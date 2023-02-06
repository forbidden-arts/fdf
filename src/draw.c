/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:00:20 by dpalmer           #+#    #+#             */
/*   Updated: 2023/02/06 10:18:45 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	project(t_coord point, t_fdf *fdf)
{
	int	zoom;

	zoom = fdf->cam->zoom;
	point.x *= zoom;
	point.y *= zoom;
	point.z *= zoom / fdf->cam->z_scale;
	point.x -= fdf->map->width * zoom / 2;
	point.y -= fdf->map->height * zoom / 2;
	rot_x(&point.y, &point.z, fdf->cam->alpha);
	rot_y(&point.x, &point.z, fdf->cam->beta);
	rot_z(&point.x, &point.y, fdf->cam->gamma);
	if (fdf->cam->view == ISOMETRIC)
		iso(&point.x, &point.y, point.z);
	point.x += (WIDTH - MENU) / 2 + MENU + fdf->cam->x_offset;
	point.y += (HEIGHT - fdf->map->height * zoom) + fdf->cam->y_offset;
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

static void	line_prep(t_coord *delta, t_coord *sign, t_coord beg, t_coord end)
{
	delta->x = ft_abs(end.x - beg.x);
	delta->y = -ft_abs(end.y - beg.y);
	if (beg.x < end.x)
		sign->x = 1;
	else
		sign->x = -1;
	if (beg.y < end.y)
		sign->y = 1;
	else
		sign->y = -1;
}

/* Using Bresenham's Algo, since it seems pretty straight forward. */
void	draw_line(t_coord beg, t_coord end, t_fdf *fdf)
{
	t_coord	delta;
	t_coord	sign;
	t_coord	tmp;
	int		error[2];

	line_prep(&delta, &sign, beg, end);
	error[0] = delta.x + delta.y;
	tmp = beg;
	while (tmp.x != end.x || tmp.y != end.y)
	{
		put_pxl(fdf, tmp.x, tmp.y, get_color(tmp, beg, end));
		error[1] = 2 * error[0];
		if (error[1] >= delta.y)
		{
			error[0] += delta.y;
			tmp.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			tmp.y += sign.y;
		}
	}
}

void	draw(t_coord *coord, t_fdf *fdf)
{
	int	x;
	int	y;

	draw_back(fdf);
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
