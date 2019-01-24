/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:56:26 by qgirard           #+#    #+#             */
/*   Updated: 2019/01/24 17:17:21 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		majexception(char **str, t_check **stock, va_list vl)
{
	if ((*stock)->type == 'D')
		*str = ft_strjoinf(*str, ft_ltoa(va_arg(vl, long)), 3);
	else if ((*stock)->type == 'U')
		*str = ft_strjoinf(*str, ft_ultoa_base(va_arg(vl, unsigned long),
		10), 3);
	else if ((*stock)->type == 'O')
		*str = ft_strjoinf(*str, ft_ultoa_base(va_arg(vl, unsigned long),
		8), 3);
	if (!*str)
		return (0);
	return (checksignerror(str, stock, vl));
}

int		exception(char **str, t_check **stock, va_list vl)
{
	if ((*stock)->type == 'c')
	{
		(*stock)->prec = -1;
		if ((*stock)->charzero == 0)
		{
			(*stock)->exception = 1;
			if (!(*str = ft_strjoinf(*str, "^@", 1)))
				return (0);
		}
		else
			*str = ft_strjoinf(*str, ft_tochartostr((*stock)->charzero), 3);
	}
	if ((*stock)->prec != -1 && (*stock)->prec < (*stock)->width &&
	(*stock)->zero == '0')
		(*stock)->zero = 0;
	return (convert0precision(str, stock, vl));
}
