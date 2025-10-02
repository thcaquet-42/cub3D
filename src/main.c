/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:14:30 by emrocher          #+#    #+#             */
/*   Updated: 2025/10/02 08:19:34 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


float	init_player_pos(t_data *data)
{
	int i = 0;
	while(data->map[i])
	{
		int j = 0;
		while(data->map[i][j])
		{
			data->player.pos.y = i + 0.5;
			data->player.pos.x = j + 0.5;
			if(data->map[i][j] == 'N')
				return (0);
			else if (data->map[i][j] == 'E')
				return (PI4);
			else if (data->map[i][j] == 'S')
				return (PI4 * 2);
			else if (data->map[i][j] == 'W')
				return (PI4 * 3);
			j++;
		}
		i++;
	}
	return (0);
}

void	init_all(t_data *data, char **av)
{
	int	nul;

	data->mlx = mlx_init();
	
	
	parsing(av[1], data);
	data->player.dir = init_player_pos(data);
	data->lst_map.x = data->lst_map.x - data->lst_map.min;
	
	data->win = mlx_new_window(data->mlx, data->scrn_x, data->scrn_y, "CUB3D");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->buf = (uint32_t *) mlx_get_data_addr(data->img, &nul, &nul, &nul);
}

#define MACRO 8
int	main(int ac, char **av)
{
	t_data data;
	
	data = (t_data){0};
	if (ac != 2)
	clear_exit(1, ERROR_ARG, 0, 0);
	
	init_all(&data, av);
	mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, key_hook_press, &data);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, key_hook_release, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);

	// y a plus qu a ecrire le reste du code ici

	
	clear_data(&data);
}
