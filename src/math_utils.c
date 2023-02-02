/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:10:02 by dpalmer           #+#    #+#             */
/*   Updated: 2023/02/02 18:00:52 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rot_x(int *y, int *z, float alpha)
{
	int	y_tmp;

	y_tmp = *y;
	*y = y_tmp * cos(alpha) + *z * sin(alpha);
	*z = -y_tmp * sin(alpha) + *z * cos(alpha);
}

void	rot_y(int *x, int *z, float beta)
{
	int	x_tmp;

	x_tmp = *x;
	*x = x_tmp * cos(beta) + *z * sin(beta);
	*z = -x_tmp * sin(beta) + *z * cos(beta);
}

void	rot_z(int *x, int *y, float gamma)
{
	int	x_tmp;
	int	y_tmp;

	x_tmp = *x;
	y_tmp = *y;
	*x = x_tmp * cos(gamma) - y_tmp * sin(gamma);
	*y = x_tmp * sin(gamma) + y_tmp * cos(gamma);
}

void	iso(int *x, int *y, int z)
{
	int	x_tmp;
	int	y_tmp;

	x_tmp = *x;
	y_tmp = *y;
	*x = (x_tmp - y_tmp) * cos(atan(M_PI_4));
	*y = -z + (x_tmp + y_tmp) * sin(atan(M_PI_4));
}
