/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freerror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:07:57 by qgirard           #+#    #+#             */
/*   Updated: 2019/01/11 17:49:41 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		freerror(char **str, t_check **stock, va_list vl)
{
	if (*str)
		ft_strdel(str);
	if ((*stock)->size)
		ft_strdel(&((*stock)->size));
	free(*stock);
	va_end(vl);
	return (0);
}
