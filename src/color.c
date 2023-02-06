/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:43:44 by dpalmer           #+#    #+#             */
/*   Updated: 2023/02/06 11:18:33 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	p_dist(int beg, int end, int cur)
{
	if (beg == end)
		return (1.0);
	else
		return ((cur - beg) / (end - beg));
}

int	get_grad(int beg, int end, float p)
{
	return ((int)((1 - p) * beg + p * end));
}

int	get_color(t_coord cur, t_coord beg, t_coord end)
{
	int		red;
	int		green;
	int		blue;
	float	p;

	if (ft_abs(beg.x - end.x) > ft_abs(beg.y - end.y))
		p = p_dist(beg.x, end.x, cur.x);
	else
		p = p_dist(beg.y, end.y, cur.y);
	red = get_grad((beg.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, p);
	green = get_grad((beg.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, p);
	blue = get_grad(beg.color & 0xFF, end.color & 0xFF, p);
	return ((red << 16) | (green << 8) | blue);
}
