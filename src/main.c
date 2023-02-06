/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:42:56 by dpalmer           #+#    #+#             */
/*   Updated: 2023/02/06 10:04:26 by dpalmer          ###   ########.fr       */
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
	t_coord	*coord;

	fd = f_cntrol(argc, argv);
	map = map_init();
	points = fill_map(map, fd);
	coord = coord_init(points, map);
	fdf = fdf_init(map);
	fdf->cam = camera_init(fdf);
	draw(coord, fdf);
	mlx_loop(fdf);
	if (close(fd) == -1)
		ft_throw_error("Error closing file.");
	free(map);
	free(coord);
	return (0);
}
