/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:12:04 by qgirard           #+#    #+#             */
/*   Updated: 2019/01/14 15:53:46 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_check
{
	int		option;
	int		option2;
	int		width;
	int		prec;
	char	*size;
	int		type;
	int		lenstr;
	int		sizetype;
	int		exception;
	int		sign;
}				t_check;

int				ft_printf(const char *format, ...);
int				checkoptions(const char **format, t_check **stock);
int				checksize(const char **format, t_check **stock);
int				convertinstr(char **str, t_check **stock, va_list vl);
int				convertwidth(char **str, t_check **stock);
int				convertinstrwsize(char **str, t_check **stock, va_list vl);
int				convertprecision(char **str, t_check **stock, va_list vl);
int				checksignerror(char **str, t_check **stock, va_list vl);
int				convert0precision(char **str, t_check **stock, va_list vl);
int				exception(char **str, t_check **stock, va_list vl);
int				convertprecisionerr(char **tmp, char **ptr, int rm);
int				freerror(char **str, t_check **stock, va_list vl);

#endif
