/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkoptions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:01:18 by qgirard           #+#    #+#             */
/*   Updated: 2018/12/20 19:05:10 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	checksize(const char **format, t_check **stock)
{
	if ((*format)[0] == 'l')
	{
		if ((*format)[1] == 'l')
			(*stock)->size = ft_strdup("ll");
		else
			(*stock)->size = ft_strdup("l");
		*format = *format + ft_strlen((*stock)->size);
	}
	else if ((*format)[0] == 'h')
	{
		if ((*format)[1] == 'h')
			(*stock)->size = ft_strdup("hh");
		else
			(*stock)->size = ft_strdup("h");
		*format = *format + ft_strlen((*stock)->size);
	}
	else if ((*format)[0] == 'L')
	{
		(*stock)->size = ft_strdup("L");
		*format = *format + 1;
	}
	printf("SIZE = %s\n", (*stock)->size);
	checktype(format, stock);
}

void	checkprecision(const char **format, t_check **stock)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strnew(0);
	if ((*format)[i] == '.')
	{
		i++;
		while (ft_isdigit((*format)[i]) == 1)
		{
			tmp = ft_strjoinf(tmp, (char *)&(*format)[i], 1);
			i++;
		}
		(*stock)->precision = ft_atoi(tmp);
		*format = *format + i;
	}
	else
		(*stock)->precision = 0;
	ft_strdel(&tmp);
	printf("PRECISION = %d\n", (*stock)->precision);
	checksize(format, stock);
}

void	checkwidth(const char **format, t_check **stock)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strnew(0);
	while (ft_isdigit((*format)[i]) == 1)
	{
		tmp = ft_strjoinf(tmp, (char *)&(*format)[i], 1);
		i++;
	}
	if (i > 0)
		(*stock)->width = ft_atoi(tmp);
	else
		(*stock)->width = 0;
	*format = *format + i;
	ft_strdel(&tmp);
	printf("WIDTH = %d\n", (*stock)->width);
	checkprecision(format, stock);
}

void	checkoption2(const char **format, t_check **stock)
{
	if ((*format)[0] == '#')
		(*stock)->option2 = '#';
	else if ((*format)[0] == '0')
		(*stock)->option2 = '0';
	else if ((*format)[0] == '-')
		(*stock)->option2 = '-';
	else if ((*format)[0] == '+')
		(*stock)->option2 = '+';
	else if ((*format)[0] == ' ')
		(*stock)->option2 = ' ';
	else
		(*stock)->option2 = 0;
	if ((*stock)->option2 != 0)
		*format = *format + 1;
	printf("OPTION = %d\n", (*stock)->option);
	printf("OPTION2 = %d\n", (*stock)->option2);
	checkwidth(format, stock);
}

void	checkoptions(const char **format, t_check **stock)
{
	if ((*format)[1] == '#')
		(*stock)->option = '#';
	else if ((*format)[1] == '0')
		(*stock)->option = '0';
	else if ((*format)[1] == '-')
		(*stock)->option = '-';
	else if ((*format)[1] == '+')
		(*stock)->option = '+';
	else if ((*format)[1] == ' ')
		(*stock)->option = ' ';
	else
		(*stock)->option = 0;
	if ((*stock)->option != 0)
		*format = *format + 2;
	else
		*format = *format + 1;
	checkoption2(format, stock);
}
