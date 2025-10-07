/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaineko <jaineko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:51:03 by thcaquet          #+#    #+#             */
/*   Updated: 2025/10/07 01:57:05 by jaineko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	close_window(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

void	check_edge(t_data *data, double in_x, double in_y)
{
	double	nin_x;
	double	nin_y;

	nin_x = in_x + data->plr.pos.x;
	nin_y = in_y + data->plr.pos.y;
	if ((int) floor(nin_x) < (int) data->lst_map.x - 1 && floor(nin_x) > 0)
		data->plr.pos.x = nin_x;
	if ((int) floor(nin_y) < (int) data->lst_map.y - 1 && floor(nin_y) > 0)
		data->plr.pos.y = nin_y;
}

void	key_hook(t_data *data)
{
	if (data->keys & BKEY_W)
		check_edge(data, 0.1 * cos(data->plr.teta), 0.1 * sin(data->plr.teta));
	if (data->keys & BKEY_S)
		check_edge(data, -.1 * cos(data->plr.teta), -0.1 * sin(data->plr.teta));
	if (data->keys & BKEY_A)
		check_edge(data, 0.1 * sin(data->plr.teta), -0.1 * cos(data->plr.teta));
	if (data->keys & BKEY_D)
		check_edge(data, -0.1 * sin(data->plr.teta), 0.1 * cos(data->plr.teta));
	if (data->keys & BKEY_LEFT)
	{
		data->plr.teta -= 0.08;
		data->plr.dir.x = cos(data->plr.teta);
		data->plr.dir.y = sin(data->plr.teta);
	}
	if (data->keys & BKEY_RIGHT)
	{
		data->plr.teta += 0.08;
		data->plr.dir.x = cos(data->plr.teta);
		data->plr.dir.y = sin(data->plr.teta);
	}
}

int	key_hook_press(int key, void *v_data)
{
	t_data			*data;

	data = v_data;
	if (key == XK_Escape)
		close_window(data);
	if (key == 'w')
		data->keys = data->keys | BKEY_W;
	if (key == 's')
		data->keys = data->keys | BKEY_S;
	if (key == 'a')
		data->keys = data->keys | BKEY_A;
	if (key == 'd')
		data->keys = data->keys | BKEY_D;
	if (key == XK_Left)
		data->keys = data->keys | BKEY_LEFT;
	if (key == XK_Right)
		data->keys = data->keys | BKEY_RIGHT;
	return (0);
}

int	key_hook_release(int key, void *v_data)
{
	t_data			*data;

	data = v_data;
	if (key == 'w')
		data->keys = data->keys & ~BKEY_W;
	if (key == 's')
		data->keys = data->keys & ~BKEY_S;
	if (key == 'a')
		data->keys = data->keys & ~BKEY_A;
	if (key == 'd')
		data->keys = data->keys & ~BKEY_D;
	if (key == XK_Left)
		data->keys = data->keys & ~BKEY_LEFT;
	if (key == XK_Right)
		data->keys = data->keys & ~BKEY_RIGHT;
	return (0);
}
