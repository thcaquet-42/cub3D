/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaineko <jaineko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:11:41 by thcaquet          #+#    #+#             */
/*   Updated: 2025/10/09 05:05:52 by jaineko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	chek_path(char *line, int len, t_data *data)
{
	if (len > 4 && line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		load_tex(line, len, data, NO);
	else if (len > 4 && line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		load_tex(line, len, data, SO);
	else if (len > 4 && line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		load_tex(line, len, data, WE);
	else if (len > 4 && line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		load_tex(line, len, data, EA);
	else if (line[0] == 'F' && line[1] == ' ')
		load_colors(line, 2, data, F);
	else if (line[0] == 'C' && line[1] == ' ')
		load_colors(line, 2, data, C);
	else
		return (FALSE);
	return (TRUE);
}

void	ensure_preloading_map(t_data *data)
{
	load_tex_bis(0, ft_strdup("src_bonus/tex/compass.xpm"), data, COMPASS);
	if (!data->tex[COMPASS].buf && data->tex[COMPASS].height == 200
		&& data->tex[COMPASS].width == 200)
		clear_exit(1, "(5)" ERROR_LOAD_TEX, data, 0);
	if (!data->tex[NO].buf)
		clear_exit(1, "(6)" ERROR_LOAD_TEX, data, 0);
	if (!data->tex[SO].buf)
		clear_exit(1, "(7)" ERROR_LOAD_TEX, data, 0);
	if (!data->tex[WE].buf)
		clear_exit(1, "(8)" ERROR_LOAD_TEX, data, 0);
	if (!data->tex[EA].buf)
		clear_exit(1, "(9)" ERROR_LOAD_TEX, data, 0);
	if (data->rgb[F].r == -1)
		clear_exit(1, "(4)" ERROR_RGB, data, 0);
	if (data->rgb[C].r == -1)
		clear_exit(1, "(4)" ERROR_RGB, data, 0);
}

void	init_map(t_data *data)
{
	data->map = malloc(sizeof(char ***) * 3);
	if (!data->map)
		clear_exit(1, "(0)" ERROR_MALLOC, data, 0);
	data->map[1] = 0;
	data->map[2] = 0;
	data->map[0] = malloc(sizeof(char **) * (data->lst_map.y + 1));
	if (!data->map[0])
		clear_exit(1, "(1)" ERROR_MALLOC, data, 0);
	data->map[1] = malloc(sizeof(char **) * (data->lst_map.y + 1));
	if (!data->map[1])
		clear_exit(1, "(2)" ERROR_MALLOC, data, 0);
	data->map[0][(data->lst_map.y)] = 0;
	data->map[1][(data->lst_map.y)] = 0;
}

void	search_path(t_data *data)
{
	char	*line;
	int		toogle;
	int		len;

	toogle = TRUE;
	while (toogle)
	{
		line = get_next_line(data->fd);
		len = ft_strlen(line);
		if (len > 3)
			toogle = chek_path(line, len, data);
		else if (len > 1)
			clear_exit(1, ERROR_LOAD, data, line);
		if (toogle)
			free(line);
	}
	ensure_preloading_map(data);
	search_map(data, line);
	data->fd = close(data->fd);
	init_map(data);
}

void	set_map(t_data *data)
{
	size_t	i;
	t_lst	*node;

	i = -1;
	node = data->lst_map.start;
	while (++i < data->lst_map.y)
	{
		data->map[0][i] = ft_strndup(node->str + \
data->lst_map.min, data->lst_map.x - data->lst_map.min);
		if (!data->map[0][i])
			clear_exit(1, "(3)" ERROR_MALLOC, data, 0);
		data->map[1][i] = ft_strndup(node->str + \
data->lst_map.min, data->lst_map.x - data->lst_map.min);
		if (!data->map[1][i])
			clear_exit(1, "(4)" ERROR_MALLOC, data, 0);
		node = node->next;
	}
	data->map[0][i] = 0;
	data->map[1][i] = 0;
}

void	parsing(const char *path, t_data *data)
{
	size_t	len;


	len = ft_strlen(path);
	if (len < 5 || ft_strcmp((char *) &path[len - 4], ".cub") != 0)
		clear_exit(1, "1: " ERROR_PATH_MAP, 0, 0);
	data->fd = open(path, O_RDONLY);
	if (data->fd < 1)
		clear_exit(1, "2: " ERROR_PATH_MAP, 0, 0);
	set_data(data);
	search_path(data);
	set_map(data);
	data->lst_map.start = clear_lst(data);
	pars_map(data);
}
