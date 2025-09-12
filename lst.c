/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:04:05 by thcaquet          #+#    #+#             */
/*   Updated: 2025/09/12 22:10:05 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	lst_add_back(t_tail *tail, char *content)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (!new)
		return ;
	new->str = ft_strdup((const char *) content);
	if (!new->str)
		return ;
	if (!tail->start)
		tail->start = new;
	new->next = 0;
	if (tail->end)
		tail->end->next = new;
	tail->end = new;
	tail->y += 1;
}

t_tail	lst_set()
{
	t_tail tail;

	tail.start = 0;
	tail.end = 0;
	tail.x = 0;
	tail.y = 0;

	return (tail);
}
