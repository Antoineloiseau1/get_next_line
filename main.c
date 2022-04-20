/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:52:09 by anloisea          #+#    #+#             */
/*   Updated: 2022/04/20 19:20:27 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int main()
{
    int fd = open("./tripouille/files/big_line_no_nl", O_RDONLY);
    if (fd == -1)
    {
        puts("Failed to open()");
        return (1);
	}

	// printf("output = %s", get_next_line(fd));
	// printf("output = %s", get_next_line(fd));
	// printf("output = %s", get_next_line(fd));
 	char	*get;
	get = get_next_line(fd);
	while (get)
	{
		printf("output = %s", get);
		get = get_next_line(fd);
	}
    close(fd);
    return (0);
}