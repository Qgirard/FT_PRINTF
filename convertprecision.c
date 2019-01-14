/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertprecision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:02:21 by qgirard           #+#    #+#             */
/*   Updated: 2019/01/14 18:13:36 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convertprecisionforhexaprime(char **str, t_check **stock, char *ptr,
		char *tmp)
{
	int		i;

	ft_strdel(str);
	if (!(*str = ft_strdup(ptr)))
		return (0);
	i = 0;
	while ((unsigned long)i++ < (*stock)->prec - ft_strlen(tmp))
	{
		if (!(*str = ft_strjoinf(*str, "0", 1)))
			return (0);
	}
	return (1);
}

int		convertprecisionerr(char **tmp, char **ptr, int rm)
{
	if (rm == 1 || rm == 3)
		ft_strdel(tmp);
	if (rm == 2 || rm == 3)
		ft_strdel(ptr);
	return (0);
}

int		convertprecisionforhexa(char **str, t_check **stock)
{
	char	*tmp;
	char	*ptr;

	(*stock)->sizetype = ft_strlen(*str) - (*stock)->lenstr;
	if ((*stock)->prec && (*stock)->prec != -1 &&
	(*stock)->prec > (*stock)->sizetype)
	{
		if (!(tmp = ft_strsub(*str, (*stock)->lenstr, ft_strlen(*str))))
			return (0);
		if (!(ptr = (((*stock)->option == '#' || (*stock)->option2 == '#') &&
		ft_strcmp(tmp, "0")) ? ft_strsub(*str, 0, (*stock)->lenstr + 2) :
		ft_strsub(*str, 0, (*stock)->lenstr)))
			return (convertprecisionerr(&tmp, &ptr, 1));
		ft_strdel(&tmp);
		if (!(tmp = ft_strsub(*str, ft_strlen(ptr), ft_strlen(*str))))
			return (convertprecisionerr(&tmp, &ptr, 2));
		if (!convertprecisionforhexaprime(str, stock, ptr, tmp))
			return (0);
		if (!(*str = ft_strjoinf(*str, tmp, 3)))
			return (convertprecisionerr(&tmp, &ptr, 3));
		ft_strdel(&ptr);
	}
	return (convertwidth(str, stock));
}

int		convert0precisionex(char **str, t_check **stock, char *tmp, char *ptr)
{
	if (ft_strcmp(tmp, "00") && ((*stock)->type == 'x' ||
	(*stock)->type == 'X' || (*stock)->type == 'o' || (((*stock)->type == 'd' ||
	(*stock)->type == 'i') && !ft_strcmp(tmp, "0"))) && (*stock)->prec > -1)
	{
		ft_strdel(str);
		if (!(*str = ft_strdup(ptr)))
			return (0);
	}
	if ((*stock)->type == 'o' && !ft_strcmp(tmp, "00"))
	{
		ft_strdel(str);
		if (!(*str = ft_strdup(ptr)))
			return (0);
		if (!(*str = ft_strjoinf(*str, "0", 1)))
			return (0);
	}
	return (1);
}

int		convert0precision(char **str, t_check **stock, va_list vl)
{
	char	*tmp;
	char	*ptr;

	if ((*stock)->prec == 0)
	{
		if (!(ptr = ft_strsub(*str, 0, (*stock)->lenstr)))
			return (0);
		if (!(tmp = ft_strsub(*str, (*stock)->lenstr, ft_strlen(*str))))
		{
			ft_strdel(&ptr);
			return (0);
		}
		if (!convert0precisionex(str, stock, tmp, ptr))
			return (convertprecisionerr(&tmp, &ptr, 3));
		ft_strdel(&ptr);
		ft_strdel(&tmp);
		convertwidth(str, stock);
	}
	else
		return (((*stock)->type == 'x' || (*stock)->type == 'X') ?
		convertprecisionforhexa(str, stock) : convertprecision(str, stock, vl));
			return (1);
}