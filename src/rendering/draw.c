/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrocher <emrocher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:04:08 by emrocher          #+#    #+#             */
/*   Updated: 2025/09/22 18:16:47 by emrocher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void check_pxl_map(t_data *data, int x, int y)
{
}

static t_arrow init_arrow(t_data *data)
{

}

static bool check_pxl_player(t_point a, t_point b, t_point c, t_point point)
{

}

void draw_map(t_data *data)
{
    int x;
    int y;
    t_arrow player;
    t_point pxl;

    y = 0;
    player = init_arrow(data);
    while (y < 200)
    {
        x = 0;
        while (x < 200)
        {
            check_pxl_map(data, x, y);
            pxl = new_point((double)x - 100.0, (double)y - 100.0);
            if (check_pxl_player(player.front, player.back, player.side, pxl))
            pxl_put(data->minimap, x, y, 0xFFFF0000);
            if (check_pxl_player(player.front, player.sym, player.back, pxl))
            pxl_put(data->minimap, x, y, 0xFF000000);
            x++;
        }
    y++;
    }
}
