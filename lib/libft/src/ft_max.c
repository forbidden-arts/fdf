/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:30:33 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/31 13:31:44 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max(int count, ...)
{
	va_list	ap;
	int		i;
	int		max;
	int		tmp;

	va_start(ap, count);
	i = 1;
	max = va_arg(ap, int);
	while (i++ < count)
	{
		tmp = va_arg(ap, int);
		if (tmp > max)
			max = tmp;
	}
	return (max);
}
