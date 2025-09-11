/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:24:42 by thcaquet          #+#    #+#             */
/*   Updated: 2025/09/11 14:51:56 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	r;

	r = (char) c;
	i = 0;
	if (r == 0)
		return ((char *)(s + ft_strlen((char *)s)));
	while (*(char *)(s + i))
	{
		if (*(char *)(s + i) == r)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}
