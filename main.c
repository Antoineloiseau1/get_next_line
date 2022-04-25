/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:52:09 by anloisea          #+#    #+#             */
/*   Updated: 2022/04/23 19:19:55 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>

int main()
{
    int fd = open("note.txt", O_RDONLY);
    if (fd == -1)
    {
        puts("Failed to open()");
        return (1);
	}
 	char	*get;
	get = get_next_line(fd);
	printf("output = %s", get);
	// printf("output = %s", get_next_line(fd));
	// printf("output = %s", get_next_line(fd));

/* 	while (get)
	{
		printf("output = %s", get);
		free(get);
		get = get_next_line(fd);
	} */
	free(get);
    close(fd);
    return (0);
}