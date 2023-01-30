/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:33:33 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/30 12:14:07 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	*parse_point(t_point *point, char *z_color)
{
	char	**tmp;

	tmp = ft_split(z_color, ',');
	point->z = ft_atoi(tmp[0]);
	if (tmp[1])
		point->color = ft_atoi_base(tmp[1], 16);
	ft_freetab(tmp);
	return (point);
}

static t_point	*parse_line(t_point *points, t_map *map, char *line)
{
	int		x;
	t_point	*point;
	char	**z_color;

	x = 0;
	point = NULL;
	z_color = ft_split(line, ' ');
	while (z_color[x])
	{
		point = parse_point(new_point(), z_color[x]);
		point->x = x;
		point->y = map->height;
		add_point(&points, point);
		x++;
	}
	if (map->width == 0)
		map->width = x;
	if (map->width != x)
	{
		free_points(points);
		ft_throw_error("Unstable width.");
	}
	ft_freetab(z_color);
	return (points);
}

static void	update_z(t_point *point, t_map *map)
{
	while (point)
	{
		if (point->z > map->z_max)
			map->z_max = point->z;
		else if (point->z < map->z_min)
			map->z_min = point->z;
		point = point->next;
	}
}

t_point	*fill_map(t_point *points, t_map *map, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		ft_throw_error("Empty map.");
	while (line)
	{
		points = parse_line(points, map, line);
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	update_z(points, map);
	ft_printf("Map filled.\n");
	return (points);
}
