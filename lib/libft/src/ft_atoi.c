/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 08:04:37 by dpalmer           #+#    #+#             */
/*   Updated: 2022/11/18 18:19:03 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  Per the manual, this is run as a LONG and then recast into an INT. ULONG_MAX
** is defined in header. */

int	ft_atoi(const char *str)
{
	int			i;
	long		sum;
	int			sign;
	const long	long_max = (ULONG_MAX - 1) / 2;

	i = 0;
	sum = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = 1 - 2 * (str[i++] == '-');
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (sum >= long_max / 10 && str[i + 1] > 7 && sign == 1)
			return (-1);
		else if (sum >= long_max / 10 && str[i + 1] > 8 && sign == -1)
			return (0);
		sum = 10 * sum - (str[i++] - '0');
	}
	return ((int)sum * -sign);
}
