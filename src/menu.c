/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:37:48 by dpalmer           #+#    #+#             */
/*   Updated: 2023/02/06 12:24:41 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_back(t_fdf *fdf)
{
	int	*img;
	int	i;

	i = 0;
	ft_bzero(fdf->addr, HEIGHT * WIDTH * fdf->bpp / 8);
	img = (int *)fdf->addr;
	while (i < HEIGHT * WIDTH)
	{
		if (i % WIDTH < MENU)
			img[i] = MENUBACK;
		else
			img[i] = BACK;
		i++;
	}
}

void	print_menu(t_fdf *fdf)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 300;
	mlx = fdf->mlx;
	win = fdf->win;
	mlx_string_put(mlx, win, 65, y += 20, BACK, "How to Use");
	mlx_string_put(mlx, win, 15, y += 60, BACK, "Zoom: Scroll or +/-");
	mlx_string_put(mlx, win, 15, y += 30, BACK, "Move: Arrows");
	mlx_string_put(mlx, win, 15, y += 30, BACK, "Flatten: </>");
	mlx_string_put(mlx, win, 15, y += 30, BACK, "Rotate: Press & Move");
	mlx_string_put(mlx, win, 15, y += 60, BACK, "Rotate:");
	mlx_string_put(mlx, win, 50, y += 30, BACK, "X-Axis - 2/8");
	mlx_string_put(mlx, win, 50, y += 30, BACK, "Y-Axis - 4/6");
	mlx_string_put(mlx, win, 50, y += 30, BACK, "Z-Axis - 1(3)/7(9)");
	mlx_string_put(mlx, win, 15, y += 60, BACK, "Projection");
	mlx_string_put(mlx, win, 50, y += 30, BACK, "Isometric: I");
	mlx_string_put(mlx, win, 50, y += 30, BACK, "Parallel: P");
}
