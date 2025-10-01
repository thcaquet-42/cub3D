/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrocher <emrocher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:11:48 by thcaquet          #+#    #+#             */
/*   Updated: 2025/10/01 19:07:51 by emrocher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"



void	get_player_pos(t_data *data, char **map)
{
	int i = 0;
	while(map[i])
	{
		int j = 0;
		while(map[i][j])
		{
			if(map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'E' || map[i][j] == 'S' )
			{
				data->player.pos.y = i;
				data->player.pos.x = j;
				printf("player pos : %f, %f", data->player.pos.x, data->player.pos.y);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_player(t_data *data, char **map)
{
	get_player_pos(data, map);
	
}


void	init_all(t_data *data, char **av)
{
	parsing(av[1], data);
	data->lst_map.x = data->lst_map.x - data->lst_map.min;
 	data->mlx = mlx_init(data->scrn_x, data->scrn_y, "minimap", true);
	init_player(data, data->map);
	
	data->minimap = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data->mlx, data->minimap, 10 , 10);
}


int	main(int ac, char **av)
{
	t_data data;

	if (ac != 2)
		clear_exit(1, ERROR_ARG, 0, 0);

	init_all(&data, av);
	mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_loop(data.mlx);

	// y a plus qu a ecrire le reste du code ici

	
	clear_data(&data);
}
