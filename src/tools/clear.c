/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:06:15 by thcaquet          #+#    #+#             */
/*   Updated: 2025/09/15 21:44:05 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

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

t_lst	*clear_lst(t_data *data)
{
	t_lst *node;
	t_lst *tmp;


	if (!data->lst_map.start)
		return (0);
	tmp = data->lst_map.start;
	while (tmp)
	{
		node = tmp;
		tmp = tmp->next;
		free(node->str);
		free(node);
	}
	return (0);
}

void	clear_data(t_data *data)
{
	if (!data)
		return;
	
	clear_lst(data);
	if (data->tex[NO])
		mlx_delete_texture(data->tex[NO]);
	if (data->tex[SO])
		mlx_delete_texture(data->tex[SO]);
	if (data->tex[WE])
		mlx_delete_texture(data->tex[WE]);
	if (data->tex[EA])
		mlx_delete_texture(data->tex[EA]);
	if (data->fd > 0)
		close(data->fd);
	if (data->map)
		free_tab(data->map);
	
}

void	clear_exit(int nb_exit, char *str, t_data *data, void *thing)
{
	ft_putstr_fd(str, 2);
	
	if (thing)
		free(thing);
	if (!data)
		exit(nb_exit);
	clear_data(data);
	exit(nb_exit);
}
