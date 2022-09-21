/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eayasli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:44:52 by eayasli           #+#    #+#             */
/*   Updated: 2022/03/02 10:47:12 by eayasli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include<stdlib.h>
# include<unistd.h>
#define BUFFER_SIZE 500000


size_t	ft_strlenn(char *str);
char	*ft_strchrr(char *s, int c);
char	*ft_strjoinn(char *s1, char *s2);
char	*ft_substrr(const char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
char	*ft_read_and_save(int fd, char *save);
char	*get_line(char *str);
char	*get_remain(char *str);
#endif
