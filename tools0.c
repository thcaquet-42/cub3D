/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:34:10 by thcaquet          #+#    #+#             */
/*   Updated: 2025/09/12 20:58:11 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_tab(char **tab)
{
	int i;

	if (!tab)
		return;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	tool_exit(int nb_exit, char *str, t_data *data, void *thing)
{
	ft_putstr_fd(str, 2);

	if (!data)
		exit(nb_exit);

	printf("F -> %d, %d, %d\n", data->rgb[F].r, data->rgb[F].g, data->rgb[F].b); // tmp
	printf("C -> %d, %d, %d\n", data->rgb[C].r, data->rgb[C].g, data->rgb[C].b); // tmp
	
	if (data->tex[NO])
		mlx_delete_texture(data->tex[NO]);
	if (data->tex[SO])
		mlx_delete_texture(data->tex[SO]);
	if (data->tex[WE])
		mlx_delete_texture(data->tex[WE]);
	if (data->tex[EA])
		mlx_delete_texture(data->tex[EA]);
	if (thing)
		free(thing);
	if (data->map)
		free_tab(data->map);
	exit(nb_exit);
}

uint32_t	tool_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

