/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anloisea <anloisea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:48:57 by anloisea          #+#    #+#             */
/*   Updated: 2022/04/20 19:19:10 by anloisea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int	    ft_is_endline(char *save);
char    *ft_read_file(int fd, char *save);
char    *ft_stash(char *buf, char *save);
int     ft_strlen(char *str);
char    *ft_get_line(char *save);
char    *ft_clean_save(char *save);

#endif