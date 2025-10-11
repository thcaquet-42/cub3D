/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaineko <jaineko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:04:17 by emrocher          #+#    #+#             */
/*   Updated: 2025/10/10 16:18:59 by jaineko          ###   ########.fr       */
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

int	game_loop(void *arg)
{
	t_data		*data;

	data = (t_data *)arg;
	key_hook(data);
	draw_wall(data);
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
