/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:22:48 by dpalmer           #+#    #+#             */
/*   Updated: 2022/11/18 18:22:35 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates and returns a string from a given starting point.

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*sub;

	if (!s || len < 0)
		return (NULL);
	s_len = ft_strlen(s);
	if (len > s_len)
		len = s_len;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	if (start < s_len)
	{
		ft_memmove(sub, &s[start], len);
		sub[len] = '\0';
	}
	else
		sub[0] = '\0';
	return (sub);
}
