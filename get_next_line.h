/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 14:43:07 by zleullie          #+#    #+#             */
/*   Updated: 2026/05/23 18:18:38 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

char	*get_next_line(int fd);

size_t	ft_strlen(char *s);
char	*ft_strncat(char *dest, char *buf, size_t n);
char	*ft_strndup(char *s1, size_t n);
char	*find_end(char *s1, int str_end);
char	*cleanup(char **stash_ptr, int clone_stash, char **free_buf);
char	*initialize_buffer();

#endif
