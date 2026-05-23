/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:46:42 by zleullie          #+#    #+#             */
/*   Updated: 2026/05/20 02:45:25 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	char	*c;
	int		fd;

	fd = open("hello.txt", O_RDONLY);
	while (1)
	{
		c = get_next_line(fd);
		if (!c)
			break ;
		printf("%s", c);
	}
}
