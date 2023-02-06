/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:35:50 by dpalmer           #+#    #+#             */
/*   Updated: 2023/02/06 12:23:48 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "controls.h"

void	zoom(int key, t_fdf *fdf)
{
	if (key == NUM_PLUS || key == MAIN_PLUS || key == MOUSE_SCROLL_UP)
		fdf->cam->zoom++;
	else if (key == NUM_MINUS || key == MAIN_MINUS || key == MOUSE_SCROLL_DOWN)
		fdf->cam->zoom--;
	if (fdf->cam->zoom < 1)
		fdf->cam->zoom = 1;
	draw(fdf->coord, fdf);
}

void	move(int key, t_fdf *fdf)
{
	if (key == ARROW_LEFT)
		fdf->cam->x_offset -= 10;
	else if (key == ARROW_RIGHT)
		fdf->cam->x_offset += 10;
	else if (key == ARROW_UP)
		fdf->cam->y_offset -= 10;
	else if (key == ARROW_DOWN)
		fdf->cam->y_offset += 10;
	draw(fdf->coord, fdf);

}

void	rot(int key, t_fdf *fdf)
{
	if (key == NUM_2 || key == MAIN_2)
		fdf->cam->alpha += 0.05;
	else if (key == NUM_8 || key == MAIN_8)
		fdf->cam->alpha -= 0.05;
	else if (key == NUM_4 || key == MAIN_4)
		fdf->cam->beta -= 0.05;
	else if (key == NUM_6 || key == MAIN_6)
		fdf->cam->beta += 0.05;
	else if (key == NUM_1 || key == MAIN_1
		|| key == NUM_3 || key == MAIN_3)
		fdf->cam->gamma += 0.05;
	else if (key == NUM_7 || key == MAIN_7 || key == NUM_9 || key == MAIN_9)
		fdf->cam->gamma -= 0.05;
	draw(fdf->coord, fdf);
}

void	flat(int key, t_fdf *fdf)
{
	if (key == MAIN_LESS)
		fdf->cam->z_scale -= 0.1;
	else if (key == MAIN_MORE)
		fdf->cam->z_scale += 0.1;
	if (fdf->cam->z_scale < 0.1)
		fdf->cam->z_scale = 0.1;
	else if (fdf->cam->z_scale > 10)
		fdf->cam->z_scale = 10;
	draw(fdf->coord, fdf);
}

void	proj(int key, t_fdf *fdf)
{
	fdf->cam->alpha = 0;
	fdf->cam->beta = 0;
	fdf->cam->gamma = 0;
	if (key == MAIN_I)
		fdf->cam->view = ISOMETRIC;
	else if (key == MAIN_P)
		fdf->cam->view = PARALLEL;
	draw(fdf->coord, fdf);
}
