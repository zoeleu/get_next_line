/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 09:09:11 by zleullie          #+#    #+#             */
/*   Updated: 2026/05/21 05:47:35 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	update_buffer(t_gnl_state *state);
static int	update_line(t_gnl_state *state);
static char	*get_return(t_gnl_state *state);
static int	scan_for_nl(t_gnl_state *state, size_t *end_index, int *found);
static int	append_from_to(t_gnl_state *state, size_t start, size_t end);

char	*get_next_line(int fd)
{
	static t_gnl_state	state = {0};

	if (fd < 0)
		return (NULL);
	if (!initialize_state(&state, fd))
		return (NULL);
	while (!state.eol)
	{
		if (!update_buffer(&state))
		{
			/* on read error */
			if (state.line)
				free(state.line);
			state.line = NULL;
			return (NULL);
		}
		if (!update_line(&state))
		{
			if (state.line)
				free(state.line);
			state.line = NULL;
			return (NULL);
		}
	}
	return (get_return(&state));
}

int	update_buffer(t_gnl_state *state)
{
	ssize_t	read_result;
	if (state->index >= state->bytes_read && !state->eof)
	{
		read_result = read(state->fd, state->buffer, BUFFER_SIZE);
		if (read_result > 0)
		{
			state->bytes_read = (size_t)read_result;
			state->index = 0;
			state->first_read = 0;
		}
		else if (read_result == 0)
		{
			state->eof = 1;
			state->bytes_read = 0;
			state->index = 0;
		}
		else
			return (0);
	}
	return (1);
}

int	initialize_state(t_gnl_state *state, int fd)
{
	if (state->fd != fd)
	{
		if (state->line)
			free(state->line);
		state->fd = fd;
		state->index = 0;
		state->bytes_read = 0;
		state->first_read = 1;
		state->eol = 0;
		state->eof = 0;
		state->line = malloc(1);
		if (!state->line)
			return (0);
		state->line[0] = '\0';
	}
	else if (!state->line)
	{
		state->line = malloc(1);
		if (!state->line)
			return (0);
		state->line[0] = '\0';
	}
	state->eol = 0;
	return (1);
}

int	update_line(t_gnl_state *state)
{
	size_t start = state->index;
	size_t end = start;
	int found = 0;

	if (!scan_for_nl(state, &end, &found))
		return (0);
	if (!append_from_to(state, start, end))
		return (0);
	if (found)
		state->eol = 1;
	return (1);
}

static int	scan_for_nl(t_gnl_state *state, size_t *end_index, int *found)
{
	size_t i = state->index;

	*found = 0;
	if (state->bytes_read == 0 && state->eof)
	{
		*end_index = i;
		state->eol = 1;
		return (1);
	}
	while (i < state->bytes_read)
	{
		if (state->buffer[i] == '\n')
		{
			i++;
			*found = 1;
			break ;
		}
		i++;
	}
	*end_index = i;
	return (1);
}

static int	append_from_to(t_gnl_state *state, size_t start, size_t end)
{
	size_t len = end - start;
	char *block = malloc(len + 1);
	char *joined;

	if (!block)
		return (0);
	for (size_t k = 0; k < len; k++)
		block[k] = state->buffer[start + k];
	block[len] = '\0';
	joined = strjoin(state->line, block);
	free(state->line);
	free(block);
	if (!joined)
		return (0);
	state->line = joined;
	state->index = end;
	if (state->index >= state->bytes_read)
	{
		state->index = 0;
		state->bytes_read = 0;
	}
	return (1);
}

char	*get_return(t_gnl_state *state)
{
	char *ret;
	(void)state;
	if (!state->line)
		return (NULL);
	ret = state->line;
	state->line = NULL;
	state->eol = 0;
	return (ret);
}
