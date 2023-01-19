/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:59:10 by dpalmer           #+#    #+#             */
/*   Updated: 2022/11/18 18:22:35 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Loops through a string and applies the function to each char.

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*map;
	char	*str;
	int		i;
	int		len;

	if (!s || !(*f))
		return (NULL);
	str = (char *)s;
	i = 0;
	len = ft_strlen(str);
	map = ft_calloc(len + 1, sizeof(char));
	if (!map)
		return (NULL);
	while (i < len)
	{
		map[i] = (*f)(i, str[i]);
		i++;
	}
	return (map);
}
