/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:44:48 by dpalmer           #+#    #+#             */
/*   Updated: 2022/11/18 18:22:35 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  This function performs three checks: First, if the destination already
matches the source, it simply returns. Second, if the destination begins after
the source, the while loop is reversed (decrimented) to remove the chance that
incorrect information is copied. Otherwise the loop is performed normally.  */

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;

	if (dst == src)
		return (dst);
	d = (unsigned char *)(dst);
	s = (unsigned char *)(src);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	while (len--)
		*(d++) = *(s++);
	return (dst);
}
