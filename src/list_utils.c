/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:46:02 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/31 12:59:07 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*new_point(void)
{
	t_point	*new;

	new = malloc(sizeof * (new));
	if (!new)
		return (NULL);
	new->x = 0;
	new->y = 0;
	new->z = 0;
	new->color = 0;
	new->tail = new;
	new->next = NULL;
	return (new);
}

void	add_point(t_point **lst, t_point *new)
{
	if (!*lst)
		*lst = new;
	else
	{
		(*lst)->tail->next = new;
		(*lst)->tail = new;
	}
}
