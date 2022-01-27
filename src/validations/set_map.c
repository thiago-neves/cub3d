/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves </var/mail/tneves>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:58:43 by tneves            #+#    #+#             */
/*   Updated: 2021/11/16 14:58:44 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	skip_to_map(t_window *window, int *folder)
{
	int		i;
	char	*line;

	i = 0;
	*folder = open(window->path, O_RDONLY);
	while (get_next_line(*folder, &line) && i < window->map.initial_line - 1)
	{
		i++;
		free(line);
	}
	free(line);
}

static int	set_array(t_window *window, char **array, int *folder)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(*folder, &line))
	{
		array[i] = line;
		i++;
	}
	array[i] = line;
	return (0);
}

static int	verify_array(char **array, t_window *window, int *folder)
{
	int	x;
	int	y;

	y = 0;
	while (window->map.y > y)
	{
		x = 0;
		while (array[y][x])
		{
			if (verify_char(array, window, x, y))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	set_map_data(t_window *window, char *line, int skip)
{
	int	map_x;
	int	folder;

	window->map.y++;
	if (window->map.initial_line == 0)
		window->map.initial_line = skip;
	if (*line == 0 && !window->map.is_after)
		window->map.n_breaks++;
	else
		window->map.is_after = 1;
	return (0);
}

int	set_map(t_window *window, char *line)
{
	int		folder;
	char	**array;

	array = (char **)malloc(sizeof(char *) * window->map.y);
	skip_to_map(window, &folder);
	set_array(window, array, &folder);
	if (verify_array(array, window, &folder))
	{
		free_setted_array(window, array);
		return (1);
	}
	if (window->player.x == 0)
	{
		free_setted_array(window, array);
		return (1);
	}
	window->map.map = array;
	return (0);
}
