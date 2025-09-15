/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 19:11:48 by thcaquet          #+#    #+#             */
/*   Updated: 2025/09/15 21:45:30 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_data data;

	if (ac != 2)
		clear_exit(1, ERROR_ARG, 0, 0);
	parsing(av[1], &data);


	// y a plus qu a ecrire le reste du code ici
	

	
	clear_data(&data);
}
