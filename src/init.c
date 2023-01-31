/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:03:02 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/31 13:48:21 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* TODO:

	Enviro Init
	Camera Init
	Mouse Init?

*/

t_map	*map_init(void)
{
	t_map	*map;

	map = malloc(sizeof(map));
	if (!map)
		return (NULL);
	map->height = 0;
	map->width = 0;
	map->z_min = 0;
	map->z_max = 0;
	return (map);
}

t_fdf	*fdf_init(t_point *points, t_map *map)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(fdf));
	if (!fdf)
		unwind_fdf(points, map, 1);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FdF");
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->addr = mlx_get_data_addr(fdf->img, &(fdf->bpp), &(fdf->size_line),
			&(fdf->endian));
	fdf->map = map;
	fdf->points = points;
	fdf->mouse = malloc(sizeof(t_mouse));
	return (fdf);
}

t_cam	*camera_init(t_fdf *fdf)
{
	t_cam	*camera;

	camera = malloc(sizeof(camera));
	if (!camera)
	{
		unwind_fdf(fdf->points, fdf->map, 0);
		free(fdf);
		ft_throw_error("Error initializing camera.");
	}
	camera->zoom = ft_min(2, (WIDTH - MENU) / fdf->map->width / 2, HEIGHT
			/ fdf->map->height / 2);
	camera->x_angle = 0;
	camera->y_angle = 0;
	camera->z_angle = 0;
	camera->z_scale = 1.0;
	camera->x_offset = 0;
	camera->y_offset = 0;
	camera->view = ISOMETRIC;
	return (camera);
}
