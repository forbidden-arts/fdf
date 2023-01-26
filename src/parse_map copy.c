/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:33:33 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/26 11:25:20 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fdf.h"

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
// 	free(line);
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
// 	if (close(fd) == -1)
// 		ft_throw_error("Error closing file.");
// 	free(line);
// 	ft_printf("Width: %d\n", width);
// 	return (width);
// }

// static void	fill_map(int **z_color, char *line, int width)
// {
// 	int		i;
// 	char	**values;

// 	values = ft_split(line, ' ');
// 	i = 0;
// 	while (values[i])
// 	{
// 		z_color[i] = calloc(sizeof(int), 2);
// 		if (!z_color[i])
// 			ft_throw_error("Allocation error.");
// 		z_color[i][0] = ft_atoi(values[i]);
// 		// if (sub_val[1])
// 		// 	z_color[i][1] = ft_atoi_base(sub_val[1], 16);
// 		// else
// 		// 	z_color[i][1] = -1;
// 		free(values[i]);
// 		i++;
// 	}
// 	free(values);
// 	if (i != width)
// 		ft_printf("fill_map i=%d\n", i);
// }

// static void	z_max_min(t_map *map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	map->z_max = map->array[0][0][0];
// 	map->z_min = map->array[0][0][0];
// 	while (i < map->height)
// 	{
// 		j = 0;
// 		while (j < map->width)
// 		{
// 			if (map->array[i][j][0] < map->z_min)
// 				map->z_min = map->array[i][j][0];
// 			else if (map->array[i][j][0] > map->z_max)
// 				map->z_max = map->array[i][j][0];
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	ft_validate_map(char *file, t_map *map)
// {
// 	int		fd;
// 	int		i;
// 	char	*line;

// 	map->height = get_height(file);
// 	map->width = get_width(file);
// 	map->array = ft_calloc(sizeof(int **), map->height);
// 	if (!map->array)
// 		ft_throw_error("Error allocating for map.");
// 	fd = open(file, O_RDONLY);
// 	if (fd < 0)
// 		ft_throw_error("Error opening file.");
// 	i = 0;
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		map->array[i] = calloc(sizeof(int *), map->width);
// 		fill_map(map->array[i++], line, map->width);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	free(line);
// 	z_max_min(map);
// 	if (close(fd) == -1)
// 		ft_throw_error("Error closing file.");
// }
