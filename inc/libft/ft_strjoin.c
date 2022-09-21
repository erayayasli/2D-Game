/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eayasli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:39:26 by eayasli           #+#    #+#             */
/*   Updated: 2022/02/08 12:11:07 by eayasli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin( char *s1,  char *s2)
{
	char	*result;
	int		i;
	int		ri;

	ri = 0;
	i = 0;
	if (!s1 || !s2)
		return (0);
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (0);
	while (s1[i])
		result[ri++] = s1[i++];
	i = 0;
	while (s2[i])
		result[ri++] = s2[i++];
	result[ri] = '\0';
	return (result);
}
