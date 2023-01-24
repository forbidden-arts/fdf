/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:03:16 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/24 10:32:52 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_freetab(char **tab)
{
	size_t	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}