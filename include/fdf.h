/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:14:05 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/24 15:18:20 by dpalmer          ###   ########.fr       */
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
	int		x;
	int		y;
	int		z;
	int		color;
}	t_point;

typedef struct s_map {
	int		***array;
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

/*		Init						*/
t_map	*ft_map_init(void);

/*		Parse Map					*/
void	ft_validate_map(char *file, t_map *map);

#endif
