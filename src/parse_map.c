/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:33:33 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/24 12:37:58 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

static int	get_height(char *file)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_throw_error("Error opening file.");
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		height++;
		line = get_next_line(fd);
	}
	free(line);
	if (close(fd) == -1)
		ft_throw_error("Error closing file.");
	return (height);
}

static int	get_width(char *file)
{
	int		fd;
	int		i;
	int		width;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_throw_error("Error opening file.");
	width = 0;
	line = get_next_line(fd);
	if (!line)
		ft_throw_error("Empty map.");
	i = 0;
	while (line[++i])
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\n'
				|| line[i + 1] == '\0'))
			width++;
	if (close(fd) == -1)
		ft_throw_error("Error closing file.");
	free(line);
	return (width);
}

static void	fill_map(int **z_color, char *line, int width)
{
	int		i;
	int		j;
	char	**values;

	values = ft_split(line, ' ');
	i = 0;
	while (values[i])
	{
		z_color[i] = calloc(sizeof(int), 2);
		if (!z_color[i])
			ft_throw_error("Allocation error.");
		z_color[i][0] = ft_atoi(values[i]);
		j = 0;
		while (values[i][j] && values [i][j] != ',')
			j++;
		if (values[i][j] == ',')
			z_color[i][1] = 
	}

}
