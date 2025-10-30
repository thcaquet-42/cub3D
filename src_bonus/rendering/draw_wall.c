/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 01:59:08 by jaineko           #+#    #+#             */
/*   Updated: 2025/10/23 15:05:10 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_draw_tex	init_draw_tex(t_data *data, t_dda *dda)
{
	t_draw_tex	draw;

	draw.color.x = \
tool_rgba(data->rgb[C].r, data->rgb[C].g, data->rgb[C].b, 255);
	draw.color.y = \
tool_rgba(data->rgb[F].r, data->rgb[F].g, data->rgb[F].b, 255);
	draw.start = dda->start;
	draw.end = dda->end;
	if (draw.end > HEIGHT - 1)
		draw.end = HEIGHT - 1;
	draw.tex_y = dda->tex_y;
	draw.tex_w = dda->tex->width;
	draw.tex_h = dda->tex->height;
	draw.dst = (draw.tex_w - dda->tex_x -1);
	return (draw);
}

void	draw_tex(t_data *data, t_dda *dda, t_pointi i, const float tex_step)
{
	t_draw_tex	draw;

	draw = init_draw_tex(data, dda);
	draw.tex_pos = (draw.start - HEIGHT / 2.0 + dda->line_height / 2.0) \
* tex_step;
	i.y = -1;
	while (++i.y < draw.start)
		data->buf[i.y * WIDTH + i.x] = draw.color.x;
	while (i.y < draw.end)
	{
		draw.tex_y = (int)draw.tex_pos;
		if (draw.tex_y >= draw.tex_h)
			break ;
		if (draw.tex_y > 0)
			data->buf[i.y * WIDTH + i.x] = \
dda->tex->buf[draw.dst + draw.tex_y * draw.tex_w];
		draw.tex_pos += tex_step;
		++i.y;
	}
	i.y -= 1;
	while (++i.y < HEIGHT - 1)
		data->buf[i.y * WIDTH + i.x] = draw.color.y;
	if (dda->door.is)
		draw_door(data, &dda->door, i);
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
		draw_tex(data, &dda, i, (float)dda.tex->height / (float)dda.line_height)\
;
	}
}
