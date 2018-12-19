/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:12:04 by qgirard           #+#    #+#             */
/*   Updated: 2018/12/19 16:21:27 by qgirard          ###   ########.fr       */
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
	int		len;
	int		precision;
	char	*size;
	int		type;
}				t_check;

int				ft_printf(const char *format, ...);
void			checkoptions(const char **format, t_check **stock);
void			checktype(const char **format, t_check **stock);
void			convertinstr(char **str, t_check *stock, va_list vl);

#endif
