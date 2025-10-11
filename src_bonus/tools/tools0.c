/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:34:10 by thcaquet          #+#    #+#             */
/*   Updated: 2025/10/11 20:53:06 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

uint32_t	tool_rgba(int r, int g, int b, int a)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

uint32_t	tool_gray(t_color *color)
{
	uint8_t	gray;

	gray = (color->r + color->g + color->b) / 3;
	return (255 << 24 | gray << 16 | gray << 8 | gray);
}

uint32_t	tool_rev(t_color *color)
{
	return (255 << 24 | (255 - color->r) << 16 | (255 - color->g) << 8 | (255 - color->b));
}

int		tool_tick(void)
{
	struct timeval			tv;
	static struct timeval	old_tv = (struct timeval) {0};

	gettimeofday(&tv, NULL);
	if (tv.tv_sec > old_tv.tv_sec || tv.tv_usec > old_tv.tv_usec + 4000)
	{
		old_tv = tv;
		return (1);
	}
	return (0);
}

int	check_enable_door(t_data *data, t_dda *dda, int *x)
{
	float	wall_dist;
	
	if (!data->t_key.door)
		return (0);
	if (dda->side == 0)
		wall_dist = dda->side_dist.x - dda->delta_dist.x;
	else
		wall_dist = dda->side_dist.y - dda->delta_dist.y;
	return (wall_dist <= 3 && (*x <= WIDTH / 2 + 80 && *x >= WIDTH / 2 - 80));
}