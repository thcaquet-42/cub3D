/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrocher <emrocher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:04:08 by emrocher          #+#    #+#             */
/*   Updated: 2025/10/01 18:12:12 by emrocher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	check_pxl_map(t_data *data, int x, int y)
{
	if (data->map[y * data->lst_map.y / 200][x * data->lst_map.x / 200] == '1')
	{
		mlx_put_pixel(data->minimap, x, y, 0xFF3b3939); // 0xFF3b3939
	}
	else if(check_is_walkable(data->map[y * data->lst_map.y / 200][x * data->lst_map.x / 200])) 
		mlx_put_pixel(data->minimap, x, y, 0xFFc2c2c2); // 0xFFc2c2c2
}

void draw_map(t_data *data)
{
    uint32_t x;
    uint32_t y;

    y = 0;
    while (y < 200)
    {
        x = 0;
        while (x < 200)
        {
            check_pxl_map(data, x, y);
            x++;
        }
    y++;
    }
}
