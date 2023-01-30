/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:33:33 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/26 18:05:11 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static void	update_z(t_point *point, t_map *map)
// {
// 	if (point->z > map->z_max)
// 		map->z_max = point->z;
// }

static void	parse_line(char *line, t_point *points, t_map *map)
{
	int		x;
	char	**z_pair;
	t_point	*temp;

	x = 0;
	ft_printf("Received line: %s\n", line);
	z_pair = ft_split(line, ' ');
	while (z_pair[x])
	{
		ft_printf("Examining pair: %s, idx %d\n", z_pair[x], x);
		temp = new_point(x, z_pair[x], map);
		add_point(&points, temp);
		x++;
	}
	if (map->width == 0)
		map->width = x;
	else if (map->width != x)
	{
		free_points(&points);
		ft_throw_error("Unstable width.");
	}
}

void	fill_map(int fd, t_point *points, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		ft_throw_error("Empty map.");
	while (line)
	{
		ft_printf("Parsing line:\n %s \n", line);
		parse_line(line, points, map);
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
}

// static int	get_height(char *file)
// {
// 	int		fd;
// 	int		height;
// 	char	*line;

// 	height = 0;
// 	fd = open(file, O_RDONLY);
// 	if (fd < 0)
// 		ft_throw_error("Error opening file.");
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		free(line);
// 		height++;
// 		line = get_next_line(fd);
// 	}
// 	if (close(fd) == -1)
// 		ft_throw_error("Error closing file.");
// 	return (height);
// }

// static int	get_width(char *file)
// {
// 	int		fd;
// 	int		i;
// 	int		width;
// 	char	*line;

// 	fd = open(file, O_RDONLY);
// 	if (fd < 0)
// 		ft_throw_error("Error opening file.");
// 	width = 0;
// 	line = get_next_line(fd);
// 	if (!line)
// 		ft_throw_error("Empty map.");
// 	i = -1;
// 	while (line[++i])
// 		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
// 			width++;
// 	while (line)
// 	{
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	if (close(fd) == -1)
// 		ft_throw_error("Error closing file.");
// 	return (width);
// }

// void	ft_validate_map(char *file, t_map *map)
// {
// 	// map->height = get_height(file);
// 	map->width = get_width(file);
// 	map->height = get_height(file);
// 	ft_printf("H: %d, W: %d\n", map->height, map->width);
// 	free(map);
// }
