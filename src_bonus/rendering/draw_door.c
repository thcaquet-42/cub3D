/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaineko <jaineko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 05:11:24 by jaineko           #+#    #+#             */
/*   Updated: 2025/10/11 04:21:06 by jaineko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_draw_tex	init_draw_tex_door(t_door *door)
{
	t_draw_tex	draw;

	draw = (t_draw_tex) {0};
	draw.start = door->start;
	draw.end = door->end;
	if (draw.end > HEIGHT - 1)
		draw.end = HEIGHT - 1;
	draw.tex_y = door->tex_y;
	draw.tex_x = door->tex_x;
	draw.tex_w = door->tex->width;
	draw.tex_h = door->tex->height;
	draw.dst = (draw.tex_w - door->tex_x -1);
	
	return (draw);
}

void	draw_tex_door(t_data *data, t_door *door, t_pointi i, const float tex_step)
{
	t_draw_tex	draw;
	int			offset;
	int			tex_x;
	
	draw = init_draw_tex_door(door);
	offset = ((float)data->map[1][door->map.y][door->map.x] / 250.0f) * draw.tex_w;
	draw.tex_pos = (draw.start - HEIGHT / 2.0 + door->line_height / 2.0) * tex_step;
	while (draw.start < draw.end)
	{
		draw.tex_y = (int)draw.tex_pos;
		if (draw.tex_y >= draw.tex_h)
			break;
		if (draw.dst <= draw.tex_w / 2)
			tex_x = draw.dst + offset / 2;
		else
			tex_x = draw.dst - offset / 2;
		if (!(draw.tex_x < draw.dst + offset && draw.tex_x > draw.dst - offset) &&
		(draw.tex_y > 0) && (door->tex->buf[tex_x + draw.tex_y * draw.tex_w] != 0))
			data->buf[draw.start * WIDTH + i.x] = door->tex->buf[tex_x + draw.tex_y * draw.tex_w];
		draw.tex_pos += tex_step;
		++draw.start;
	}
}

void	draw_door(t_data *data, t_door *door, t_pointi i)
{

	// door->start += 200;
	draw_tex_door(data, door, i, (float)door->tex->height / (float)door->line_height);
}