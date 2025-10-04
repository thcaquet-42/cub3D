/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaineko <jaineko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 02:40:25 by jaineko           #+#    #+#             */
/*   Updated: 2025/10/04 17:58:40 by jaineko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void dda_init(t_data *data, t_dda *dda, t_point ray_dir)
{
    if(ray_dir.x < 0)
    {
        dda->step.x = -1;
        dda->side_dist.x = (data->plr.pos.x - dda->map.x) * dda->delta_dist.x;
    }
    else
    {
        dda->step.x = 1;
        dda->side_dist.x = (dda->map.x + 1.0 - data->plr.pos.x) * dda->delta_dist.x;
    }

    if(ray_dir.y < 0)
    {
        dda->step.y = -1;
        dda->side_dist.y = (data->plr.pos.y - dda->map.y) * dda->delta_dist.y;
    }
    else
    {
        dda->step.y = 1;
        dda->side_dist.y = (dda->map.y + 1.0 - data->plr.pos.y) * dda->delta_dist.y;
    }
}


void	dda_wall(t_data *data, t_dda *dda)
{

	while(1) 
	{
		if(dda->side_dist.x < dda->side_dist.y)
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
		if(!check_is_walkable(data->map[dda->map.y][dda->map.x])) // dda->map.y > (int)data->lst_map.y || dda->map.x > (int)data->lst_map.x ||
			break;
	}
}

void	dda_alg(t_data *data, t_dda *dda, t_point plane, int x)
{
	t_point	ray_dir;
	double 	cameraX;
	double	perpWallDist;

	cameraX = 2.0 * x / (double)WIDTH - 1.0;
	ray_dir.x = data->plr.dir.x + plane.x * cameraX;
	ray_dir.y = data->plr.dir.y + plane.y * cameraX;
	dda->map.x = (int)data->plr.pos.x;
	dda->map.y = (int)data->plr.pos.y;
	dda->delta_dist.x = fabs(1 / ray_dir.x);
	dda->delta_dist.y = fabs(1 / ray_dir.y);
	dda_init(data, dda, ray_dir);
	dda_wall(data, dda);
	if (dda->side == 0)
		perpWallDist = dda->side_dist.x - dda->delta_dist.x;
	else
		perpWallDist = dda->side_dist.y - dda->delta_dist.y;
	dda->start = -(HEIGHT / perpWallDist) / 2 + HEIGHT / 2;
	if (dda->start < 0)
		dda->start = 0;
	dda->end   = (HEIGHT / perpWallDist) / 2 + HEIGHT / 2;
	if (dda->end >= HEIGHT)
	dda->end = HEIGHT - 1;
}
