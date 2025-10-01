/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrocher <emrocher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:26:48 by thcaquet          #+#    #+#             */
/*   Updated: 2025/10/01 17:26:47 by emrocher         ###   ########.fr       */
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

	data->scrn_x = 1920;
	data->scrn_y = 1080;

	data->lst_map = lst_set();
}