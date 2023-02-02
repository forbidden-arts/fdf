/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:00:20 by dpalmer           #+#    #+#             */
/*   Updated: 2023/02/02 12:33:47 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pxl(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	dst = fdf->addr + (y * fdf->size_line + x * fdf->bpp / 8);
	*(unsigned int *)dst = color;
}

// void	draw_line()
// {

// }

void	draw(t_coord *coord, t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < (fdf->map->height) * (fdf->map->width))
	{
		put_pxl(fdf, (coord[i].x) * fdf->cam->zoom, (coord[i].y) * fdf->cam->zoom, 0xFFFFFF);
		i++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
