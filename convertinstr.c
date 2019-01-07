/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertinstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:12:29 by qgirard           #+#    #+#             */
/*   Updated: 2019/01/07 18:20:50 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convertprecision(char **str, t_check *stock, va_list vl)
{
	char	*tmp;
	char	*ptr;
	int		i;

	i = 0;
	stock->sizetype = ((stock->option == '+' || stock->option == '+') ||
	(stock->option == ' ' || stock->option2 == ' ')) ?
	ft_strlen(*str) - stock->lenstr - 1 : ft_strlen(*str) - stock->lenstr;
	if (stock->prec && stock->prec > stock->sizetype &&
	stock->type != 's')
	{
		ptr = ft_reallocstr(NULL, stock->prec - stock->sizetype);
		while (i < stock->prec - stock->sizetype)
			ptr[i++] = '0';
		i = ft_strlen(*str) - stock->sizetype;
		tmp = ft_strsub(*str, i, stock->sizetype);
		while ((*str)[i])
			(*str)[i++] = '\0';
		*str = ft_strjoinf(*str, ptr, 3);
		*str = ft_strjoinf(*str, tmp, 3);
	}
	else if (stock->prec && stock->prec > stock->sizetype && stock->type == 's')
		*str = ft_strjoinf(*str, ft_strsub(va_arg(vl, char *), 0,
		stock->prec), 3);
	convertwidth(str, stock);
}

void	checksignerror(char **str, t_check *stock, va_list vl)
{
	char	*tmp;
	char	*ptr;

	tmp = ft_strsub(*str, stock->lenstr + 1, ft_strlen(*str));
	if (tmp[0] == '-' && ((stock->option == '+' || stock->option2 == '+') ||
	(stock->option == ' ' || stock->option2 == ' ')))
	{
		ptr = ft_strsub(*str, 0, stock->lenstr);
		ft_strdel(str);
		*str = ft_strdup(ptr);
		*str = ft_strjoinf(*str, tmp, 1);
		ft_strdel(&ptr);
	}
	ft_strdel(&tmp);
	convertprecision(str, stock, vl);
}

void	convertinstr2(char **str, t_check *stock, va_list vl)
{
	if (stock->type == 'd' || stock->type == 'i')
		*str = ft_strjoinf(*str, ft_itoa(va_arg(vl, int)), 3);
	else if (stock->type == 'u')
		*str = ft_strjoinf(*str, ft_utoa_base(va_arg(vl, unsigned int), 10), 3);
	else if (stock->type == 'b')
		*str = ft_strjoinf(*str, ft_utoa_base(va_arg(vl, unsigned int), 2), 3);
	else if (stock->type == 'c')
		*str = ft_strjoinf(*str, ft_tochartostr(va_arg(vl, int)), 3);
	else if (stock->type == 's' && !stock->prec)
		*str = ft_strjoinf(*str, va_arg(vl, char *), 1);
	else if (stock->type == 'p')
		*str = ft_strjoinf(*str, va_arg(vl, void *), 1);
	else if (stock->type == 'o')
		*str = ft_strjoinf(*str, ft_utoa_base(va_arg(vl, unsigned int), 8), 3);
	else if (stock->type == 'x')
		*str = ft_strjoinf(*str, ft_utoa_base(va_arg(vl, unsigned int), 16), 3);
	else if (stock->type == 'X')
		*str = ft_strjoinf(*str,
		ft_toupperstr(ft_utoa_base(va_arg(vl, unsigned int), 16)), 3);
	checksignerror(str, stock, vl);
}

void	convertinstr(char **str, t_check *stock, va_list vl)
{
	stock->lenstr = ft_strlen(*str);
	if (stock->type == '%')
		*str = ft_strjoinf(*str, "%", 1);
	else if (stock->option == '#' || stock->option2 == '#' || stock->type == 'p')
	{
		if (stock->type == 'x' || stock->type == 'p')
			*str = ft_strjoinf(*str, "0x", 1);
		if (stock->type == 'X')
			*str = ft_strjoinf(*str, "0X", 1);
		if (stock->type == 'o')
			*str = ft_strjoinf(*str, "0", 1);
	}
	else if (stock->option == '+' || stock->option2 == '+')
		*str = ft_strjoinf(*str, "+", 1);
	else if (stock->option == ' ' || stock->option2 == ' ')
		*str = ft_strjoinf(*str, " ", 1);
	if (stock->size == NULL || !ft_strcmp(stock->size, "h") ||
	!ft_strcmp(stock->size, "hh"))
		convertinstr2(str, stock, vl);
	else if (stock->size != NULL)
		convertinstrwsize(str, stock, vl);
}
