/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:19:46 by qgirard           #+#    #+#             */
/*   Updated: 2019/01/07 16:52:55 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int		main(void)
{
//	int fd = 42;
//	char *str = "DEMIE VOLEE PAVARD";
	//if (ft_printf("CINQ DOIGTS DE LA MAIN") == 0)
	ft_printf("%+d\n", -42);
	printf("%+d\n", -42);
	return (0);
}
