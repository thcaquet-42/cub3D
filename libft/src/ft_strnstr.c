/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:25:51 by thcaquet          #+#    #+#             */
/*   Updated: 2025/09/11 14:51:56 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!(*(unsigned char *)little))
		return ((void *) big);
	if (!len)
		return (0);
	i = 0;
	while (*(unsigned char *)(big + i) && (i < len))
	{
		j = 0;
		while (*(unsigned char *)(big + i + j) ==
				*(unsigned char *)(little + j) && j < len)
		{
			j++;
			if (*(unsigned char *)(little + j) == 0 &&
				i + j <= len)
				return ((void *)(big + i));
		}
		i++;
	}
	return (0);
}
