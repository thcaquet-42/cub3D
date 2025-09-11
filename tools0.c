/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:34:10 by thcaquet          #+#    #+#             */
/*   Updated: 2025/09/11 20:48:59 by thcaquet         ###   ########.fr       */
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
	// if (data->t.NO)
	// 	free(data->t.NO);
	// if (data->t.SO)
	// 	free(data->t.SO);
	// if (data->t.WE)
	// 	free(data->t.WE);
	// if (data->t.EA)
	// 	free(data->t.EA);
	if (thing)
		free(thing);
	if (data->map)
		free_tab(data->map);
	exit(nb_exit);
}
