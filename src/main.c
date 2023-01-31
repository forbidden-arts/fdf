/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:42:56 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/31 12:31:54 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_map(t_point *points, t_map *map)
{
	int	x;

	while (points)
	{
		x = 0;
		while (x < map->width)
		{
			ft_printf("%d  ", points->z);
			if (points->color)
				ft_printf("color: %d ", points->color);
			points = points->next;
			x++;
		}
		ft_printf("\n");
	}
	ft_printf("Map Stats:\n W: %d, H: %d, Zmax: %d, Zmin %d\n", map->width,
		map->height, map->z_max, map->z_min);
}

static int	f_cntrol(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		ft_throw_error("Usage: ./fdf <file>");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_throw_error("Error opening file.");
	return (fd);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;
	t_point	*points;
	t_fdf	*fdf;

	fd = f_cntrol(argc, argv);
	points = NULL;
	map = map_init();
	points = fill_map(points, map, fd);
	// mlx = mlx_init();
	// display control
	// mlx_loop(mlx);
	// print_map(points, map);
	if (close(fd) == -1)
		ft_throw_error("Error closing file.");
	free(map);
	free_points(points);
	return (0);
}

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

	// void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }
