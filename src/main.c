/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrocher <emrocher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:11:48 by thcaquet          #+#    #+#             */
/*   Updated: 2025/10/01 18:32:41 by emrocher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"



// static char	get_player_pos(t_data *data, char **map)
// {

// }

// static void	init_player(t_data *data, char **map)
// {
// }

void	init_all(t_data *data, char **av)
{
	parsing(av[1], data);
	data->lst_map.x = data->lst_map.x - data->lst_map.min;
	(void) av;
	printf("scrn_x = %d, scrn_y = %d\n", data->scrn_x, data->scrn_y); // test ==========================
	
	int	i = -1;
	while(data->map[++i])
	{
		printf("map[%d] = %s\n", i, data->map[i]);
	}
	printf("x_max = %zu, Y_max = %zu\n", data->lst_map.x, data->lst_map.y);
	printf("end\n");

	// tmp
 	data->mlx = mlx_init(data->scrn_x, data->scrn_y, "minimap", true);
	
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
