/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves </var/mail/tneves>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:57:00 by tneves            #+#    #+#             */
/*   Updated: 2021/11/16 15:04:02 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	turn_right(t_window *window)
{
	double	rot_speed;
	double	old_dir_x;
	double	old_plane_x;

	rot_speed = .1;
	old_dir_x = window->player.dir_x;
	old_plane_x = window->player.plane_x;
	window->player.dir_x = window->player.dir_x * cos(rot_speed) \
			- window->player.dir_y * sin(rot_speed);
	window->player.dir_y = old_dir_x * sin(rot_speed) \
			+ window->player.dir_y * cos(rot_speed);
	window->player.plane_x = window->player.plane_x * cos(rot_speed) \
			- window->player.plane_y * sin(rot_speed);
	window->player.plane_y = old_plane_x * sin(rot_speed) \
			+ window->player.plane_y * cos(rot_speed);
}

void	turn_left(t_window *window)
{
	double	rot_speed;
	double	old_dir_x;
	double	old_plane_x;

	rot_speed = .1;
	old_dir_x = window->player.dir_x;
	old_plane_x = window->player.plane_x;
	window->player.dir_x = window->player.dir_x * cos(-rot_speed) \
			- window->player.dir_y * sin(-rot_speed);
	window->player.dir_y = old_dir_x * sin(-rot_speed) \
			+ window->player.dir_y * cos(-rot_speed);
	window->player.plane_x = window->player.plane_x * cos(-rot_speed) \
			- window->player.plane_y * sin(-rot_speed);
	window->player.plane_y = old_plane_x * sin(-rot_speed) \
			+ window->player.plane_y * cos(-rot_speed);
}
