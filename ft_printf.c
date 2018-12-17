/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:11:40 by qgirard           #+#    #+#             */
/*   Updated: 2018/12/17 19:36:23 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	checktype(char **str, char *type, va_list vl)
{
	if (!ft_strncmp(type, "%%", 2))
		*str = ft_strjoinf(*str, "%", 1);
	else if (!ft_strncmp(type, "%d", 2) || !ft_strncmp(type, "%i", 2))
		*str = ft_strjoinf(*str, ft_itoa(va_arg(vl, int)), 3);
	else if (!ft_strncmp(type, "%s", 2))
		*str = ft_strjoinf(*str, va_arg(vl, char *), 1);
	else if (!ft_strncmp(type, "%o", 2))
		*str = ft_strjoinf(*str, ft_itoa_base(va_arg(vl, int), 8), 3);
	else if (!ft_strncmp(type, "%x", 2))
		*str = ft_strjoinf(*str, ft_itoa_base(va_arg(vl, int), 16), 3);
	else if (!ft_strncmp(type, "%X", 2))
		*str = ft_strjoinf(*str, ft_toupperstr(ft_itoa_base(va_arg(vl, int),
		16)), 3);
}

void	checknext(const char **format, char **str, va_list vl)
{
	char	*type;

	if (ft_strchr(*format, '\n'))
	{
		type = ft_strsub(*format, 0, ft_strlen(*format) -
		ft_strlen(ft_strchr(*format, '\n')));
		*format = ft_strchr(*format, '\n');
	}
	else if (ft_strchr(*format, ' '))
	{
		type = ft_strsub(*format, 0, ft_strlen(*format) -
		ft_strlen(ft_strchr(*format, ' ')));
		*format = ft_strchr(*format, ' ');
	}
	else
	{
		type = ft_strsub(*format, 0, ft_strlen(*format) -
		ft_strlen(ft_strchr(*format, '\0')));
		*format = ft_strchr(*format, '\0');
	}
	checktype(str, type, vl);
	ft_strdel(&type);
}

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

	if (!(stock = (t_check *)ft_memalloc(sizeof(t_check))))
		return (0);
	va_start(vl, format);
	str = ft_strnew(0);
	while (checkpercent(&format, &str))
	{
		checkoptions(&format, &stock);
		checknext(&format, &str, vl);
	}
	va_end(vl);
	ft_putstr(str);
	ft_strdel(&str);
	return (1);
}
