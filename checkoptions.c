/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkoptions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:01:18 by qgirard           #+#    #+#             */
/*   Updated: 2019/01/14 15:34:22 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		checkprecision(const char **format, t_check **stock)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!(tmp = ft_strnew(0)))
		return (0);
	if ((*format)[i] == '.')
	{
		i++;
		while (ft_isdigit((*format)[i]) == 1)
		{
			if (!(tmp = ft_strjoinf(tmp, (char *)&(*format)[i], 1)))
			{
				ft_strdel(&tmp);
				return (0);
			}
			i++;
		}
		(*stock)->prec = ft_atoi(tmp);
		*format = *format + i;
	}
	else
		(*stock)->prec = -1;
	ft_strdel(&tmp);
	return (checksize(format, stock));
}

int		checkwidth(const char **format, t_check **stock)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!(tmp = ft_strnew(0)))
		return (0);
	while (ft_isdigit((*format)[i]) == 1)
	{
		if (!(tmp = ft_strjoinf(tmp, (char *)&(*format)[i], 1)))
		{
			ft_strdel(&tmp);
			return (0);
		}
		i++;
	}
	if (i > 0)
		(*stock)->width = ft_atoi(tmp);
	else
		(*stock)->width = 0;
	*format = *format + i;
	ft_strdel(&tmp);
	return (checkprecision(format, stock));
}

void	checkmoreoptions(const char **format, t_check **stock)
{
	if ((*format)[0] == '+')
	{
		(*stock)->option2 = '+';
		while ((*format)[1] == '+')
			*format = *format + 1;
	}
	else if ((*format)[0] == ' ')
	{
		(*stock)->option2 = ' ';
		while ((*format)[1] == ' ')
			*format = *format + 1;
	}
}

int		checkoption2(const char **format, t_check **stock)
{
	if ((*format)[0] == '#')
		(*stock)->option2 = '#';
	else if ((*format)[0] == '0' && (*stock)->option != '-')
		(*stock)->option2 = '0';
	else if ((*format)[0] == '-')
	{
		(*stock)->option2 = '-';
		if ((*stock)->option == '0')
			(*stock)->option = 0;
	}
	else if ((*format)[0] == '+' || (*format)[0] == ' ')
		checkmoreoptions(format, stock);
	else
		(*stock)->option2 = 0;
	if ((*stock)->option2 != 0)
		*format = *format + 1;
	return (checkwidth(format, stock));
}

int		checkoptions(const char **format, t_check **stock)
{
	if ((*format)[1] == '#')
		(*stock)->option = '#';
	else if ((*format)[1] == '0')
		(*stock)->option = '0';
	else if ((*format)[1] == '-')
		(*stock)->option = '-';
	else if ((*format)[1] == '+')
	{
		(*stock)->option = '+';
		while ((*format)[2] == '+')
			*format = *format + 1;
	}
	else if ((*format)[1] == ' ')
	{
		(*stock)->option = ' ';
		while ((*format)[2] == ' ')
			*format = *format + 1;
	}
	else
		(*stock)->option = 0;
	if ((*stock)->option != 0)
		*format = *format + 2;
	else
		*format = *format + 1;
	return (checkoption2(format, stock));
}
