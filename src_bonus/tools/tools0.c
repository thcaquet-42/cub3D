/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:34:10 by thcaquet          #+#    #+#             */
/*   Updated: 2025/10/11 17:46:15 by thcaquet         ###   ########.fr       */
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

int		tool_tick(int i)
{
	struct timeval			tv;
	static struct timeval	old_tv[2] = (struct timeval[2]) {0};

	gettimeofday(&tv, NULL);
	if (tv.tv_sec > old_tv[i].tv_sec || tv.tv_usec > old_tv[i].tv_usec + 4000 + i * 8000)
	{
		old_tv[i] = tv;
		return (1);
	}
	return (0);
}