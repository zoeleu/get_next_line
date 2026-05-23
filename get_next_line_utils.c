/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 14:43:09 by zleullie          #+#    #+#             */
/*   Updated: 2026/05/23 17:32:15 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

char	*ft_strncat(char *dest, char *buf, size_t n)
{
	char	*new_buffer;
	size_t	index;

	if (n == (size_t)(-1))
		new_buffer = malloc(ft_strlen(dest) + ft_strlen(buf) + 1);
	else
		new_buffer = malloc(ft_strlen(dest) + n + 1);
	index = 0;
	if (n == (size_t)(-1))
	{
		while (*dest)
			new_buffer[index++] = *dest++;
		while (*buf)
			new_buffer[index++] = *buf++;
	}
	else
	{
		while (*dest)
			new_buffer[index++] = *dest++;
		while (n--)
			new_buffer[index++] = *buf++;
	}
	new_buffer[index] = 0;
	return (free(dest), dest = new_buffer, dest);
}

char	*ft_strndup(char *s1, size_t n)
{
	char	*new_buffer;
	size_t	index;

	index = 0;
	if (n == (size_t)(-1))
		new_buffer = malloc(ft_strlen(s1) + 1);
	else
		new_buffer = malloc(n + 1);
	if (n == (size_t)(-1))
		while (*s1)
			new_buffer[index++] = *s1++;
	else
		while (n--)
			new_buffer[index++] = *s1++;
	new_buffer[index] = 0;
	return (new_buffer);
}

char	*find_end(char *s1, int str_end)
{
	while (*s1)
		if (*s1++ == '\n')
			return (s1);
	if (str_end)
		return (s1);
	else
		return (0);
}
