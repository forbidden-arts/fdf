/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:03:02 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/26 15:16:33 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* TODO:

	Enviro Init
	Camera Init
	Mouse Init?

*/

t_map	*ft_map_init(void)
{
	t_map	*map;

	map = malloc(sizeof * map);
	map->height = 0;
	map->width = 0;
	map->z_min = 0;
	map->z_max = 0;
	return (map);
}
