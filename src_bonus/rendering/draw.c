/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:04:08 by emrocher          #+#    #+#             */
/*   Updated: 2025/10/11 21:00:39 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	draw_compass(t_data *data)
{
	t_pointi	i;
	t_pointi	r;
	float		cos_a;
	float		sin_a;

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

void	draw_map(t_data *data)
{
	t_pointu	i;
	uint32_t	i_map;
	uint32_t	color;
	size_t		s_x;
	size_t		s_y;

	i_map = (WIDTH - MAP_X);
	i.y = 0;
	s_x = data->lst_map.x;
	s_y = data->lst_map.y;
	color = tool_rev(&data->rgb[C]);
	while (i.y < MAP_Y)
	{
		i.x = 0;
		while (i.x < MAP_X)
		{
			if (data->map[0][i.y * s_y / MAP_Y][i.x * s_x / MAP_X] == '1')
				data->buf[i_map + i.x] = COLOR_EDGE;
			else if (check_is_edge(data->map[0][i.y * s_y / MAP_Y][i.x * s_x / MAP_X]))
				data->buf[i_map + i.x] = color;
			++i.x;
		}
		++i.y;
		i_map += WIDTH;
	}
}

void	draw_vec(t_data *data, float teta, const uint32_t gray, const uint32_t rev)
{
	uint32_t	dst;
	t_pointu	j;
	t_pointu	o;
	int			i;

	o.y = (uint32_t)(data->plr.pos.y * MAP_Y / data->lst_map.y);
	o.x = (uint32_t)(data->plr.pos.x * MAP_X / data->lst_map.x);
	i = 0;
	j.x = o.x;
	j.y = o.y;
	dst = (j.y * WIDTH) + (WIDTH - MAP_X + j.x);
	while (++i && dst > 0 && j.x < MAP_X && j.y < MAP_Y)
	{
		if ((data->buf[dst] != rev && (data->buf[dst] != gray)) && (i > 3))
		{
			data->buf[dst] = COLOR_G;
			break ;
		}
		data->buf[dst] = gray;
		j.x = o.x + round(i * cos(teta));
		j.y = o.y + round(i * sin(teta));
		dst = (j.y * WIDTH) + (WIDTH - MAP_X + j.x);
	}
}

void	draw_player(t_data *data)
{
	int	x;
	int	y;
	int	cx;
	int	cy;
	int	i;

	i = -11;
	while (++i <= 10)
		draw_vec(data, data->plr.teta - PI42 * i, tool_gray(&data->rgb[C]), tool_rev(&data->rgb[C]));
	cy = (uint32_t)(data->plr.pos.y * MAP_Y / data->lst_map.y);
	cx = (uint32_t)(data->plr.pos.x * MAP_X / data->lst_map.x);
	y = -3;
	while (y <= 3)
	{
		x = -3;
		while (x <= 3)
		{
			if ((y + cy) * WIDTH + (WIDTH - MAP_X + cx + x) > 0)
				data->buf[(y + cy) * WIDTH + (WIDTH - MAP_X + cx + x)] = COLOR_R;
			++x;
		}
		++y;
	}
}
