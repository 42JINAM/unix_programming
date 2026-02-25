/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cool <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 16:13:58 by cool              #+#    #+#             */
/*   Updated: 2026/02/25 16:14:24 by cool             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/apue.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	c;

	c = getc(stdin);
	while (c != EOF)
	{
		if (putc(c, stdout) == EOF)
			err_sys("output error");
		c = getc(stdin);
	}
	if (ferror(stdin))
		err_sys("input error");
	exit(0);
}
