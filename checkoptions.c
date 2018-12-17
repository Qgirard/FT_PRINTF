/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkoptions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:01:18 by qgirard           #+#    #+#             */
/*   Updated: 2018/12/17 19:56:26 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	checklen(const char **format, t_check **stock)
{
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
	*format = ft_strchr(*format, (*stock)->option);
	checklen(format, stock);
}
