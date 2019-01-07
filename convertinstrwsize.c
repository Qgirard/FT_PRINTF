/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertinstrwsize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:00:18 by qgirard           #+#    #+#             */
/*   Updated: 2019/01/03 16:10:26 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convertinstrwsize2(char **str, t_check *stock, va_list vl)
{
	if (ft_strcmp(stock->size, "ll"))
		convertinstrwsize2(str, stock, vl);
	else if (stock->type == 'd' || stock->type == 'i')
		*str = ft_strjoinf(*str, ft_ltoa(va_arg(vl, long long)), 3);
	else if (stock->type == 'u')
		*str = ft_strjoinf(*str, ft_ultoa_base(va_arg(vl, unsigned long long),
		10), 3);
	else if (stock->type == 'b')
		*str = ft_strjoinf(*str, ft_ultoa_base(va_arg(vl, unsigned long long),
		2), 3);
	else if (stock->type == 'o')
		*str = ft_strjoinf(*str, ft_ultoa_base(va_arg(vl, unsigned long long),
		8), 3);
	else if (stock->type == 'x')
		*str = ft_strjoinf(*str, ft_ultoa_base(va_arg(vl, unsigned long long),
		16), 3);
	else if (stock->type == 'X')
		*str = ft_strjoinf(*str,
		ft_toupperstr(ft_ultoa_base(va_arg(vl, unsigned long long), 16)), 3);
	convertprecision(str, stock, vl);
}

void	convertinstrwsize(char **str, t_check *stock, va_list vl)
{
	if (ft_strcmp(stock->size, "l"))
		convertinstrwsize2(str, stock, vl);
	else if (stock->type == 'd' || stock->type == 'i')
		*str = ft_strjoinf(*str, ft_ltoa(va_arg(vl, long)), 3);
	else if (stock->type == 'u')
		*str = ft_strjoinf(*str, ft_ultoa_base(va_arg(vl, unsigned long), 10),
		3);
	else if (stock->type == 'b')
		*str = ft_strjoinf(*str, ft_ultoa_base(va_arg(vl, unsigned long), 2),
		3);
	else if (stock->type == 'o')
		*str = ft_strjoinf(*str, ft_ultoa_base(va_arg(vl, unsigned long), 8),
		3);
	else if (stock->type == 'x')
		*str = ft_strjoinf(*str, ft_ultoa_base(va_arg(vl, unsigned long), 16),
		3);
	else if (stock->type == 'X')
		*str = ft_strjoinf(*str,
		ft_toupperstr(ft_ultoa_base(va_arg(vl, unsigned long), 16)), 3);
	convertprecision(str, stock, vl);
}
