/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zleullie <zleullie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 15:53:09 by zleullie          #+#    #+#             */
/*   Updated: 2026/05/23 15:55:42 by zleullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	char	*str;
	int		fd;

	fd = open("hello.txt", O_RDONLY);
	str = NULL;
	while (1)
	{
		str = get_next_line(fd);
		printf("%s", str);
		if (str == NULL)
			break ;
		free(str);
	}
	close(fd);
}
