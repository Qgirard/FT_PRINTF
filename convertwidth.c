/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertwidth.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:47:23 by qgirard           #+#    #+#             */
/*   Updated: 2019/01/03 17:44:25 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	convertwidth2(char **str, t_check *stock)
{
	char	*tmp;
	char	*ptr;
	int		i;

	i = 0;
	ptr = ft_reallocstr(NULL, stock->width - stock->sizetype);
	while (i < stock->width - stock->sizetype)
		ptr[i++] = ((stock->option == '0' || stock->option2 == '0') &&
		(stock->type != 's' && stock->type != 'c')) ? '0' : ' ';
	i = ft_strlen(*str) - stock->sizetype;
	tmp = ft_strsub(*str, i, stock->sizetype);
	while ((*str)[i])
		(*str)[i++] = '\0';
	*str = ft_strjoinf(*str, ptr, 3);
	*str = ft_strjoinf(*str, tmp, 3);
}

void	convertwidth(char **str, t_check *stock)
{
	char	*tmp;
	int		i;

	i = 0;
	stock->sizetype = ft_strlen(*str) - stock->lenstr;
	if (stock->sizetype >= stock->width || stock->prec >= stock->width)
		stock->width = 0;
	else
	{
		if (stock->option == '-' || stock->option2 == '-')
		{
			tmp = ft_reallocstr(NULL, stock->width - stock->sizetype);
			while (i < stock->width - stock->sizetype)
				tmp[i++] = ((stock->option == '0' || stock->option2 == '0') &&
				(stock->type != 's' && stock->type != 'c')) ? '0' : ' ';
			*str = ft_strjoinf(*str, tmp, 3);
		}
		else
			convertwidth2(str, stock);
	}
}
