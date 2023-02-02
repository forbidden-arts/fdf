/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:00:20 by dpalmer           #+#    #+#             */
/*   Updated: 2023/02/02 15:33:49 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	project(t_coord point, t_fdf *fdf)
{
	point.x = (WIDTH - (fdf->map->width - 1) * fdf->cam->zoom) / 2 + MENU
		+ fdf->cam->x_offset;
	point.y = (HEIGHT - (fdf->map->height - 1) * fdf->cam->zoom) / 2
		+ fdf->cam->y_offset;
}

void	put_pxl(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	dst = fdf->addr + (y * fdf->size_line + x * fdf->bpp / 8);
	*(unsigned int *)dst = color;
}

void	draw_line(t_coord start, t_coord end, t_fdf *fdf)
{

}

void	draw(t_coord *coord, t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (x != fdf->map->width - 1)
			{
				// draw line (x, x+1)
			}
			if (y != fdf->map->height - 1)
			{
				// draw line (y, y+1)
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
