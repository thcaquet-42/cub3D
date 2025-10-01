/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:51:03 by thcaquet          #+#    #+#             */
/*   Updated: 2025/10/01 18:53:31 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_key_hook(mlx_key_data_t d_k, void *data)
{
	t_data	*c_d;

	c_d = data;
	if (d_k.key == MLX_KEY_ESCAPE)
		mlx_close_window(c_d->mlx);
	if (d_k.key == MLX_KEY_Z && d_k.action == MLX_PRESS)
	{
		printf("Z\n");
	}
}