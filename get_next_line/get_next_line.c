/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves <tneves@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:03:01 by tneves            #+#    #+#             */
/*   Updated: 2021/03/30 16:29:55 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char *string)
{
	char	*new_line;
	int		line_length;

	line_length = ft_line_length(string);
	if (string[line_length] != '\n')
		line_length++;
	new_line = ft_gnl_substr(string, 0, line_length, 0);
	return (new_line);
}

static char	*remove_line(char *string)
{
	int	line_length;
	int	left_over_length;

	line_length = ft_line_length(string);
	if (string[line_length] != '\n')
		line_length++;
	left_over_length = ft_strlen(string) - line_length - 1;
	string = ft_gnl_substr(string, line_length + 1, left_over_length, string);
	return (string);
}

static int	verify_inputs(int fd, char **line, char **buffer)
{
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	*buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!*buffer)
		return (-1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*saved_buffer;
	char		*buffer;
	int			reader;

	if ((verify_inputs(fd, line, &buffer)) == -1)
		return (-1);
	reader = 1;
	while (reader != 0 && !ft_str_has_line(saved_buffer, '\n'))
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[reader] = '\0';
		saved_buffer = ft_gnl_strjoin(saved_buffer, buffer);
	}
	free(buffer);
	*line = get_line(saved_buffer);
	saved_buffer = remove_line(saved_buffer);
	if (reader == 0)
		return (0);
	return (1);
}
