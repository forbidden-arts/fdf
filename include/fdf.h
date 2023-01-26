/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:14:05 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/26 18:53:36 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "../lib/libft/include/libft.h"

# define WIDTH 1920
# define HEIGHT 1080
# define MENU 300

typedef enum e_proj {
	ISOMETRIC,
	PARALLEL
}	t_proj;

/* TODO:
	structs for:
		mouse?
*/

typedef struct s_point {
	int				x;
	int				y;
	int				z;
	int				color;
	struct s_point	*next;
}	t_point;

typedef struct s_map {
	int		height;
	int		width;
	int		z_min;
	int		z_max;
}	t_map;

typedef struct s_cam {
	int		zoom;
	float	x_angle;
	float	y_angle;
	float	z_angle;
	int		x_offset;
	int		y_offset;
	t_proj	view;
}	t_cam;

typedef struct s_mouse {
	int		button;
	int		x;
	int		y;
	int		x_prev;
	int		y_prev;
}	t_mouse;

typedef struct s_fdf {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_fdf;

/*		Error Handling				*/
void	ft_throw_error(char *str);

/*		Mem Handling				*/
void	ft_freetab(char **tab);

/*		List Utils					*/
t_point	*new_point(int x, char *sub, t_map *map);
void	add_point(t_point **lst, t_point *new);
t_point	*last_point(t_point *lst);
void	free_points(t_point **stack);

/*		Init						*/
t_map	*map_init(void);
t_point	*points_init(void);

/*		Parse Map					*/
void	fill_map(int fd, t_point *points, t_map *map);

#endif
