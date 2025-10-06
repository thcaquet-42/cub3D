/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:47:35 by thcaquet          #+#    #+#             */
/*   Updated: 2025/10/06 17:29:13 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_str_resize(char *str, int begin, int size)
{
	char	*new;
	int		i;

	if (size < 1 || begin > (int) ft_strlen(str))
		return (0);
	new = malloc(size + 1);
	i = -1;
	while (str && str[begin + ++i] && i < size)
		new[i] = str[begin + i];
	while (i <= size)
	{
		new[i] = 0;
		++i;
	}
	free (str);
	return (new);
}
