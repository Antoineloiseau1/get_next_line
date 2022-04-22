/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:50:06 by anloisea          #+#    #+#             */
/*   Updated: 2022/04/22 16:52:35 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*ft_strjoin(char *buf, char *save)
{
	int 	i;
	char	*stash;

	if (!save)
	{
		save = malloc(1 * sizeof(*save));
		save[0]= 0;
	}
	if (!save || !buf)
	{
		free(save);
		return (NULL);
	}
	stash = malloc((ft_strlen(buf) + ft_strlen(save) + 1) * sizeof(*stash));
	if (!stash)
	{
		free(save);
		return (NULL);
	}
	i = 0;
	while (save[i])
	{
		stash[i] = save[i];
		i++;
	}
	i = 0;
	while (buf[i])
	{
		stash[ft_strlen(save) + i] = buf[i];
		i++;
	} 
	stash[ft_strlen(save) + i] = '\0';
	free(save);
	return (stash);
}

char	*ft_clean_save(char *save)
{
	int		i;
	char	*clean;
	int 	j;

	i = 0;
	j = 0;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	while (save[i] != '\n' && save[i])
		i++;
	if (save[i] == '\n')
		i++;
	clean = malloc((ft_strlen(save) - i + 1) * sizeof(*clean));
	if (!clean)
	{
		free(save);
		return (NULL);
	}
	while (save[i + j])
	{
		clean[j] = save[i + j];
		j++;
	}
	clean[j] = 0;
	free(save);
	return (clean);
}

char	*ft_get_line(char *save)
{
	int		i;
	char	*line;

	i = 0;
	if (save[i] == '\0')
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(*line));
	if (!line)
	{	
		free(save);
		return (NULL);
	}
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = 0;
	return (line);
}

char	*ft_read_file(int fd, char *save)
{
	int		bytes;
	char	*buf;

	bytes = 1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(*buf));
	if (!buf)
		return (NULL);
	while (!ft_is_endline(save) && bytes)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes] = '\0';
		save = ft_strjoin(buf, save);
	}
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read_file(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	save = ft_clean_save(save);
	return (line);
}