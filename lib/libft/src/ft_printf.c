/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:13:11 by dpalmer           #+#    #+#             */
/*   Updated: 2022/11/18 18:22:35 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pf_args(va_list *ap, char c, int count)
{
	if (c == '%')
		count += ft_pf_char('%');
	else if (c == 'c')
		count += ft_pf_char(va_arg(*ap, int));
	else if (c == 's')
		count += ft_pf_str(va_arg(*ap, char *));
	else if (c == 'd' || c == 'i')
		count += ft_pf_int(va_arg(*ap, int));
	else if (c == 'u')
		count += ft_pf_base(va_arg(*ap, unsigned int), 10, 0);
	else if (c == 'x' || c == 'X')
		count += ft_pf_base(va_arg(*ap, unsigned int), 16, (1 * (c == 'X')));
	else if (c == 'p')
		count += ft_pf_ptr(va_arg(*ap, unsigned long));
	return (count);
}

static int	ft_pf_parse(char *str, va_list *ap)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (!*str)
				break ;
			count += ft_pf_args(ap, *str, 0);
		}
		else
			count += ft_pf_char(*str);
		str++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	char	*str;

	if (!format)
		return (0);
	str = ft_strdup(format);
	if (!str)
		return (0);
	va_start(ap, format);
	count = ft_pf_parse(str, &ap);
	va_end(ap);
	free (str);
	return (count);
}
