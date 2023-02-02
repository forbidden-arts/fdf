/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:00:20 by dpalmer           #+#    #+#             */
/*   Updated: 2023/02/02 19:16:42 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	project(t_coord point, t_fdf *fdf)
{
	point.x += (WIDTH - (fdf->map->width - 1) * fdf->cam->zoom) / 2 + MENU
		+ fdf->cam->x_offset;
	point.y += (HEIGHT - (fdf->map->height - 1) * fdf->cam->zoom) / 2
		+ fdf->cam->y_offset;
	rot_x(&point.y, &point.z, fdf->cam->alpha);
	rot_y(&point.x, &point.z, fdf->cam->beta);
	rot_z(&point.x, &point.y, fdf->cam->gamma);
	if (fdf->cam->view == ISOMETRIC)
		iso(&point.x, &point.y, point.z);
	return (point);
}

void	put_pxl(t_fdf *fdf, int x, int y, int color)
{
	int	i;

	if (x >= MENU && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * fdf->bpp / 8 + y * fdf->size_line);
		fdf->addr[i] = color;
		fdf->addr[++i] = color >> 8;
		fdf->addr[++i] = color >> 16;
	}
}

/* Using Bresenham's Algo, since it seems pretty straight forward. */
void	draw_line(t_coord beg, t_coord end, t_fdf *fdf)
{
	int		error[2];
	int		sign[2];
	t_coord	tmp;

	sign[0] = 1 - 2 * (beg.x < end.x);
	sign[1] = 1 - 2 * (beg.y < end.y);
	error[0] = ft_abs(beg.x - end.x) - ft_abs(beg.y - end.y);
	tmp = beg;
	while (tmp.x != end.x || tmp.y != end.y)
	{
		put_pxl(fdf, tmp.x, tmp.y, get_color(tmp, beg, end));
		error[1] = 2 * error[0];
		if (error[1] >= -ft_abs(beg.y - end.y))
		{
			error[0] += -ft_abs(beg.y - end.y);
			tmp.x += sign[0];
		}
		if (error[1] < ft_abs(beg.x - end.x))
		{
			error[0] += ft_abs(beg.x - end.x);
			tmp.y += sign[1];
		}
	}
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
				draw_line(project(coord[x + y * fdf->map->width], fdf),
					project(coord[(x + 1) + y * fdf->map->width], fdf), fdf);
			}
			if (y != fdf->map->height - 1)
			{
				draw_line(project(coord[x + y * fdf->map->width], fdf),
					project(coord[x + (y + 1) * fdf->map->width], fdf), fdf);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
