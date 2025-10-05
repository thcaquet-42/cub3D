/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaineko <jaineko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:04:08 by emrocher          #+#    #+#             */
/*   Updated: 2025/10/05 17:21:15 by jaineko          ###   ########.fr       */
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
			data->buf[i.y * WIDTH + i.x] = dda->tex->buf[dda->tex_y * dda->tex->width + dda->tex_x];
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
	plane.y =  data->plr.dir.x * FOV;
	i.x = -1;
	while (++i.x < WIDTH)
	{
		dda_alg(data, &dda, plane, i.x);
		dda_choose_tex(data, &dda);
		if (dda.side == 0)
			dda.wall_x = data->plr.pos.y + dda.wall_dist * dda.ray_dir.y;
		else
			dda.wall_x = data->plr.pos.x + dda.wall_dist * dda.ray_dir.x;
		dda.tex_x = (int)((dda.wall_x -=floor(dda.wall_x)) * (double)dda.tex->width);
		if (dda.tex_x >= dda.tex->width)
			dda.tex_x = dda.tex->width - 1;
		if ((dda.side == 0 && dda.ray_dir.x > 0) || (dda.side == 1 && dda.ray_dir.y < 0))
			dda.tex_x = dda.tex->width - dda.tex_x - 1;
		if (dda.line_height <= 0)
			dda.line_height = 1;
		dda.tex_step = (double)dda.tex->height / (double)dda.line_height;
		draw_tex(data, &dda, i);
	}
}

void	draw_map(t_data *data)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (y < MAP_Y)
	{
		x = 0;
		while (x < MAP_X)
		{
			if (data->map[y * data->lst_map.y / MAP_Y][x * data->lst_map.x / MAP_X] == '1')
				data->buf[(y) * WIDTH + (WIDTH - MAP_X + x)] = tool_rgba(10, 10, 10, 255);
			else if(check_is_walkable(data->map[y * data->lst_map.y / MAP_Y][x * data->lst_map.x / MAP_X])) 
				data->buf[(y) * WIDTH + (WIDTH - MAP_X + x)] = tool_negative(&data->rgb[C]);
			x++;
		}
	y++;
	}
}

void	draw_vec(t_data *data, double teta, uint32_t color)
{
	unsigned long int	x;
	unsigned long int	y;
	uint32_t	ox;
	uint32_t	oy;
	int			i;

	oy = (uint32_t) (data->plr.pos.y * MAP_Y / data->lst_map.y);
	ox = (uint32_t) (data->plr.pos.x * MAP_X / data->lst_map.x);
	i = 0;
	x = ox;
	y = oy;
	while (++i && (y) * WIDTH + (WIDTH - MAP_X + x) > 0)
	{
		if (x >= MAP_X || y >= MAP_Y || \
			(data->buf[(y) * WIDTH + (WIDTH - MAP_X + x)] != tool_negative(&data->rgb[C]) \
			&& (data->buf[(y) * WIDTH + (WIDTH - MAP_X + x)] != color)))
		{
			data->buf[(y) * WIDTH + (WIDTH - MAP_X + x)] =  tool_rgba(0, 255, 0, 255);
			break;
		}
		data->buf[(y) * WIDTH + (WIDTH - MAP_X + x)] = color;
		x = ox + round(i * cos(teta));
		y = oy + round(i * sin(teta));
	}
}

void	draw_player(t_data *data)
{
	int	x;
	int	y;
	int	cx;
	int	cy;
	int	i;

	i = -12;
	while (++i <= 11)
		draw_vec(data, data->plr.teta - PI42 * i, tool_gray(&data->rgb[C]));
	cy = (uint32_t) (data->plr.pos.y * MAP_Y / data->lst_map.y);
	cx = (uint32_t) (data->plr.pos.x * MAP_X / data->lst_map.x);
	y = -3;
	while (y <= 3)
	{
		x = -3;
		while (x <= 3)
		{
			if ((y + cy) * WIDTH +  (WIDTH - MAP_X + cx + x) > 0)
				data->buf[(y + cy) * WIDTH +  (WIDTH - MAP_X + cx + x)] = tool_rgba(255, 10, 10, 255);
			++x;
		}
		++y;
	}
}
