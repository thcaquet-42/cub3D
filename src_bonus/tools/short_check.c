/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 20:58:34 by thcaquet          #+#    #+#             */
/*   Updated: 2025/10/30 14:43:22 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_case_map(int c)
{
	return (c != ' ' || c != '0' || c != '1' || c != 'N' || c != 'S'
		|| c != 'E' || c != 'W' || c != 'D' || c != 'C' || c != '\n');
}

int	check_is_void(int c)
{
	return (c != ' ' && c != '0' && c != '1' && c != 'N' && c != 'S'
		&& c != 'E' && c != 'W' && c != '\n' && c != 'C' && c != 'D');
}

int	check_is_spawn(int c)
{
	return (c == 'S' || c == 'N' || c == 'W' || c == 'E');
}

int	check_edge(int c)
{
	return (c == '0' || c == 'S' || c == 'N' || c == 'W' || c == 'E' || c == 'C'
		|| c == 'D');
}

int	check_is_walkable(int c)
{
	return (c == '0' || c == 'S' || c == 'N' || c == 'W' || c == 'E'
		|| c == 'D');
}
