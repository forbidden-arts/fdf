/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:44:48 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/24 13:48:02 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	chk_atoi_base(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	chr_to_num(char c)
{
	int		i;
	char	*set;

	i = 0;
	set = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	while (set[i])
	{
		if (c == set[i])
			break ;
		i++;
	}
	if (set[i] != '\0')
		return (i);
	return (-1);
}

/* Converts positive numbers of base(n) or addresses into an unsigned INT. */
unsigned int	ft_atoi_base(char *str, int base)
{
	unsigned int	sum;

	sum = 0;
	if (base < 2 || base > 36)
		return (0);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	str = ft_strtrim(str, " \n\t\v\r\f");
	if (chk_atoi_base(str))
	{
		if (!ft_strncmp(str, "0x", 2))
			str += 2;
		while (str)
		{
			if (chr_to_num(ft_toupper(*str)) < 0
				|| chr_to_num(ft_toupper(*str)) >= base)
				break ;
			sum = base * sum + chr_to_num(ft_toupper(*str));
			str++;
		}
	}
	return (sum);
}
