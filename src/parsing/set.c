/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:26:48 by thcaquet          #+#    #+#             */
/*   Updated: 2025/09/15 19:56:03 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	set_data(t_data *data)
{
	data->tex[EA] = 0;
	data->tex[NO] = 0;
	data->tex[SO] = 0;
	data->tex[WE] = 0;
	data->rgb[F].r = -1;
	data->rgb[C].r = -1;
	data->map = 0;

	data->lst_map = lst_set();
}