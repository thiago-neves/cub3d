/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves </var/mail/tneves>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:59:13 by tneves            #+#    #+#             */
/*   Updated: 2021/11/16 14:59:14 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	is_valid_range(int value)
{
	return (value >= 0 && value <= 255);
}

static int	get_color_value(char **arguments, int *value, int i)
{
	if (arguments[1][i] == 0)
		return (-1);
	*value = ft_atoi(arguments[1] + i);
	if (!is_valid_range(*value))
		return (-1);
	while (ft_isdigit(arguments[1][i]))
		i++;
	if (arguments[1][i] == ',' && ft_isdigit(arguments[1][i + 1]))
		i++;
	return (i);
}

static int	verify_color_arguments(char **arguments, int *rgb)
{
	int	i;
	int	skip;
	int	value;

	if (!arguments[1] || (arguments[1] && arguments[2]))
		return (0);
	i = 0;
	skip = 0;
	while (3 > i)
	{
		skip = get_color_value(arguments, &value, skip);
		if (skip == -1)
			return (0);
		if (is_valid_range(value))
			rgb[i] = value;
		else
			return (0);
		i++;
	}
	if (arguments[1][skip] != '\0')
		return (0);
	return (1);
}

int	verify_color(t_window *window, char **arguments)
{
	int	*rgb;

	rgb = (int *)malloc(3 * sizeof(int));
	if (!verify_color_arguments(arguments, rgb))
	{
		free(rgb);
		return (0);
	}
	if (ft_str_is_equal(arguments[0], "F"))
		window->textures->floor = rgb;
	if (ft_str_is_equal(arguments[0], "C"))
		window->textures->ceilling = rgb;
	return (1);
}
