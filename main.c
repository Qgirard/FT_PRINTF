/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:19:46 by qgirard           #+#    #+#             */
/*   Updated: 2019/01/24 19:20:03 by qgirard          ###   ########.fr       */
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
	ft_printf("{%*d}\n", 5, 42);
	printf("{%*d}\n", 5, 42);
	//printf("%d\n", ft_printf("%c", 0));
	//printf("%d\n", printf("%c", 0));
	//printf("FLOAT = %f\n", DBL_MAX);
	return (0);
}
