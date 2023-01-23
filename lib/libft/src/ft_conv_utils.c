/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:26:19 by dpalmer           #+#    #+#             */
/*   Updated: 2022/11/18 18:19:34 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_digits(unsigned long num, int base)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= base;
		i++;
	}
	return (i);
}

static char	ft_n_base(int n)
{
	if (n >= 0 && n <= 9)
		return ((char)(n + 48));
	return ((char)(n + 87));
}

char	*ft_ltoa_b(long long num, int base)
{
	int				i;
	char			*result;
	unsigned long	num_p;

	if (base < 2 || base > 36)
		return (NULL);
	result = ft_calloc(ft_count_digits(num, base) + 1, sizeof(char));
	if (!result)
		return (NULL);
	if (!num)
		result[0] = '0';
	i = 0;
	num_p = (unsigned long)num;
	while (num_p)
	{
		result[i++] = ft_n_base(num_p % base);
		num_p /= base;
	}
	return (ft_strrev(result));
}
