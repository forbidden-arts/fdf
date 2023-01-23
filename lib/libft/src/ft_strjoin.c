/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:05:47 by dpalmer           #+#    #+#             */
/*   Updated: 2022/11/18 18:22:35 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates memory and returns the concatenation of two strings.

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s_len;
	size_t	t_len;

	if (!s1 || !s2)
		return (NULL);
	s_len = ft_strlen(s1);
	t_len = s_len + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * t_len);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s_len + 1);
	ft_strlcat(str, s2, t_len);
	return (str);
}
