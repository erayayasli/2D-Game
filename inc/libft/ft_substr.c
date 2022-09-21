/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eayasli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:06:34 by eayasli           #+#    #+#             */
/*   Updated: 2022/02/08 17:18:06 by eayasli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr( char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new;

	i = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) <= start)
	{
		new = ft_calloc(1, 1);
		return (new);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	new = malloc(len + 1);
	if (!new)
		return (0);
	while (i < len && s[start])
	{
		new[i] = s[start];
		i++;
		start++;
	}
	new[i] = '\0';
	return (new);
}
