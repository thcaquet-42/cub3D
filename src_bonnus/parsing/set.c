/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:26:48 by thcaquet          #+#    #+#             */
/*   Updated: 2025/10/06 17:15:51 by thcaquet         ###   ########.fr       */
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
	data->map = 0;
	data->scrn_x = WIDTH;
	data->scrn_y = HEIGHT;
	data->lst_map = lst_set();
}
