/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaineko <jaineko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 05:11:24 by jaineko           #+#    #+#             */
/*   Updated: 2025/10/07 06:53:12 by jaineko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	draw_compass(t_data *data)
{
	t_pointi	i;
	t_pointi	r;
	double		cos_a;
	double		sin_a;

	i.y = -1;
	cos_a = cos(data->plr.teta + PI2);
	sin_a = sin(data->plr.teta + PI2);
	while (++i.y < 200)
	{
		i.x = -1;
		while (++i.x < 200)
		{
			r.x = (int)(cos_a * (i.x - 100) - sin_a * (i.y - 100) + 100);
			r.y = (int)(sin_a * (i.x - 100) + cos_a * (i.y - 100) + 100);
			if ((r.x >= 0 && r.x < 200 && r.y >= 0 && r.y < 200) && (data->tex[COMPASS].buf[r.y * 200 + r.x] != 0))
				data->buf[(i.y) * WIDTH + (WIDTH - 410 + i.x)] = data->tex[COMPASS].buf[r.y * 200 + r.x];
		}
	}
}

