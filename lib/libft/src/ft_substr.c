/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:22:48 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/30 17:35:15 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates and returns a string from a given starting point.

/* Optimization update - Jan 30, 2023. Multiple calls to ft_strlen are impacting
the performance of FdF. In the interest of efficiency, ft_strlen is no longer
called, which may result in the over-allocation of memory. Calloc is now used
in place of the previous malloc. In the event a malicious actor tries to access
any indexes beyond the NULL-terminator in the original string, the new 
substring will also produce a series of NULL-terminators.	*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub;

	if (!s || len < 0)
		return (NULL);
	sub = calloc(sizeof(char), (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{	
			sub[j] = s[i];
			j++;
		}
		i++;
	}
	sub[j] = 0;
	return (sub);
}
