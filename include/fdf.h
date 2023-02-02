/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:14:05 by dpalmer           #+#    #+#             */
/*   Updated: 2023/02/02 15:09:05 by dpalmer          ###   ########.fr       */
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

typedef struct s_coord {
	int	x;
	int	y;
	int	z;
	int	color;
}	t_coord;

typedef struct s_point {
	int				x;
	int				y;
	int				z;
	int				color;
	struct s_point	*tail;
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
	double	x_angle;
	double	y_angle;
	double	z_angle;
	float	z_scale;
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
	int		bpp;
	int		size_line;
	int		endian;
	t_cam	*cam;
	t_map	*map;
	t_mouse	*mouse;
}	t_fdf;

/*		Error Handling				*/
void	ft_throw_error(char *str);

/*		Mem Handling				*/
void	ft_freetab(char **tab);
void	free_points(t_point *stack);
void	unwind_fdf(t_point *points, t_map *map, int i);

/*		List Utils					*/
t_point	*new_point(void);
void	add_point(t_point **lst, t_point *new);

/*		Init						*/
t_map	*map_init(void);
t_coord	*coord_init(t_point *points, t_map *map);
t_fdf	*fdf_init(t_map *map);
t_cam	*camera_init(t_fdf *fdf);

/*		Parse Map					*/
t_point	*fill_map(t_map *map, int fd);

/*		Math Utils					*/
float	p_dist(int beg, int end, int cur);

/*		Draw						*/
void	put_pxl(t_fdf *img, int x, int y, int color);
void	draw(t_coord *coord, t_fdf *fdf);

/*		Color						*/
float	p_dist(int beg, int end, int cur);
int		get_grad(int beg, int end, float p);
int		get_color(t_coord cur, t_coord beg, t_coord end);

#endif
