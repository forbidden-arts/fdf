/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:00:20 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/31 13:01:22 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pxl(t_fdf *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * img->bpp / 8);
	*(unsigned int *)dst = color;
}
