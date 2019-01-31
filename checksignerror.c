/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksignerror.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:28:30 by qgirard           #+#    #+#             */
/*   Updated: 2019/01/31 20:09:44 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		checksignerror2(char **str, t_check **stock)
{
	char	*ptr;

	if (!(ptr = ft_strsub(*str, 0, (*stock)->lenstr)))
		return (0);
	ft_strdel(str);
	if (!(*str = ft_strdup(ptr)))
	{
		ft_strdel(&ptr);
		return (0);
	}
	if (!(*str = ft_strjoinf(*str, "0", 1)))
	{
		ft_strdel(&ptr);
		return (0);
	}
	ft_strdel(&ptr);
	return (1);
}

int		errorcase(char **str, t_check **stock, char *tmp, char *ptr)
{
	if (!(ptr = ft_strsub(*str, 0, (*stock)->lenstr)))
		return (0);
	ft_strdel(str);
	if (!(*str = ft_strdup(ptr)))
		return (0);
	if (!(*str = ft_strjoinf(*str, tmp + 1, 1)))
		return (0);
	(*stock)->sign = '-';
	return (1);
}

int		checksignerror(char **str, t_check **stock, va_list vl,
		t_excep **current)
{
	char	*tmp;

	(*stock)->sign = 0;
	if (!(tmp = ft_strsub(*str, (*stock)->lenstr, ft_strlen(*str))))
		return (0);
	if (tmp[0] == '-')
		(*stock)->sign = '-';
	if (tmp[1] == '-' && ((*stock)->plus == '+' || (*stock)->space == ' '))
	{
		if (!errorcase(str, stock, tmp, NULL))
		{
			ft_strdel(&tmp);
			return (0);
		}
	}
	else if ((*stock)->diez == '#' &&
	(!ft_strcmp(tmp, "0x0") || !ft_strcmp(tmp, "0X0")))
	{
		if (!checksignerror2(str, stock))
			return (0);
	}
	ft_strdel(&tmp);
	return (exception(str, stock, vl, current));
}
