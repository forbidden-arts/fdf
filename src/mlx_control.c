/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:10:02 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/31 11:23:42 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_control(t_point *points, t_map *map)
{
	void	*mlx;
	void	*mlx_win;
	t_fdf	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "FdF");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	put_pxl(&img, 5, 5, 16711680);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

void	put_map(t_point *points, t_map *map)
{
	int	zoom;

	if (/* condition */)
	{
		/* code */
	}

}
