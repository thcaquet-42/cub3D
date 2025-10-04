/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaineko <jaineko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:04:08 by emrocher          #+#    #+#             */
/*   Updated: 2025/10/04 17:58:11 by jaineko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void draw_wall(t_data *data)
{
    t_pointi i;
    t_point plane;
    t_dda dda;

    plane.x = -data->plr.dir.y * FOV;
    plane.y =  data->plr.dir.x * FOV;
	i.x = -1;
	while (++i.x < WIDTH)
	{
		dda_alg(data, &dda, plane, i.x);
		i.y = -1;
		while (++i.y < HEIGHT)
		{
			if (i.y >= dda.start && i.y <= dda.end)
				data->buf[(i.y) * WIDTH + (i.x)] =  tool_rgba(50, 50, 200, 255);
			else
				data->buf[(i.y) * WIDTH + (i.x)] =  tool_rgba(200, 50, 50, 255);
		}
	}
}


void	draw_map(t_data *data)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (y < MAP_Y)
	{
		x = 0;
		while (x < MAP_X)
		{
			if (data->map[y * data->lst_map.y / MAP_Y][x * data->lst_map.x / MAP_X] == '1')
				data->buf[(y) * WIDTH + (WIDTH - MAP_X + x)] = tool_rgba(10, 10, 10, 255);
			else if(check_is_walkable(data->map[y * data->lst_map.y / MAP_Y][x * data->lst_map.x / MAP_X])) 
				data->buf[(y) * WIDTH + (WIDTH - MAP_X + x)] =  tool_rgba(50, 50, 100, 255);
			x++;
		}
	y++;
	}
}

void	draw_vec(t_data *data, double teta, uint32_t color)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	ox;
	uint32_t	oy;
	int			i;

	oy = (uint32_t) (data->plr.pos.y * MAP_Y / data->lst_map.y);
	ox = (uint32_t) (data->plr.pos.x * MAP_X / data->lst_map.x);
	i = 0;
	x = ox;
	y = oy;
	while (x < MAP_X && y < MAP_Y)
	{
		data->buf[(y) * WIDTH + (WIDTH - MAP_X + x)] = color;
		x = ox + round(i * cos(teta));
		y = oy + round(i * sin(teta));
		if (!check_is_walkable(data->map[y * data->lst_map.y / MAP_Y][x * data->lst_map.x / MAP_X]))
		{
			data->buf[(y) * WIDTH + (WIDTH - MAP_X + x)] =  tool_rgba(0, 255, 0, 255);
			break;
		}
		++i;
	}
}

void	draw_player(t_data *data)
{
	int	x;
	int	y;
	int	cx;
	int	cy;
	int	i;

	i = -8;
	while (++i <= 8)
		draw_vec(data, data->plr.teta - PI32 * i, tool_rgba(100, 100, 100, 255));
	cy = (uint32_t) (data->plr.pos.y * MAP_Y / data->lst_map.y);
	cx = (uint32_t) (data->plr.pos.x * MAP_X / data->lst_map.x);
	y = -3;
	while (y <= 3)
	{
		x = -3;
		while (x <= 3)
		{
			data->buf[(y + cy) * WIDTH +  (WIDTH - MAP_X + cx + x)] = tool_rgba(255, 10, 10, 255);
			++x;
		}
		++y;
	}
}
