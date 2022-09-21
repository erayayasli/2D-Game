/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eayasli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:44:59 by eayasli           #+#    #+#             */
/*   Updated: 2022/02/24 12:28:40 by eayasli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	printchar(char c);
int	printstr(const char *str);
int	printpercent(void);
int	printpointer(unsigned long int n);
int	printnbr(int n);
int	printunbr(unsigned int n);
int	printdecimal(unsigned int n, char c);
int	ft_printf(const char *str, ...);
int	organizer(char c, va_list arg);

#endif
