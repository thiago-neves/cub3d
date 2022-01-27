/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves </var/mail/tneves>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:59:24 by tneves            #+#    #+#             */
/*   Updated: 2021/11/16 15:12:54 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	verify_file(t_window *window, char *path, int *folder)
{
	int		i;
	char	*line;
	char	*file_extension;

	i = 0;
	file_extension = ft_strrchr(path, '.');
	if (!ft_str_is_equal(file_extension, ".cub"))
		return (0);
	window->path = path;
	*folder = open(path, O_RDONLY);
	if (*folder == -1)
		return (0);
	return (1);
}

static int	set_elements_info(t_window *window, char **arguments)
{
	int		is_valid;

	is_valid = 0;
	if ((arguments[0] && arguments[0][0] == '\0') || !arguments[0])
		return (1);
	else if (ft_str_is_equal(arguments[0], "NO") && !window->textures->no)
		is_valid = verify_texture(window, arguments);
	else if (ft_str_is_equal(arguments[0], "SO") && !window->textures->so)
		is_valid = verify_texture(window, arguments);
	else if (ft_str_is_equal(arguments[0], "WE") && !window->textures->we)
		is_valid = verify_texture(window, arguments);
	else if (ft_str_is_equal(arguments[0], "EA") && !window->textures->ea)
		is_valid = verify_texture(window, arguments);
	else if (ft_str_is_equal(arguments[0], "F") && !window->textures->floor)
		is_valid = verify_color(window, arguments);
	else if (ft_str_is_equal(arguments[0], "C") && !window->textures->ceilling)
		is_valid = verify_color(window, arguments);
	return (is_valid);
}

static int	elements_info_is_not_setted(t_window *window)
{
	return (window->textures->floor == NULL || \
			window->textures->ceilling == NULL || \
			window->textures->no == NULL || \
			window->textures->so == NULL || \
			window->textures->we == NULL || \
			window->textures->ea == NULL);
}

static int	read_map(t_window *win, int f, char *line, char **arguments)
{
	int	i;

	i = 0;
	while (get_next_line(f, &line))
	{
		if (elements_info_is_not_setted(win))
		{
			arguments = ft_split(line, ' ');
			if (!set_elements_info(win, arguments))
				free_map(win, arguments, line, f);
			clear_array(arguments);
		}
		else
			if (set_map_data(win, line, i))
				free_map(win, 0, line, f);
		free(line);
		i++;
	}
	if (set_map_data(win, line, i) || set_map(win, line))
	{
		free(line);
		return (1);
	}
	free(line);
	return (0);
}

int	verify_map(t_window *window, char *path)
{
	char	*line;
	int		folder;
	int		i;
	char	**arguments;

	if (!verify_file(window, path, &folder))
	{
		free_textures(window);
		error_message_handler(1);
		return (2);
	}
	if (read_map(window, folder, line, arguments))
	{
		error_message_handler(2);
		return (4);
	}
	return (0);
}
