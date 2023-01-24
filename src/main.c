/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:42:56 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/24 15:59:54 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

void	print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			ft_printf("%d ", map->array[i][j][0]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("H: %d W: %d Max: %d Min: %d\n", map->height, map->width,
		map->z_max, map->z_min);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		ft_throw_error("Usage: ./fdf <file>");
	map = ft_map_init();
	ft_validate_map(argv[1], map);
	print_map(map);
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
