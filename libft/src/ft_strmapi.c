/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:17:14 by thcaquet          #+#    #+#             */
/*   Updated: 2025/09/11 14:51:56 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	if (!s || !f)
		return (0);
	i = ft_strlen(s);
	str = malloc(i + 1);
	if (!str)
		return (0);
	str[i] = 0;
	while (i--)
		str[i] = f(i, s[i]);
	return (str);
}
