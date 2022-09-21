/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eayasli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:45:51 by eayasli           #+#    #+#             */
/*   Updated: 2022/02/24 11:19:36 by eayasli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	organizer(char a, va_list arg)
{
	int	prtnbr;

	prtnbr = 0;
	if (a == 'c')
		prtnbr += printchar(va_arg(arg, int));
	else if (a == 's')
		prtnbr += printstr(va_arg(arg, char *));
	else if (a == 'p')
	{
		prtnbr += write(1, "0x", 2);
		prtnbr += printpointer(va_arg(arg, unsigned long int));
	}
	else if (a == 'd')
		prtnbr += printnbr(va_arg(arg, int));
	else if (a == 'i')
		prtnbr += printnbr(va_arg(arg, int));
	else if (a == 'u')
		prtnbr += printunbr(va_arg(arg, unsigned int));
	else if (a == 'x' || a == 'X')
		prtnbr += printdecimal(va_arg(arg, int), a);
	else if (a == '%')
		prtnbr += printpercent();
	return (prtnbr);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	arg;
	int		prtnbr;

	prtnbr = 0;
	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			prtnbr += organizer(str[++i], arg);
			i++;
		}
		else
			prtnbr += printchar(str[i++]);
	}
	va_end(arg);
	return (prtnbr);
}
