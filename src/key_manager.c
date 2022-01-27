/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves </var/mail/tneves>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:58:11 by tneves            #+#    #+#             */
/*   Updated: 2021/11/16 15:09:56 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	move_forward(t_window *window)
{
	if (window->map.map[(int) window->player.y][(int) \
			(window->player.x + window->player.dir_x)] == '0')
		window->player.x += window->player.dir_x;
	if (window->map.map[(int)(window->player.y + window->player.dir_y)][(int) \
			window->player.x] == '0')
		window->player.y += window->player.dir_y;
}

static void	move_backwards(t_window *window)
{
	if (window->map.map[(int)window->player.y][(int) \
			(window->player.x - window->player.dir_x)] == '0')
		window->player.x -= window->player.dir_x;
	if (window->map.map[(int)(window->player.y - window->player.dir_y)][(int) \
			window->player.x] == '0')
		window->player.y -= window->player.dir_y;
}

static void	move_left(t_window *window)
{
	if (window->map.map[(int)window->player.y][(int) \
			(window->player.x - window->player.plane_x)] == '0')
		window->player.x -= window->player.plane_x;
	if (window->map.map[(int)(window->player.y - window->player.plane_y)][(int) \
			window->player.x] == '0')
		window->player.y -= window->player.plane_y;
}

static void	move_right(t_window *window)
{
	if (window->map.map[(int)window->player.y][(int) \
			(window->player.x + window->player.plane_x)] == '0')
		window->player.x += window->player.plane_x;
	if (window->map.map[(int)(window->player.y + window->player.plane_y)][(int) \
			window->player.x] == '0')
		window->player.y += window->player.plane_y;
}

int	key_hook(int keycode, t_window *window)
{
	if (keycode == 119)
		move_forward(window);
	if (keycode == 115)
		move_backwards(window);
	if (keycode == 97)
		move_left(window);
	if (keycode == 100)
		move_right(window);
	if (keycode == 65363)
		turn_right(window);
	if (keycode == 65361)
		turn_left(window);
	if (keycode == 65307)
		closed(window);
	return (1);
}
