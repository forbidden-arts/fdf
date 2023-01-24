/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:52:18 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/24 10:44:06 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <errno.h>

void	ft_throw_error(char *str)
{
	ft_putendl_fd(str, STDERR_FILENO);
	exit (-1);
}
