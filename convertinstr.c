/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertinstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:12:29 by qgirard           #+#    #+#             */
/*   Updated: 2019/01/14 13:36:21 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convertinstrwint(char **str, t_check **stock, va_list vl)
{
	if ((*stock)->type == 'd' || (*stock)->type == 'i')
		*str = ft_strjoinf(*str, ft_itoa(va_arg(vl, int)), 3);
	else if ((*stock)->type == 'u')
		*str = ft_strjoinf(*str, ft_utoa_base(va_arg(vl, unsigned int),
		10), 3);
	else if ((*stock)->type == 'b')
		*str = ft_strjoinf(*str, ft_utoa_base(va_arg(vl, unsigned int),
		2), 3);
	else if ((*stock)->type == 'c')
		*str = ft_strjoinf(*str, ft_tochartostr(va_arg(vl, int)), 3);
	else if ((*stock)->type == 's' && (*stock)->prec == -1)
		*str = ft_strjoinf(*str, va_arg(vl, char *), 1);
	else if ((*stock)->type == 'p')
		*str = ft_strjoinf(*str, ft_ultoa_base(va_arg(vl, unsigned long),
		16), 3);
	else if ((*stock)->type == 'o')
		*str = ft_strjoinf(*str, ft_utoa_base(va_arg(vl, unsigned int), 8), 3);
	else if ((*stock)->type == 'x')
		*str = ft_strjoinf(*str, ft_utoa_base(va_arg(vl, unsigned int), 16), 3);
	else if ((*stock)->type == 'X')
		*str = ft_strjoinf(*str,
		ft_toupperstr(ft_utoa_base(va_arg(vl, unsigned int), 16)), 3);
	if (!*str)
		return (0);
	return (checksignerror(str, stock, vl));
}

int		convertinstrwoptions(char **str, t_check **stock, va_list vl)
{
	if ((*stock)->option == '#' || (*stock)->option2 == '#' ||
	(*stock)->type == 'p')
	{
		if ((*stock)->type == 'x' || (*stock)->type == 'p')
			*str = ft_strjoinf(*str, "0x", 1);
		else if ((*stock)->type == 'X')
			*str = ft_strjoinf(*str, "0X", 1);
		else if ((*stock)->type == 'o')
			*str = ft_strjoinf(*str, "0", 1);
		if (!*str)
			return (0);
	}
	if ((*stock)->size == NULL || !ft_strcmp((*stock)->size, "h") ||
	!ft_strcmp((*stock)->size, "hh"))
		return (convertinstrwint(str, stock, vl));
	else if ((*stock)->size != NULL)
		return (convertinstrwsize(str, stock, vl));
	return (1);
}

int		convertinstr(char **str, t_check **stock, va_list vl)
{
	(*stock)->lenstr = ft_strlen(*str);
	if ((*stock)->type == '%')
	{
		if (!(*str = ft_strjoinf(*str, "%", 1)))
			return (0);
	}
	else if ((*stock)->option == '+' || (*stock)->option2 == '+')
	{
		if (!(*str = ft_strjoinf(*str, "+", 1)))
			return (0);
	}
	else if ((*stock)->option == ' ' || (*stock)->option2 == ' ')
	{
		if (!(*str = ft_strjoinf(*str, " ", 1)))
			return (0);
	}
	return (convertinstrwoptions(str, stock, vl));
}
