/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checktype.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 14:53:34 by qgirard           #+#    #+#             */
/*   Updated: 2019/01/11 18:26:13 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		checktype(const char **format, t_check **stock)
{
	if ((*format)[0] == 'c')
		(*stock)->type = 'c';
	else if ((*format)[0] == 's')
		(*stock)->type = 's';
	else if ((*format)[0] == 'p')
		(*stock)->type = 'p';
	else if ((*format)[0] == 'd' || (*format)[0] == 'D')
		(*stock)->type = 'd';
	else if ((*format)[0] == 'i')
		(*stock)->type = 'i';
	else if ((*format)[0] == 'o')
		(*stock)->type = 'o';
	else if ((*format)[0] == 'u' || (*format)[0] == 'U')
		(*stock)->type = 'u';
	else if ((*format)[0] == 'x' || (*format)[0] == 'X')
		(*stock)->type = ((*format)[0] == 'x') ? 'x' : 'X';
	else if ((*format)[0] == 'f')
		(*stock)->type = 'f';
	else if ((*format)[0] == '%' || (*format)[0] == 'b')
		(*stock)->type = ((*format)[0] == '%') ? '%' : 'b';
	else
		(*stock)->type = 0;
	*format = *format + 1;
	return (1);
}

int		checklittlesize(const char **format, t_check **stock)
{
	if ((*format)[0] == 'h')
	{
		if ((*format)[1] == 'h')
		{
			if (!((*stock)->size = ft_strdup("hh")))
				return (0);
		}
		else
		{
			if (!((*stock)->size = ft_strdup("h")))
				return (0);
		}
		*format = *format + ft_strlen((*stock)->size);
	}
	else if ((*format)[0] == 'L')
	{
		if (!((*stock)->size = ft_strdup("L")))
			return (0);
		*format = *format + 1;
	}
	return (checktype(format, stock));
}

int		checksize(const char **format, t_check **stock)
{
	if ((*format)[0] == 'l' || (*format)[0] == 'j' || (*format)[0] == 'z')
	{
		if ((*format)[1] == 'l')
		{
			if (!((*stock)->size = ft_strdup("ll")))
				return (0);
		}
		else
		{
			if (!((*stock)->size = ft_strdup("l")))
				return (0);
		}
		*format = *format + ft_strlen((*stock)->size);
	}
	return (checklittlesize(format, stock));
}
