/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isdigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves <tneves@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 22:19:01 by tneves            #+#    #+#             */
/*   Updated: 2021/03/30 22:21:40 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_isdigit(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		if (!ft_isdigit(s[i++]))
			return (0);
	return (1);
}
