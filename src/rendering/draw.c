/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:04:08 by emrocher          #+#    #+#             */
/*   Updated: 2025/10/02 06:53:45 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

	// mlx_get_data_addr
// buffer[y * WIDTH + x] = color;

void draw_map(t_data *data)
{
	uint32_t x;
	uint32_t y;

	y = 0;
	while (y < MAP_Y)
	{
		x = 0;
		while (x < MAP_X)
		{
			if (data->map[y * data->lst_map.y / MAP_Y][x * data->lst_map.x / MAP_X] == '1')
				data->buf[(y + 5) * WIDTH +  (WIDTH - 20 - MAP_X + x)] = tool_rgba(10, 10, 10, 255);
			else if(check_is_walkable(data->map[y * data->lst_map.y / MAP_Y][x * data->lst_map.x / MAP_X])) 
				data->buf[(y + 5) * WIDTH +  (WIDTH - 20 - MAP_X + x)] =  tool_rgba(50, 50, 100, 255);
			x++;
		}
	y++;
	}
}

void draw_vec(t_data *data, double teta, uint32_t color)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	ox;
	uint32_t	oy;
	int			i;

	oy = (uint32_t) (data->player.pos.y * MAP_Y / data->lst_map.y) -3;
	ox = (uint32_t) (data->player.pos.x * MAP_X / data->lst_map.x) -3;
	i = 0;
	x = 1;
	y = 1;
	while (x < MAP_X - 1 && y < MAP_Y - 1 && x > 0 && y > 0)
	{
		data->buf[(y + 5) * WIDTH +  (WIDTH - 20 - MAP_X + x)] = color;
		if (x % (MAP_X / data->lst_map.x) == 0 || y % (MAP_Y / data->lst_map.y) == 0)
			data->buf[(y + 5) * WIDTH +  (WIDTH - 20 - MAP_X + x)] =  tool_rgba(0, 255, 0, 255);
		++i;
		x = ox + round(i * cos(teta));
		y = oy + round(i * sin(teta));
	}
}

void draw_player(t_data *data)
{
	uint32_t x;
	uint32_t y;
	uint32_t cx;
	uint32_t cy;
	int	i;

	i = -10;
	while (++i <= 10)
		draw_vec(data, data->player.dir - PI32 * i, tool_rgba(100, 100, 100, 255));
	y = (uint32_t) (data->player.pos.y * MAP_Y / data->lst_map.y) - 6;
	cy = y + 6;
	while (y <= cy)
	{
		x = (uint32_t) (data->player.pos.x * MAP_X / data->lst_map.x) - 6;
		cx = x + 6;
		while (x <= cx)
		{
			data->buf[(y + 6) * WIDTH +  (WIDTH - 20 - MAP_X + x)] =  tool_rgba(255, 10, 10, 255);
			++x;
		}
	++y;
	}
}
