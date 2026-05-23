/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 09:09:09 by zleullie          #+#    #+#             */
/*   Updated: 2026/05/23 14:38:36 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*arr;
	unsigned char	chk;

	chk = (unsigned char)c;
	arr = (unsigned char *)s;
	while (n--)
	{
		if (*arr == chk)
			return (arr);
		arr++;
	}
	return (0);
}

size_t	strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*strjoin(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_buffer;
	size_t	index;

	s1_len = strlen(s1);
	s2_len = strlen(s2);
	new_buffer = malloc(s1_len + s2_len + 1);
	index = 0;
	while (*s1)
		new_buffer[index++] = *s1++;
	while (*s2)
		new_buffer[index++] = *s2++;
	new_buffer[index] = '\0';
	return (new_buffer);
}

char	*strdup(const char *str)
{
	char	*new_buffer;
	size_t	len;

	len = strlen(str);
	new_buffer = malloc(len + 1);
	if (!new_buffer)
		return (NULL);
	for (size_t i = 0; i < len; i++)
		new_buffer[i] = str[i];
	new_buffer[len] = '\0';
	return (new_buffer);
}
