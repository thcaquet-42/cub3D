/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 02:40:25 by jaineko           #+#    #+#             */
/*   Updated: 2025/10/23 14:51:08 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

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

void	dda_init(t_data *data, t_dda *dda, t_point ray_dir)
{
	if (ray_dir.x < 0)
	{
		dda->step.x = -1;
		dda->side_dist.x = (data->plr.pos.x - dda->map.x) * dda->delta_dist.x;
	}
	else
	{
		dda->step.x = 1;
		dda->side_dist.x = (dda->map.x + 1.0 - data->plr.pos.x) \
* dda->delta_dist.x;
	}
	if (ray_dir.y < 0)
	{
		dda->step.y = -1;
		dda->side_dist.y = (data->plr.pos.y - dda->map.y) \
* dda->delta_dist.y;
	}
	else
	{
		dda->step.y = 1;
		dda->side_dist.y = (dda->map.y + 1.0 - data->plr.pos.y) \
* dda->delta_dist.y;
	}
}

void	dda_wall(t_data *data, t_dda *dda)
{
	while (1)
	{
		if (dda->side_dist.x < dda->side_dist.y)
		{
			dda->side_dist.x += dda->delta_dist.x;
			dda->map.x += dda->step.x;
			dda->side = 0;
		}
		else
		{
			dda->side_dist.y += dda->delta_dist.y;
			dda->map.y += dda->step.y;
			dda->side = 1;
		}
		if (!check_is_walkable(data->map[dda->map.y][dda->map.x]))
			break ;
	}
}

void	dda_alg(t_data *data, t_dda *dda, t_point plane, int x)
{
	double	camera_x;

	camera_x = 2.0 * x / (double)WIDTH - 1.0;
	dda->ray_dir.x = data->plr.dir.x + plane.x * camera_x;
	dda->ray_dir.y = data->plr.dir.y + plane.y * camera_x;
	dda->map.x = (int)data->plr.pos.x;
	dda->map.y = (int)data->plr.pos.y;
	dda->delta_dist.x = fabs(1.0 / dda->ray_dir.x);
	dda->delta_dist.y = fabs(1.0 / dda->ray_dir.y);
	dda_init(data, dda, dda->ray_dir);
	dda_wall(data, dda);
	if (dda->side == 0)
		dda->wall_dist = dda->side_dist.x - dda->delta_dist.x;
	else
		dda->wall_dist = dda->side_dist.y - dda->delta_dist.y;
	dda->line_height = (int)((double)HEIGHT / dda->wall_dist);
	dda->start = -dda->line_height / 2 + HEIGHT / 2;
	if (dda->start < 0)
		dda->start = 0;
	dda->end = dda->line_height / 2 + HEIGHT / 2;
}
