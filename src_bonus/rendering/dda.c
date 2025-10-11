/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 02:40:25 by jaineko           #+#    #+#             */
/*   Updated: 2025/10/11 17:44:50 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	dda_choose_tex(t_data *data, t_dda *dda)
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

void	dda_door(t_data *data, t_dda *dda, t_door *door)
{
	door->is = 1;
	door->tex = &data->tex[DOOR];
	door->ray_dir.x = dda->ray_dir.x;
	door->ray_dir.y = dda->ray_dir.y;
	door->line_height = (int)((float)HEIGHT / door->wall_dist);
	door->start = -door->line_height / 2 + HEIGHT / 2;
	if (door->start < 0)
		door->start = 0;
	door->end = door->line_height / 2 + HEIGHT / 2;
	if (dda->side  == 0)
		door->wall_x = data->plr.pos.y + door->wall_dist * door->ray_dir.y;
	else
		door->wall_x = data->plr.pos.x + door->wall_dist * door->ray_dir.x;
	door->tex_x = (int)((door->wall_x - floor(door->wall_x)) * door->tex->width);
	if (door->tex_x >= door->tex->width)
		door->tex_x = door->tex->width - 1;
	if ((!dda->side  && door->ray_dir.x > 0) || (dda->side  && door->ray_dir.y < 0))
		door->tex_x = door->tex->width - door->tex_x - 1;
	if (door->line_height <= 0)
		door->line_height = 1;
	door->tex_step = (float)door->tex->height / (float)door->line_height;
	door->map.x = dda->map.x;
	door->map.y = dda->map.y;
}

int		check_enable_door(t_data *data, t_dda *dda, int *x)
{
	float	wall_dist;
	
	if (!data->t_key.door)
		return (0);
	if (dda->side == 0)
		wall_dist = dda->side_dist.x - dda->delta_dist.x;
	else
		wall_dist = dda->side_dist.y - dda->delta_dist.y;
	return (wall_dist <= 1 && (*x <= WIDTH / 2 + 50 && *x >= WIDTH / 2 - 50));
}

void	get_door(t_data *data, t_dda *dda, int *x)
{
	unsigned char	*state;
	int				tick;

	if (check_enable_door(data, dda, x))
	{
		if (data->map[0][dda->map.y][dda->map.x] == 'D')
			data->map[0][dda->map.y][dda->map.x] = 'C';
		else if (data->map[0][dda->map.y][dda->map.x] == 'C')
			data->map[0][dda->map.y][dda->map.x] = 'D';
		data->t_key.door = 0;
	}
	if (!dda->door.is)
	{
		if (dda->side == 0)
			dda->door.wall_dist = dda->side_dist.x - dda->delta_dist.x;
		else
			dda->door.wall_dist = dda->side_dist.y - dda->delta_dist.y;
		dda_door(data, dda, &dda->door);
		state = (unsigned char *) &data->map[1][dda->map.y][dda->map.x];
	}
	tick = tool_tick(0);
	if (tick && data->map[0][dda->map.y][dda->map.x] == 'D' && *state < 125)
		*state += 1;
	if (tick && data->map[0][dda->map.y][dda->map.x] == 'C' && *state > 0)
		*state -= 1;
}

void	dda_wall(t_data *data, t_dda *dda, int *x)
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
		if (check_is_door(data->map[0][dda->map.y][dda->map.x]))
			get_door(data, dda, x);
		else if (check_is_wall(data->map[0][dda->map.y][dda->map.x]))
			break ;
	}
}

void	dda_alg(t_data *data, t_dda *dda, t_point plane, int x)
{
	float	camera_x;

	dda->door.is = 0;
	camera_x = 2.0 * x / (float)WIDTH - 1.0;
	dda->ray_dir.x = data->plr.dir.x + plane.x * camera_x;
	dda->ray_dir.y = data->plr.dir.y + plane.y * camera_x;
	dda->map.x = (int)data->plr.pos.x;
	dda->map.y = (int)data->plr.pos.y;
	dda->delta_dist.x = fabs(1.0 / dda->ray_dir.x);
	dda->delta_dist.y = fabs(1.0 / dda->ray_dir.y);
	dda_init(data, dda, dda->ray_dir);
	dda_wall(data, dda, &x);
	if (dda->side == 0)
		dda->wall_dist = dda->side_dist.x - dda->delta_dist.x;
	else
		dda->wall_dist = dda->side_dist.y - dda->delta_dist.y;
	dda->line_height = (int)((float)HEIGHT / dda->wall_dist);
	dda->start = -dda->line_height / 2 + HEIGHT / 2;
	if (dda->start < 0)
		dda->start = 0;
	dda->end = dda->line_height / 2 + HEIGHT / 2;
}
