/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrocher <emrocher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:33:27 by emrocher          #+#    #+#             */
/*   Updated: 2025/09/22 18:16:47 by emrocher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_point new_point(double x, double y)
{
    t_point new_point;

    new_point.x = x;
    new_point.y = y;
    return(new_point);
}