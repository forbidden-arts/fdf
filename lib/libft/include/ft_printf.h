/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:43:28 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/23 11:35:50 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *format, ...);

// Utility Funcs
int		ft_count_digits(unsigned long num, int base);
char	*ft_ltoa_b(long long num, int base);
int		ft_pf_char(char c);
int		ft_pf_str(char *str);
int		ft_pf_int(int i);
int		ft_pf_base(unsigned long ul, int base, int upper);
int		ft_pf_ptr(unsigned long ul);

#endif
