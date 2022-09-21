/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eayasli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:46:11 by eayasli           #+#    #+#             */
/*   Updated: 2022/02/24 12:27:17 by eayasli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	printchar(char a)
{
	write(1, &a, 1);
	return (1);
}

int	printstr(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i++], 1);
	}
	return (i);
}

int	printnbr(int a)
{
	int	prtnbr;

	prtnbr = 0;
	if (a == -2147483648)
	{
		prtnbr += printstr("-2147483648");
		return (prtnbr);
	}
	if (a < 0)
	{
		prtnbr += printchar('-');
		a *= -1;
	}
	if (a > 9)
		prtnbr += printnbr(a / 10);
	prtnbr += printchar(a % 10 + '0');
	return (prtnbr);
}

int	printunbr(unsigned int a)
{
	int	prtnbr;

	prtnbr = 0;
	if (a > 9)
		prtnbr += printnbr(a / 10);
	prtnbr += printchar(a % 10 + '0');
	return (prtnbr);
}

int	printdecimal(unsigned int n, char c)
{
	int	prtnbr;

	prtnbr = 0;
	if (n == 0)
	{
		printchar('0');
		return (1);
	}
	if (n >= 16)
		prtnbr += printdecimal(n / 16, c);
	if (c == 'x')
		prtnbr += printchar("0123456789abcdef"[n % 16]);
	else
		prtnbr += printchar("0123456789ABCDEF"[n % 16]);
	return (prtnbr);
}
