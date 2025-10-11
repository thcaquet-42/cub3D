/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaineko <jaineko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:51:03 by thcaquet          #+#    #+#             */
/*   Updated: 2025/10/11 04:31:10 by jaineko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_edge(t_data *data, float in_x, float in_y)
{
	float	nin_x;
	float	nin_y;

	nin_x = in_x + data->plr.pos.x;
	nin_y = in_y + data->plr.pos.y;
	if (check_is_walkable(data->map[0][(int) floor(data->plr.pos.y)]\
[(int) floor(nin_x)]))
		data->plr.pos.x = nin_x;
	if (check_is_walkable(data->map[0][(int) floor(nin_y)][(int)\
floor(data->plr.pos.x)]))
		data->plr.pos.y = nin_y;
}

void	key_hook(t_data *data)
{
	int	bool;

	bool = tool_tick(1);
	if (bool && data->keys & BKEY_W)
		check_edge(data, 0.05 * cos(data->plr.teta), 0.05 * sin(data->plr.teta));
	if (bool && data->keys & BKEY_S)
		check_edge(data, -0.05 * cos(data->plr.teta), -0.05 * sin(data->plr.teta));
	if (bool && data->keys & BKEY_A)
		check_edge(data, 0.05 * sin(data->plr.teta), -0.05 * cos(data->plr.teta));
	if (bool && data->keys & BKEY_D)
		check_edge(data, -0.05 * sin(data->plr.teta), 0.05 * cos(data->plr.teta));
	if (bool && data->keys & BKEY_LEFT)
	{
		data->plr.teta -= 0.08;
		data->plr.dir.x = cos(data->plr.teta);
		data->plr.dir.y = sin(data->plr.teta);
	}
	if (bool && data->keys & BKEY_RIGHT)
	{
		data->plr.teta += 0.08;
		data->plr.dir.x = cos(data->plr.teta);
		data->plr.dir.y = sin(data->plr.teta);
	}
}

void	key_hook_press_bis(int key, t_data *data)
{
	if (key == 'f')
	{
		if (++data->t_key.mous)
			mlx_mouse_hide(data->mlx, data->win);
		else
			mlx_mouse_show(data->mlx, data->win);
	}
}

int	key_hook_press(int key, void *v_data)
{
	t_data	*data;

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
	if (key == 'e')
		data->t_key.door = 1;
	if (key == XK_Left)
		data->keys = data->keys | BKEY_LEFT;
	if (key == XK_Right)
		data->keys = data->keys | BKEY_RIGHT;
	if (key == XK_Tab)
		++data->t_key.map;
	key_hook_press_bis(key, data);
	return (0);
}

int	key_hook_release(int key, void *v_data)
{
	t_data	*data;

	data = v_data;
	if (key == 'w')
		data->keys = data->keys & ~BKEY_W;
	if (key == 's')
		data->keys = data->keys & ~BKEY_S;
	if (key == 'a')
		data->keys = data->keys & ~BKEY_A;
	if (key == 'd')
		data->keys = data->keys & ~BKEY_D;
	if (key == 'e')
		data->t_key.door = 0;
	if (key == XK_Left)
		data->keys = data->keys & ~BKEY_LEFT;
	if (key == XK_Right)
		data->keys = data->keys & ~BKEY_RIGHT;

	return (0);
}
