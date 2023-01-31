/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:18:24 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/31 13:29:42 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_min(int count, ...)
{
	va_list	ap;
	int		i;
	int		min;
	int		tmp;

	va_start(ap, count);
	i = 1;
	min = va_arg(ap, int);
	while (i++ < count)
	{
		tmp = va_arg(ap, int);
		if (tmp < min)
			min = tmp;
	}
	return (min);
}
