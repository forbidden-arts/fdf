/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:20:19 by dpalmer           #+#    #+#             */
/*   Updated: 2022/11/18 18:22:35 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Concatenates two strings, if possible, and returns the dest string length. */

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	s_len;
	size_t	d_len;

	j = 0;
	if ((!dst ||!src) && dstsize == 0)
		return (0);
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	i = d_len;
	if (dstsize == 0 || dstsize <= d_len)
		return (s_len + dstsize);
	while (src[j] && (d_len + j) < dstsize)
		dst[i++] = src[j++];
	if ((d_len + j) == dstsize && d_len < dstsize)
		dst[i - 1] = '\0';
	else
		dst[i] = '\0';
	return (s_len + d_len);
}
