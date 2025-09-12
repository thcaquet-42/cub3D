/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:11:41 by thcaquet          #+#    #+#             */
/*   Updated: 2025/09/12 22:13:44 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		chek_path(char *line, int len, t_data *data)
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

void	search_path(int fd, t_data *data)
{
	char	*line;
	int		toogle;
	int		len;

	toogle = TRUE;
	while (toogle)
	{
		line = get_next_line(fd);
		len = ft_strlen(line);
		printf("%s->%d\n", line, len); // tmp
		if (len > 3)
			toogle = chek_path(line, len, data);
		else if (len > 1)
			tool_exit(1, ERROR_LOAD, data, line);
		free(line);
	}
	(void) data;
}

void	search_map(t_tail *tail, int fd,t_data *data)
{
	char		*line;
	size_t		i;
	size_t		n;

	while (1)
	{
		i = -1;
		n = 0;
		line = get_next_line(fd);
		if (line == 0)
			break;
		while (line[++i])
		{
			if (check_case_map(line[i]))
				tool_exit(1, ERROR_MAP, data, line);
			if (line[i] != ' ')
				n = i;
		}
		lst_add_back(tail, line);
		if (n > tail->x)
			tail->x = n;
		printf("%s->%zu\n x=%zu, y=%zu\n", line, i, tail->x, tail->y); // tmp
		free(line);
	}
}

void	parsing(const char *path, t_data *data)
{

	int		len;
	int		fd;
	t_tail	tail;

	tail = lst_set();
	len = ft_strlen(path);
	if (len < 5 || ft_strcmp((char *) &path[len - 4], ".cub") != 0)
		tool_exit(1, "1: " ERROR_PATH_MAP, 0, 0);
	fd = open(path, O_RDONLY);
	if (fd > 1024 || fd < 1)
		tool_exit(1, "2: " ERROR_PATH_MAP, 0, 0);
	set_data(data);
	search_path(fd, data);
	search_map(&tail, fd, data);
	close(fd);
	(void) data;
}
