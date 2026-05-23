/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 09:09:16 by zleullie          #+#    #+#             */
/*   Updated: 2026/05/20 23:43:55 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct s_gnl_state
{
	int		fd;
	char	*line;
	char	buffer[BUFFER_SIZE];
	size_t	index;
	size_t	bytes_read;
	int		first_read;
	int		eol;
	int		eof;
}	t_gnl_state;

char	*get_next_line(int fd);
void	*ft_memchr(const void *s, int c, size_t n);
char	*strjoin(const char *s1, const char *s2);
size_t	strlen(const char *str);
char	*strdup(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);

int		initialize_state(t_gnl_state *state, int fd);

#endif