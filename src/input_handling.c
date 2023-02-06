/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:17:52 by dpalmer           #+#    #+#             */
/*   Updated: 2023/02/06 15:10:38 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "controls.h"

int	w_close(void *param)
{
	(void)param;
	exit(0);
}

void	user_input(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 0, key_down, fdf);
	mlx_hook(fdf->win, 17, 0, w_close, fdf);
// 	mlx_hook(fdf->win, 4, 0, mouse_down, fdf);
// 	mlx_hook(fdf->win, 5, 0, mouse_up, fdf);
// 	mlx_hook(fdf->win, 6, 0, mouse_move, fdf);
}

int	key_down(int key, void *vars)
{
	// t_fdf	*fdf;

	// fdf = (t_fdf *)vars;
	if (key == MAIN_ESC)
		w_close(vars);
	// if (key == NUM_PLUS || key == MAIN_PLUS
	// 	|| key == NUM_MINUS || key == MAIN_MINUS)
	// 	zoom(key, fdf);
	// else if (key == ARROW_LEFT || key == ARROW_RIGHT
	// 	|| key == ARROW_UP || key == ARROW_DOWN)
	// 	move(key, fdf);
	// else if (key == NUM_1 || key == MAIN_1
	// 	|| key == NUM_2 || key == MAIN_2
	// 	|| key == NUM_3 || key == MAIN_3
	// 	|| key == NUM_4 || key == MAIN_4
	// 	|| key == NUM_6 || key == MAIN_6
	// 	|| key == NUM_7 || key == MAIN_7
	// 	|| key == NUM_8 || key == MAIN_8
	// 	|| key == NUM_9 || key == MAIN_9)
	// 	rot(key, fdf);
	// else if (key == MAIN_LESS || key == MAIN_MORE)
	// 	flat(key, fdf);
	// else if (key == MAIN_P || key == MAIN_I)
	// 	proj(key, fdf);
	return (0);
}
