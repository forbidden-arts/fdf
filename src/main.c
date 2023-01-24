/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:42:56 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/24 12:23:31 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char **argv)
{
	// void	*mlx;
	// void	*mlx_win;
	// t_fdf	img;

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 		&img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FFFFFF);
	// my_mlx_pixel_put(&img, 50, 50, 0x00FFFFFF);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// mlx_loop(mlx);
	if (argc != 2)
		ft_throw_error("Usage: ./fdf <file>");
	argv = NULL;
	int i = 0;
	while (i++ < 10)
		ft_printf("%d", i);
	return (0);
}
