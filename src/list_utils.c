/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:46:02 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/26 15:44:33 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*new_point(int x, char *sub, t_map *map)
{
	t_point	*tmp;
	char	**z_color;

	tmp = malloc(sizeof * (tmp));
	if (!tmp)
		return (NULL);
	ft_printf("Unparsed pair: %s\n", sub);
	z_color = ft_split(sub, ',');
	ft_printf("Orig Z: %s\n", z_color[0]);
	tmp->x = x;
	tmp->y = map->height;
	tmp->z = ft_atoi(z_color[0]);
	if (z_color[1])
		tmp->color = ft_atoi_base(z_color[1], 16);
	else
		tmp->color = -1;
	ft_freetab(z_color);
	tmp->next = NULL;
	ft_printf("x %d, y %d, z %d, c: %d\n", tmp->x, tmp->y, tmp->z, tmp->color);
	return (tmp);
}

void	add_point(t_point **lst, t_point *new)
{
	t_point	*temp;

	if (!*lst)
		*lst = new;
	else
	{
		temp = last_point(*lst);
		temp->next = new;
	}
}

t_point	*last_point(t_point *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next == NULL)
		return (lst);
	return (last_point(lst->next));
}

void	free_points(t_point **stack)
{
	t_point	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	free(stack);
}
