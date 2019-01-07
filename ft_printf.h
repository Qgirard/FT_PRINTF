/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:12:04 by qgirard           #+#    #+#             */
/*   Updated: 2019/01/07 17:44:30 by qgirard          ###   ########.fr       */
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
}				t_check;

int				ft_printf(const char *format, ...);
void			checkoptions(const char **format, t_check **stock);
void			checktype(const char **format, t_check **stock);
void			convertinstr(char **str, t_check *stock, va_list vl);
void			convertwidth(char **str, t_check *stock);
void			convertinstrwsize(char **str, t_check *stock, va_list vl);
void			convertprecision(char **str, t_check *stock, va_list vl);
void			checksignerror(char **str, t_check *stock, va_list vl);

#endif
