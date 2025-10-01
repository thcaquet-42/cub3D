/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrocher <emrocher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:04:08 by emrocher          #+#    #+#             */
/*   Updated: 2025/10/01 18:38:09 by emrocher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	check_pxl_map(t_data *data, int x, int y)
{
	if (data->map[y * data->lst_map.y / MAP_Y][x * data->lst_map.x / MAP_X] == '1')
	{
		mlx_put_pixel(data->minimap, WIDTH - 20 - MAP_X + x, y, tool_rgba(10, 10, 10, 255));
	}
	else if(check_is_walkable(data->map[y * data->lst_map.y / MAP_Y][x * data->lst_map.x / MAP_X])) 
		mlx_put_pixel(data->minimap, WIDTH - 20 - MAP_X + x, y,  tool_rgba(50, 50, 100, 255));
}

void draw_map(t_data *data)
{
    uint32_t x;
    uint32_t y;

    y = 0;
    while (y < MAP_Y)
    {
        x = 0;
        while (x < MAP_X)
        {
            check_pxl_map(data, x, y);
            x++;
        }
    y++;
    }
}
