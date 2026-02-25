/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.6.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cool <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 16:25:05 by cool              #+#    #+#             */
/*   Updated: 2026/02/25 16:26:11 by cool             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "include/apue.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	printf("Hello world form process ID: %ld\n", (long)getpid());
	exit(0);
}
