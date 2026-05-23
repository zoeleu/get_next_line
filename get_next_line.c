/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 14:43:11 by zleullie          #+#    #+#             */
/*   Updated: 2026/05/23 18:00:30 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*stash = NULL;
	char			*line;
	char			*buf;
	char			*read_buffer;
	static ssize_t	read_result;

	read_buffer = malloc(BUFFER_SIZE);
	read_buffer[0] = 0;
	if (!stash)
		stash = ft_strndup("", (size_t)(-1));
	while (!find_end(stash, 0))
	{
		read_result = read(fd, read_buffer, BUFFER_SIZE);
		if (read_result == -1)
		{
			free(stash);
			stash = NULL;
			break ;
		}
		if (read_result == 0)
			break ;
		stash = ft_strncat(stash, read_buffer, read_result);
	}
	if (read_result < 1)
		return (cleanup(&stash, 1, read_buffer));
	line = ft_strndup(stash, find_end(stash, 1) - stash);
	buf = ft_strndup(find_end(stash, 1), (size_t)(-1));
	cleanup(&stash, 0, read_buffer);
	stash = buf;
	return (line);
}

char	*cleanup(char **stash_ptr, int clone_stash, char *free_buf)
{
	char	*stash;
	char	*buf;

	stash = *stash_ptr;
	if (!stash)
	{
		free(free_buf);
		return (NULL);
	}
	if (clone_stash && ft_strlen(stash) != 0)
	{
		buf = ft_strndup(stash, (size_t)(-1));
		free(stash);
		*stash_ptr = ft_strndup("", (size_t)(-1));
		free(free_buf);
		return (buf);
	}
	free(free_buf);
	free(stash);
	return (NULL);
}
