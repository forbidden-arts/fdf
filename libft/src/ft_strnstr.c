/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 07:39:43 by dpalmer           #+#    #+#             */
/*   Updated: 2022/11/18 18:22:35 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns whether a string is contained within another string

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;
	char	*str;

	i = 0;
	str = (char *)haystack;
	needle_len = ft_strlen(needle);
	if (!needle_len || haystack == needle)
		return (str);
	if (!len)
		return (NULL);
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (str[i + j] != '\0' && needle[j] != '\0'
			&& str[i + j] == needle[j] && i + j < len)
			j++;
		if (j == needle_len)
			return (str + i);
		i++;
	}
	return (NULL);
}
