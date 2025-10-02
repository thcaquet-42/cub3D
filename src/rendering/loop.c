/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:04:17 by emrocher          #+#    #+#             */
/*   Updated: 2025/10/02 06:32:19 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int game_loop(void *arg)
{
	t_data *data;
	// int x;

	data = (t_data *)arg;
	draw_map(data);
	draw_player(data);
	// x = 0;
	// key_hooks(data);
	key_hook(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0 , 0);
	return (0);
}
