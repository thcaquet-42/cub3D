/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 18:57:47 by thcaquet          #+#    #+#             */
/*   Updated: 2025/10/06 17:27:35 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strcount(const char *str, int c)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] == c)
		i++;
	return (i);
}
