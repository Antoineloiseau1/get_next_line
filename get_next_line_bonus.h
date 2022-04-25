/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:48:57 by anloisea          #+#    #+#             */
/*   Updated: 2022/04/23 19:19:34 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_is_endline(char *save);
char	*ft_read_file(int fd, char *save);
char	*ft_strjoin(char *buf, char *save);
int		ft_strlen(char *str);
char	*ft_get_line(char *save);
char	*ft_clean_save(char *save);
char    *ft_strdup(char *str);

#endif