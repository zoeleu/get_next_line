/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 14:43:11 by zleullie          #+#    #+#             */
/*   Updated: 2026/05/23 17:33:26 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*stash = NULL;
	char			*line;
	char			*buf;
	char			read_buffer[BUFFER_SIZE];
	static ssize_t	read_result;

	if (!stash)
		stash = ft_strndup("", (size_t)(-1));
	while (!find_end(stash, 0))
	{
		read_result = read(fd, read_buffer, BUFFER_SIZE);
		if (read_result == -1)
			free(stash);
		if (read_result == 0)
			break ;
		stash = ft_strncat(stash, read_buffer, read_result);
	}
	if (read_result < 1)
		return (cleanup(&stash));
	line = ft_strndup(stash, find_end(stash, 1) - stash);
	buf = ft_strndup(find_end(stash, 1), (size_t)(-1));
	free(stash);
	stash = buf;
	return (line);
}

char	*cleanup(char **stash)
{
	free(*stash);
	return (NULL);
}
