/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:14:30 by emrocher          #+#    #+#             */
/*   Updated: 2025/10/23 14:36:43 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	init_player_pos(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->map[0][i])
	{
		j = 0;
		while (data->map[0][i][j])
		{
			data->plr.pos.y = i + 0.5;
			data->plr.pos.x = j + 0.5;
			if (data->map[0][i][j] == 'E')
				return (0.0001 + 0);
			else if (data->map[0][i][j] == 'N')
				return (0.0001 + PI2 * 3);
			else if (data->map[0][i][j] == 'S')
				return (0.0001 + PI2);
			else if (data->map[0][i][j] == 'W')
				return (0.0001 + PI);
			j++;
		}
		i++;
	}
	return (0.001 + 0);
}

void	init_all(t_data *data, char **av)
{
	int	nul;

	data->mlx = mlx_init();
	if (data->mlx == 0)
		clear_exit(1, ERROR_MLX, 0, 0);
	parsing(av[1], data);
	data->plr.teta = init_player_pos(data);
	data->plr.dir.x = cos(data->plr.teta);
	data->plr.dir.y = sin(data->plr.teta);
	data->lst_map.x = data->lst_map.x - data->lst_map.min;
	data->win = mlx_new_window(data->mlx, data->scrn_x, data->scrn_y, "CUB3D");
	if (data->win == 0)
		clear_exit(1, ERROR_MLX, data, 0);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->img == 0)
		clear_exit(1, ERROR_MLX, data, 0);
	data->buf = (uint32_t *) mlx_get_data_addr(data->img, &nul, &nul, &nul);
	data->t_key.map = 1;
	data->t_key.mous = 1;
}

int	mouse_move_hook(int x, int y, t_data *data)
{
	if (data->t_key.mous)
	{
		if (x != WIDTH / 2)
		{
			data->plr.teta += (x - WIDTH / 2) * 0.0003;
			data->plr.dir.x = cos(data->plr.teta);
			data->plr.dir.y = sin(data->plr.teta);
			mlx_mouse_move(data->mlx, data->win, WIDTH / 2, HEIGHT / 2);
		}
	}
	(void) y;
	return (0);
}

int	close_window(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	data = (t_data){0};
	if (ac != 2)
		clear_exit(1, ERROR_ARG, 0, 0);
	init_all(&data, av);
	mlx_mouse_hide(data.mlx, data.win);
	mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, key_hook_press, &data);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, key_hook_release, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_hook(data.win, MotionNotify, PointerMotionMask, mouse_move_hook, &data);
	mlx_loop(data.mlx);
	clear_data(&data);
}
