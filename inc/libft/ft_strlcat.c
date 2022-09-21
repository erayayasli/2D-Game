/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eayasli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:40:36 by eayasli           #+#    #+#             */
/*   Updated: 2022/02/08 12:07:52 by eayasli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize <= ft_strlen(dest))
		return (dstsize + ft_strlen(src));
	i = ft_strlen(dest);
	while (*src && i + 1 < dstsize)
	{
		dest[i] = *src;
		src++;
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(dest) + ft_strlen(src));
}
