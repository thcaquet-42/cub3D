/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:04:17 by emrocher          #+#    #+#             */
/*   Updated: 2025/10/23 15:05:52 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	print_fps(t_data *data)
{
	struct timeval	tv;
	static long		tim_us;
	t_pointi		i;
	char			*fps;
	int				len;

	gettimeofday(&tv, NULL);
	i.y = -1;
	fps = ft_itoa(-S / (tim_us - tv.tv_usec));
	if (fps)
	{
		len = (int)strlen(fps);
		while (++i.y < 12)
		{
			i.x = -2;
			while (++i.x < 7 * len)
				data->buf[i.y * WIDTH + WIDTH - 231 + i.x] = 0;
		}
		mlx_string_put(data->mlx, data->win, WIDTH - 230, 10, -1, fps);
		free(fps);
	}
	tim_us = tv.tv_usec;
}

void	loop_door(t_data *data)
{
	t_pointi		max;
	t_pointi		i;
	int				tick;

	max.x = data->lst_map.x;
	max.y = data->lst_map.y;
	i.y = -1;
	tick = tool_tick(1);
	while (tick && ++i.y < max.y)
	{
		i.x = 0;
		while (++i.x < max.x)
		{
			if (tick && data->map[0][i.y][i.x] == \
'D' && data->map[1][i.y][i.x] < 144)
				data->map[1][i.y][i.x] += 8;
			if (tick && data->map[0][i.y][i.x] == \
'C' && data->map[1][i.y][i.x] > 0)
				data->map[1][i.y][i.x] -= 8;
		}
	}
}

int	game_loop(void *arg)
{
	t_data		*data;

	data = (t_data *)arg;
	key_hook(data);
	draw_wall(data);
	loop_door(data);
	if (data->t_key.map)
	{
		draw_compass(data);
		draw_map(data);
		draw_player(data);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	print_fps(data);
	return (0);
}
