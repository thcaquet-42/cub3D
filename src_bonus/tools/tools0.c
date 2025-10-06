/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaineko <jaineko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:34:10 by thcaquet          #+#    #+#             */
/*   Updated: 2025/10/06 23:22:31 by jaineko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

uint32_t	tool_rgba(int r, int g, int b, int a)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

uint32_t	tool_gray(t_color *color)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	gray;

	r = (color->r >> 16);
	g = (color->g >> 8);
	b = (color->b);
	gray = (r + g + b) / 3;
	return (255 << 24 | gray << 16 | gray << 8 | gray);
}

uint32_t	tool_negative(t_color *color)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	r = 255 - color->r;
	g = 255 - color->g;
	b = 255 - color->b;
	return (255 << 24 | r << 16 | g << 8 | b);
}
