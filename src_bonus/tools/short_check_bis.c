/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_check_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 05:16:11 by jaineko           #+#    #+#             */
/*   Updated: 2025/10/23 15:10:24 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_is_door(int c)
{
	return (c == 'C' || c == 'D');
}

int	check_is_wall(int c)
{
	return (c == '1');
}

void	check_dda_tex(t_data *data, t_dda *dda)
{
	if (dda->side == 0)
	{
		if (dda->step.x == 1)
			dda->tex = &data->tex[WE];
		else
			dda->tex = &data->tex[EA];
	}
	else
	{
		if (dda->step.y == 1)
			dda->tex = &data->tex[SO];
		else
			dda->tex = &data->tex[NO];
	}
}
