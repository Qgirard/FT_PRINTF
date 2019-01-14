/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:11:40 by qgirard           #+#    #+#             */
/*   Updated: 2019/01/14 13:55:37 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		checkpercent(const char **format, char **str)
{
	if (ft_strchr(*format, '%'))
	{
		if (!((*str) = ft_strjoinf(*str, ft_strsub(*format, 0,
		ft_strlen(*format) - ft_strlen(ft_strchr(*format, '%'))), 3)))
			return (0);
		*format = ft_strchr(*format, '%');
	}
	else
	{
		if (!((*str) = ft_strjoinf(*str, ft_strsub(*format, 0,
		ft_strlen(*format)), 3)))
			return (0);
		return (0);
	}
	return (1);
}

int		ft_printf(const char *format, ...)
{
	va_list	vl;
	int		i;
	char	*str;
	t_check *stock;

	if (!(stock = (t_check *)malloc(sizeof(t_check))))
		return (0);
	stock->size = NULL;
	va_start(vl, format);
	if (!(str = ft_strnew(0)))
		return (0);
	while (checkpercent(&format, &str))
	{
		if (!checkoptions(&format, &stock))
			return (freerror(&str, &stock, vl));
		if (!convertinstr(&str, &stock, vl))
			return (freerror(&str, &stock, vl));
		ft_strdel(&stock->size);
	}
	va_end(vl);
	ft_putstr(str);
	i = (stock->exception == 1) ? ft_strlen(str) - 1 : ft_strlen(str);
	free(stock);
	ft_strdel(&str);
	return (i);
}
