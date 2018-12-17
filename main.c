/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:19:46 by qgirard           #+#    #+#             */
/*   Updated: 2018/12/17 19:36:49 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
//	int fd = 42;
//	char *str = "DEMIE VOLEE PAVARD";
	//if (ft_printf("CINQ DOIGTS DE LA MAIN") == 0)
	if (ft_printf("HEXADECIMAL = %X\n", 42) == 0)
		return (1);
	return (0);
}
