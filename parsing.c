/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:11:41 by thcaquet          #+#    #+#             */
/*   Updated: 2025/09/11 22:14:54 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		chek_path(char *line, int len, t_data *data)
{
	char	*tmp;

	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
	{
		printf("test fd = %d : |%s", data->tex.NO, &line[3]); // asgsadghsadgsahjdashjdsahjdashjdsayhjdsajhd
		if (data->tex.NO == 0)
		{
			tmp = ft_strndup(&line[3], len - 4);
			data->tex.NO = open(tmp, O_RDONLY);
			free(tmp);
			printf("test fd = %d\n", data->tex.NO); // asgsadghsadgsahjdashjdsahjdashjdsayhjdsajhd
		}
		else
			tool_exit(1, "NO : " ERROR_MULTI_PATH, data, line);
		if (data->tex.NO < 1)
			tool_exit(1, "NO : " ERROR_PATH, data, line);
	}
	(void) line;
	(void) len;
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
		printf("%s->%d\n", line, len);
		if (len > 4)
			toogle = chek_path(line, len, data);
		else if (len > 1)
			tool_exit(1, ERROR_LOAD, data, line);
		free(line);
	}
	(void) data;
}

void	parsing(const char *path, t_data *data)
{

	int	len;
	int	fd;

	len = ft_strlen(path);
	if (len < 5 || ft_strcmp((char *) &path[len - 4], ".cub") != 0)
		tool_exit(1, "1: " ERROR_PATH_MAP, 0, 0);
	fd = open(path, O_RDONLY);
	if (fd > 1024 || fd < 1)
		tool_exit(1, "2: " ERROR_PATH_MAP, 0, 0);
	set_data(data);
	search_path(fd, data);
	//search_map(path, &fd, data);
	close(fd);
	(void) data;
}