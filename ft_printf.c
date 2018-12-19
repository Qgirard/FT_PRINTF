/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:11:40 by qgirard           #+#    #+#             */
/*   Updated: 2018/12/19 18:29:03 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		checkpercent(const char **format, char **str)
{
	if (ft_strchr(*format, '%'))
	{
		(*str) = ft_strjoinf(*str, ft_strsub(*format, 0, ft_strlen(*format) -
		ft_strlen(ft_strchr(*format, '%'))), 3);
		*format = ft_strchr(*format, '%');
	}
	else
	{
		(*str) = ft_strjoinf(*str, ft_strsub(*format, 0,
		ft_strlen(*format)), 3);
		return (0);
	}
	return (1);
}

int		ft_printf(const char *format, ...)
{
	va_list	vl;
	char	*str;
	t_check *stock;

	if (!(stock = (t_check *)malloc(sizeof(t_check))))
		return (0);
	stock->size = NULL;
	va_start(vl, format);
	str = ft_strnew(0);
	while (checkpercent(&format, &str))
	{
		checkoptions(&format, &stock);
		convertinstr(&str, stock, vl);
		ft_strdel(&stock->size);
	}
	va_end(vl);
	free(stock);
	ft_putstr(str);
	ft_strdel(&str);
	return (1);
}
