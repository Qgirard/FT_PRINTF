/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertinstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:12:29 by qgirard           #+#    #+#             */
/*   Updated: 2018/12/19 19:34:28 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convertinstr2(char **str, t_check *stock, va_list vl)
{
	if (stock->type == 'd' || stock->type == 'i')
		*str = ft_strjoinf(*str, ft_itoa(va_arg(vl, int)), 3);
	else if (stock->type == 'u')
		*str = ft_strjoinf(*str, ft_utoa_base(va_arg(vl, unsigned int), 10), 3);
	else if(stock->type == 'c')
		*str = ft_strjoinf(*str, ft_tochartostr(va_arg(vl, int)), 3);
	else if (stock->type == 's')
		*str = ft_strjoinf(*str, va_arg(vl, char *), 1);
	else if (stock->type == 'o')
		*str = ft_strjoinf(*str, ft_utoa_base(va_arg(vl, unsigned int), 8), 3);
	else if (stock->type == 'x')
		*str = ft_strjoinf(*str, ft_utoa_base(va_arg(vl, unsigned int), 16), 3);
	else if (stock->type == 'X')
		*str = ft_strjoinf(*str,
		ft_toupperstr(ft_utoa_base(va_arg(vl, unsigned int), 16)), 3);
}

void	convertinstr(char **str, t_check *stock, va_list vl)
{
	if (stock->option == '#' || stock->option2 == '#')
	{
		if (stock->type == 'x')
			*str = ft_strjoinf(*str, ft_strjoinf("0x",
			ft_utoa_base(va_arg(vl, unsigned int), 16), 2), 3);
		else if (stock->type == 'X')
			*str = ft_strjoinf(*str, ft_strjoinf("0X",
			ft_toupperstr(ft_utoa_base(va_arg(vl, unsigned int), 16)), 2), 3);
		else if (stock->type == 'o')
			*str = ft_strjoinf(*str, ft_strjoinf("0",
			ft_utoa_base(va_arg(vl, unsigned int), 8), 2), 3);
	}
	else
		convertinstr2(str, stock, vl);
}
