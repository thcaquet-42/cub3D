/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaineko <jaineko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 20:09:54 by thcaquet          #+#    #+#             */
/*   Updated: 2025/10/09 03:40:24 by jaineko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	loop_check_case_map(char *line, size_t *i, t_data *data)
{
	size_t	n;

	n = 0;
	while (line[*i])
	{
		if (!check_case_map(line[*i]))
			clear_exit(1, "(3)" ERROR_MAP, data, line);
		if (line[*i] == '\n')
			line[*i] = 0;
		if (line[*i] != ' ' && line[*i] != 0)
			n = *i + 1;
		++*i;
	}
	lst_add_back(&data->lst_map, line, n);
	return ;
}

void	search_map(t_data *data, char *line)
{
	size_t		i;

	while (1)
	{
		i = 0;
		if (line == 0)
			break ;
		if (line[0] == '\n')
			clear_exit(1, "(1)" ERROR_MAP, data, line);
		while (line[i] == ' ')
			++i;
		if (data->lst_map.min > i)
			data->lst_map.min = i;
		if (line[i] == '\n')
			clear_exit(1, "(2)" ERROR_MAP, data, line);
		loop_check_case_map(line, &i, data);
		free(line);
		line = get_next_line(data->fd);
	}
}

void	look_neighbor(t_data *data, int x, int y)
{
	if (x - 1 < 0 || check_is_void(data->map[y][x - 1]))
		clear_exit(1, "(6)" ERROR_MAP, data, 0);
	if (x + 1 > (int) data->lst_map.x - 1 || check_is_void(data->map[y][x + 1]))
		clear_exit(1, "(7)" ERROR_MAP, data, 0);
	if (y - 1 < 0 || check_is_void(data->map[y - 1][x]))
		clear_exit(1, "(8)" ERROR_MAP, data, 0);
	if (y + 1 > (int) data->lst_map.y - 1 || check_is_void(data->map[y + 1][x]))
		clear_exit(1, "(9)" ERROR_MAP, data, 0);
}

void	pars_map(t_data *data)
{
	int	x;
	int	y;
	int	spawn;

	y = -1;
	spawn = 0;
	while (++y < (int) data->lst_map.y)
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (check_is_edge(data->map[y][x]))
				look_neighbor(data, x, y);
			if (check_is_spawn(data->map[y][x]))
				++spawn;
			if (spawn > 1)
				clear_exit(1, "(4)" ERROR_MAP, data, 0);
		}
	}
	if (spawn != 1)
		clear_exit(1, "(5)" ERROR_MAP, data, 0);
}
