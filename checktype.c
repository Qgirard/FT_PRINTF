/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checktype.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 14:53:34 by qgirard           #+#    #+#             */
/*   Updated: 2018/12/20 19:07:54 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	checktype(const char **format, t_check **stock)
{
	if ((*format)[0] == 'c')
		(*stock)->type = 'c';
	else if ((*format)[0] == 's')
		(*stock)->type = 's';
	else if ((*format)[0] == 'p')
		(*stock)->type = 'p';
	else if ((*format)[0] == 'd')
		(*stock)->type = 'd';
	else if ((*format)[0] == 'i')
		(*stock)->type = 'i';
	else if ((*format)[0] == 'o')
		(*stock)->type = 'o';
	else if ((*format)[0] == 'u')
		(*stock)->type = 'u';
	else if ((*format)[0] == 'x')
		(*stock)->type = 'x';
	else if ((*format)[0] == 'X')
		(*stock)->type = 'X';
	else if ((*format)[0] == 'f')
		(*stock)->type = 'f';
	else if ((*format)[0] == '%' || (*format)[0] == 'b')
		(*stock)->type = ((*format)[0] == '%') ? '%' : 'b';
	else
		(*stock)->type = 0;
	printf("TYPE = %d\n", (*stock)->type);
	*format = *format + 1;
}
