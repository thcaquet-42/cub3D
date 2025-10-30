/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:26:48 by thcaquet          #+#    #+#             */
/*   Updated: 2025/10/23 14:43:50 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	set_data(t_data *data)
{
	data->tex[EA].img = 0;
	data->tex[NO].img = 0;
	data->tex[SO].img = 0;
	data->tex[WE].img = 0;
	data->rgb[F].r = -1;
	data->rgb[C].r = -1;
	data->scrn_x = WIDTH;
	data->scrn_y = HEIGHT;
	data->lst_map = lst_set();
}

void	set_map(t_data *data)
{
	size_t	i;
	t_lst	*node;

	i = -1;
	node = data->lst_map.start;
	while (++i < data->lst_map.y)
	{
		data->map[0][i] = (unsigned char *) ft_strndup(node->str + \
data->lst_map.min, data->lst_map.x - data->lst_map.min);
		if (!data->map[0][i])
			clear_exit(1, "(3)" ERROR_MALLOC, data, 0);
		data->map[1][i] = (unsigned char *) ft_strndup(node->str + \
data->lst_map.min, data->lst_map.x - data->lst_map.min);
		if (!data->map[1][i])
			clear_exit(1, "(4)" ERROR_MALLOC, data, 0);
		node = node->next;
	}
	data->map[0][i] = 0;
	data->map[1][i] = 0;
}
