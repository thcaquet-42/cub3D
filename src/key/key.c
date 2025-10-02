/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:51:03 by thcaquet          #+#    #+#             */
/*   Updated: 2025/10/02 08:16:50 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int close_window(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}


void	check_edge(t_data *data, double in_x, double in_y)
{
	double nin_x;
	double nin_y;

	nin_x = in_x + data->player.pos.x;
	nin_y = in_y + data->player.pos.y;
	
	if (check_is_walkable(data->map[(int) floor(data->player.pos.y)][(int) floor(nin_x)]))
		data->player.pos.x = nin_x;
	if (check_is_walkable(data->map[(int) floor(nin_y)][(int) floor(data->player.pos.x)]))
		data->player.pos.y = nin_y;
}

void	key_hook(t_data *data)
{
	if (data->keys & BKEY_W)
		check_edge(data, 0.01 * cos(data->player.dir), 0.01 * sin(data->player.dir));
	if (data->keys & BKEY_S)
		check_edge(data, -0.01 * cos(data->player.dir), -0.01 * sin(data->player.dir));
	if (data->keys & BKEY_A)
		check_edge(data, 0.01 * sin(data->player.dir), 0.01 * cos(data->player.dir));
	if (data->keys & BKEY_D)
		check_edge(data, -0.01 * sin(data->player.dir), -0.01 * cos(data->player.dir));
	if (data->keys & BKEY_LEFT)
		data->player.dir += 0.008;
	if (data->keys & BKEY_RIGHT)
		data->player.dir -= 0.008;
}

int	key_hook_press(int key, void *v_data)
{
	t_data			*data;
	
	data = v_data;
	if (key == KEY_ESC)
		close_window(data);
	if (key == KEY_W)
		data->keys = data->keys | BKEY_W;
	if (key == KEY_S)
		data->keys = data->keys | BKEY_S;
	if (key == KEY_A)
		data->keys = data->keys | BKEY_A;
	if (key == KEY_D)
		data->keys = data->keys | BKEY_D;
	if (key == KEY_LEFT)
		data->keys = data->keys | BKEY_LEFT;
	if (key == KEY_RIGHT)
		data->keys = data->keys | BKEY_RIGHT;
	return (0);
}

int	key_hook_release(int key, void *v_data)
{
	t_data			*data;
	
	data = v_data;
	if (key == KEY_W)
		data->keys = data->keys & ~BKEY_W;
	if (key == KEY_S)
		data->keys = data->keys & ~BKEY_S;
	if (key == KEY_A)
		data->keys = data->keys & ~BKEY_A;
	if (key == KEY_D)
		data->keys = data->keys & ~BKEY_D;
	if (key == KEY_LEFT)
		data->keys = data->keys & ~BKEY_LEFT;
	if (key == KEY_RIGHT)
		data->keys = data->keys & ~BKEY_RIGHT;
	return (0);
}
