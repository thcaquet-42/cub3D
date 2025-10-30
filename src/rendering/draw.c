/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:04:08 by emrocher          #+#    #+#             */
/*   Updated: 2025/10/23 14:51:08 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	draw_tex(t_data *data, t_dda *dda, t_pointi i)
{
	dda->tex_pos = ((double)dda->start - (double)HEIGHT / 2.0 + \
(double)dda->line_height / 2.0) * dda->tex_step;
	i.y = -1;
	while (++i.y < HEIGHT)
	{
		if (i.y < dda->start)
			data->buf[i.y * WIDTH + i.x] = \
tool_rgba(data->rgb[C].r, data->rgb[C].g, data->rgb[C].b, 255);
		else if (i.y <= dda->end)
		{
			dda->tex_y = (int)dda->tex_pos;
			if (dda->tex_y < 0)
				dda->tex_y = 0;
			if (dda->tex_y >= dda->tex->height)
				dda->tex_y = dda->tex->height - 1;
			data->buf[i.y * WIDTH + i.x] = \
dda->tex->buf[dda->tex_y * dda->tex->width + (dda->tex->width - dda->tex_x -1)];
			dda->tex_pos += dda->tex_step;
		}
		else
			data->buf[i.y * WIDTH + i.x] = \
tool_rgba(data->rgb[F].r, data->rgb[F].g, data->rgb[F].b, 255);
	}
}

void	draw_wall(t_data *data)
{
	t_pointi	i;
	t_point		plane;
	t_dda		dda;

	plane.x = -data->plr.dir.y * FOV;
	plane.y = data->plr.dir.x * FOV;
	i.x = -1;
	while (++i.x < WIDTH)
	{
		dda_alg(data, &dda, plane, i.x);
		check_dda_tex(data, &dda);
		if (dda.side == 0)
			dda.wall_x = data->plr.pos.y + dda.wall_dist * dda.ray_dir.y;
		else
			dda.wall_x = data->plr.pos.x + dda.wall_dist * dda.ray_dir.x;
		dda.tex_x = (int)((dda.wall_x - floor(dda.wall_x)) * dda.tex->width);
		if (dda.tex_x >= dda.tex->width)
			dda.tex_x = dda.tex->width - 1;
		if ((!dda.side && dda.ray_dir.x > 0) || (dda.side && dda.ray_dir.y < 0))
			dda.tex_x = dda.tex->width - dda.tex_x - 1;
		if (dda.line_height <= 0)
			dda.line_height = 1;
		dda.tex_step = (double)dda.tex->height / (double)dda.line_height;
		draw_tex(data, &dda, i);
	}
}
