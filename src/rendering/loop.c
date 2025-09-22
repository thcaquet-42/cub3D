/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrocher <emrocher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:04:17 by emrocher          #+#    #+#             */
/*   Updated: 2025/09/22 18:16:47 by emrocher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void game_loop(void *arg)
{
    t_data *data;
    int x;

    data = (t_data *)arg;
    x = 0;
    key_hooks(data);
    draw_map(data);
}
