/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:17:52 by dpalmer           #+#    #+#             */
/*   Updated: 2023/02/07 15:16:19 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "controls.h"

int	w_close(t_fdf *fdf)
{
	exit(0);
	mlx_destroy_window(fdf->mlx, fdf->win);
	return(0);
}

void	user_input(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 0, key_down, fdf);
	mlx_hook(fdf->win, 17, 0, w_close, fdf);
}

int	key_down(int key, t_fdf *fdf)
{
	if (key == MAIN_ESC)
		w_close(fdf);
	return (0);
}
