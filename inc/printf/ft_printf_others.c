/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_others.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eayasli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:28:19 by eayasli           #+#    #+#             */
/*   Updated: 2022/02/24 12:29:59 by eayasli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	printpercent(void)
{
	write(1, "%", 1);
	return (1);
}

int	printpointer(unsigned long int a)
{
	int	prtnbr;

	prtnbr = 0;
	if (a >= 16)
		prtnbr += printpointer(a / 16);
	prtnbr += printchar("0123456789abcdef"[a % 16]);
	return (prtnbr);
}
