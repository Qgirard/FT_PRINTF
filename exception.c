/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 13:56:26 by qgirard           #+#    #+#             */
/*   Updated: 2019/01/14 17:33:16 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		exception(char **str, t_check **stock, va_list vl)
{
	char	*tmp;

	if ((*stock)->type == 'c')
	{
		if (!(tmp = ft_strsub(*str, (*stock)->lenstr, ft_strlen(*str))))
			return (0);
		if (!ft_strcmp(tmp, "\0"))
		{
			if (!(*str = ft_strjoinf(*str, "^@", 1)))
				return (0);
			(*stock)->exception = 1;
		}
		ft_strdel(&tmp);
	}
	if ((*stock)->prec != -1 && (*stock)->prec < (*stock)->width &&
	(*stock)->option == '0')
		(*stock)->option = 0;
	if ((*stock)->prec != -1 && (*stock)->prec < (*stock)->width &&
	(*stock)->option2 == '0')
		(*stock)->option2 = 0;
	return (convert0precision(str, stock, vl));
}
