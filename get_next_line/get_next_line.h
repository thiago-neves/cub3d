/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves <tneves@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:58:09 by tneves            #+#    #+#             */
/*   Updated: 2021/02/17 23:38:58 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1024

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
int		ft_str_has_line(const char *str, int c);
size_t	ft_strlen(const char *s);
char	*ft_gnl_substr(char const *s, unsigned int start, int len, char *strf);
char	*ft_gnl_strjoin(char *s1, char *s2);
size_t	ft_line_length(const char *str);

#endif
