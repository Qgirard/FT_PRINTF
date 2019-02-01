/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:19:46 by qgirard           #+#    #+#             */
/*   Updated: 2019/02/01 18:28:56 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>

int		main(void)
{
	//test("%f", 654.23154);
	//ft_printf("%+  d\n", 42);
	//printf("%+  d\n", 42);
	//printf("RETURN = %d\n", ft_printf("%# 0-50p\n", ""));
	//printf("RETURN = %d\n", printf("%# 0-50p\n", ""));
	//printf("%d\n", ft_printf("toto %0##0.4X%#4.2xet c'est fini \n", 0x037a, 0x9e));
	//printf("%d\n", printf("toto %0##0.4X%#4.2xet c'est fini \n", 0x037a, 0x9e));
	printf("%d\n", ft_printf("test %-7C %007d!!", 0xd777, 0x45));
	printf("%d\n", printf("test %-7C %007d!!", 0xd777, 0x45));
	//printf("FLOAT = %f\n", DBL_MAX);
	return (0);
}
