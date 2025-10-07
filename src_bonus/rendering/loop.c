/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaineko <jaineko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:04:17 by emrocher          #+#    #+#             */
/*   Updated: 2025/10/07 03:20:13 by jaineko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	print_fps(t_data *data)
{
	struct timeval	tv;
	static long		tim_us;
	t_pointi		i;

	gettimeofday(&tv, NULL);
	i.y = -1;
	while (++i.y < 10)
	{
		i.x = -1;
		while (++i.x < 13)
			data->buf[i.y * WIDTH + WIDTH - 231 + i.x] = 0;
	}
	mlx_string_put(data->mlx, data->win, WIDTH - 230, 10, -1, ft_itoa(-S / (tim_us - tv.tv_usec)));
	tim_us = tv.tv_usec;
}

int	game_loop(void *arg)
{
	t_data		*data;

	data = (t_data *)arg;
	key_hook(data);
	draw_wall(data);
	if (data->t_key.map)
	{
		draw_map(data);
		draw_player(data);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	if (data->t_key.map)
		print_fps(data);
	return (0);
}
