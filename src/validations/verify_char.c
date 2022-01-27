/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves </var/mail/tneves>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:59:05 by tneves            #+#    #+#             */
/*   Updated: 2021/11/16 14:59:07 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	verify_space(char **array, t_window *window, int x, int y)
{
	if (x == 0 || y == window->map.n_breaks || y == window->map.y - 1 || \
			array[y - 1][0] == 0 || array[y][0] == 0 || array[y + 1][0] == 0)
		return (1);
	if (array[y - 1][x] == ' ' || array[y - 1][x + 1] == ' ' || \
			array[y - 1][x] == '\0' || array[y - 1][x + 1] == '\0')
		return (1);
	if (x > 0 && (array[y - 1][x - 1] == ' ' || array[y - 1][x - 1] == '\0'))
		return (1);
	if (x > 0 && (array[y][x - 1] == ' ' || array[y][x - 1] == '\0'))
		return (1);
	if (array[y][x + 1] == ' ' || array[y][x + 1] == '\0')
		return (1);
	if (array[y + 1][x] == ' ' || array[y + 1][x + 1] == ' ' || \
			array[y + 1][x] == '\0' || array[y + 1][x + 1] == '\0')
		return (1);
	if (x > 0 && array[y + 1][x - 1] == '\0')
		return (1);
	return (0);
}

void	set_start_pos(t_window *win, double d_y, double p_x, double p_y)
{
	win->player.dir_y = d_y;
	win->player.plane_x = p_x;
	win->player.plane_y = p_y;
}

static int	verify_player(t_window *win, char angle, int x, int y)
{
	if (win->player.x != 0 || win->player.y != 0)
		return (1);
	win->player.x = x + 0.5;
	win->player.y = y + 0.5;
	if (angle == 'N')
	{
		win->player.dir_x = 0;
		set_start_pos(win, -1, 0.66, 0);
	}
	else if (angle == 'S')
	{
		win->player.dir_x = 0;
		set_start_pos(win, 1, -0.66, 0);
	}
	else if (angle == 'W')
	{
		win->player.dir_x = -1;
		set_start_pos(win, 0, 0, -0.66);
	}
	else if (angle == 'E')
	{
		win->player.dir_x = 1;
		set_start_pos(win, 0, 0, 0.66);
	}
	return (0);
}

int	verify_char(char **array, t_window *win, int x, int y)
{
	if (array[y][x] == '0')
		return (verify_space(array, win, x, y));
	else if (array[y][x] == 'N' || array[y][x] == 'S' || array[y][x] == 'W' \
			|| array[y][x] == 'E')
		return (verify_player(win, array[y][x], x, y) == 1 \
				|| verify_space(array, win, win->player.x, win->player.y) == 1);
	else if (array[y][x] != ' ' && array[y][x] != '1')
		return (1);
	return (0);
}
