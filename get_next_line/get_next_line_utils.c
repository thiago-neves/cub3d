/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves <tneves@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 23:17:07 by tneves            #+#    #+#             */
/*   Updated: 2021/02/19 15:06:20 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_str_has_line(const char *str, int c)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_line_length(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	if (i > 0)
		return (i - 1);
	return (i);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_gnl_substr(char const *s, unsigned int start, int len, char *strf)
{
	char	*str;
	char	*ptr;
	size_t	length;

	length = ft_strlen(s);
	if (!s || (int)len < 0)
	{
		free(strf);
		return (0);
	}
	str = malloc(len + 1);
	if (!str)
	{
		free(strf);
		return (0);
	}
	ptr = str;
	while (len-- > 0 && start < length && s[start])
		*ptr++ = s[start++];
	*ptr = 0;
	free(strf);
	return (str);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	char	*s1free;
	char	*ptr;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(len1 + len2 + 1);
	ptr = str;
	if (!str)
	{
		free(s1);
		return (0);
	}
	s1free = s1;
	if (s1)
		while (*s1)
			*ptr++ = *s1++;
	if (s2)
		while (*s2)
			*ptr++ = *s2++;
	*ptr = 0;
	free(s1free);
	return (str);
}
