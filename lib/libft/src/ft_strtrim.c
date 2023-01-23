/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:03:53 by dpalmer           #+#    #+#             */
/*   Updated: 2022/11/18 18:22:35 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*beg;
	const char	*end;

	if (!s1 || !set)
		return (NULL);
	beg = s1;
	end = s1 + ft_strlen(s1);
	while (ft_strchr(set, *beg) && beg <= end)
		beg++;
	while (ft_strchr(set, *end) && beg <= end)
		end--;
	return (ft_substr(s1, beg - s1, end - beg + 1));
}
