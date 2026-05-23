/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 14:43:11 by zleullie          #+#    #+#             */
/*   Updated: 2026/05/23 18:23:37 by zleullie         ###   ########.fr       */
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

	read_buffer = initialize_buffer();
	if (!stash)
		stash = str_duplicate_n("", (size_t)(-1));
	while (!find_end(stash, 0))
	{
		read_result = read(fd, read_buffer, BUFFER_SIZE);
		if (read_result == -1)
			cleanup(&stash, 0, &read_buffer);
		if (read_result <= 0)
			break ;
		stash = append_to_str(stash, read_buffer, read_result);
	}
	if (read_result < 1)
		return (cleanup(&stash, 1, &read_buffer));
	line = str_duplicate_n(stash, find_end(stash, 1) - stash);
	buf = str_duplicate_n(find_end(stash, 1), (size_t)(-1));
	cleanup(&stash, 0, &read_buffer);
	stash = buf;
	return (line);
}

char	*cleanup(char **stash_ptr, int clone_stash, char **free_buf)
{
	char	*stash;
	char	*buf;

	stash = *stash_ptr;
	if (free_buf)
	{
		free(*free_buf);
		*free_buf = 0;
	}
	if (!stash)
		return (NULL);
	if (clone_stash && stash && ft_strlen(stash) != 0)
	{
		buf = str_duplicate_n(stash, (size_t)(-1));
		free(stash);
		*stash_ptr = str_duplicate_n("", (size_t)(-1));
		return (buf);
	}
	free(stash);
	*stash_ptr = NULL;
	return (NULL);
}

char	*initialize_buffer(void)
{
	char	*buf;

	buf = malloc(BUFFER_SIZE);
	buf[0] = 0;
	return (buf);
}
