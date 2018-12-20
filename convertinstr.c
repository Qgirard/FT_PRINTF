/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertinstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:12:29 by qgirard           #+#    #+#             */
/*   Updated: 2018/12/20 19:08:45 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	convertprecision(char **str, t_check *stock)
{
	char	*tmp;
	char	*ptr;
	int		i;

	i = 0;
	stock->sizetype = ft_strlen(*str) - stock->lenstr;
	if (stock->precision)
	{
		ptr = ft_reallocstr(NULL, stock->precision - stock->sizetype);
		while (i < stock->precision - stock->sizetype)
			ptr[i++] = '0';
		i = ft_strlen(*str) - stock->sizetype;
		tmp = ft_strsub(*str, i, stock->sizetype);
		while ((*str)[i])
			(*str)[i++] = '\0';
		*str = ft_strjoinf(*str, ptr, 3);
		*str = ft_strjoinf(*str, tmp, 3);
	}
	convertwidth(str, stock);
}

void	convertinstr2(char **str, t_check *stock, va_list vl)
{
	if (stock->type == '%')
		*str = ft_strjoinf(*str, "%", 1);
	else if (stock->type == 'd' || stock->type == 'i')
		*str = ft_strjoinf(*str, ft_itoa(va_arg(vl, int)), 3);
	else if (stock->type == 'u')
		*str = ft_strjoinf(*str, ft_utoa_base(va_arg(vl, unsigned int), 10), 3);
	else if (stock->type == 'b')
		*str = ft_strjoinf(*str, ft_itoa_base(va_arg(vl, int), 2), 3);
	else if (stock->type == 'c')
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
	convertprecision(str, stock);
}

void	convertinstr(char **str, t_check *stock, va_list vl)
{
	stock->lenstr = ft_strlen(*str);
	if (stock->option == '#' || stock->option2 == '#')
	{
		if (stock->type == 'x')
			*str = ft_strjoinf(*str, "0x", 1);
		if (stock->type == 'X')
			*str = ft_strjoinf(*str, "0X", 1);
		if (stock->type == 'o')
			*str = ft_strjoinf(*str, "0", 1);
	}
	convertinstr2(str, stock, vl);
}
