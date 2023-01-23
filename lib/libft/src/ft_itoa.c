/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:12:12 by dpalmer           #+#    #+#             */
/*   Updated: 2022/11/18 18:22:35 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int n)
{
	int	i;

	i = 0 + (n < 0);
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*result;

	size = get_size(n);
	result = (char *)ft_calloc(size + 1, sizeof(char));
	if (!result)
		return (NULL);
	if (n == 0)
		result[0] = '0';
	else if (n < 0)
		result[0] = '-';
	else
		n *= -1;
	while (n != 0)
	{
		result[size-- - 1] = '0' - (n % 10);
		n /= 10;
	}
	return (result);
}
