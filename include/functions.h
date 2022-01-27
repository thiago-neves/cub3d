/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves </var/mail/tneves>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:05:26 by tneves            #+#    #+#             */
/*   Updated: 2021/11/16 15:06:13 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "structs.h"
# include "../get_next_line/get_next_line.h"

int		set_map(t_window *window, char *line);
int		verify_map(t_window *window, char *path);
int		verify_color(t_window *window, char **arguments);
int		verify_texture(t_window *window, char **arguments);
int		verify_args(t_window *window, int argc, char **argv);
int		set_map_data(t_window *window, char *line, int skip);
void	clear_array(char **array);
int		verify_char(char **array, t_window *window, int x, int y);
int		draw_map(t_window *window);
int		key_hook(int keycode, t_window *window);
int		closed(t_window *window);
int		free_all(t_window *window);
void	ver_line_color_image(t_line *line, t_window *window, int color );
void	pixel_put_to_image(int *color, int x, int y, t_image *img);
void	put_xpm_to_image(t_window *win, t_image *img, t_line *line, t_ray *ray);
void	put_xpm_to_image(t_window *window, t_image *img, t_line *line, \
			t_ray *ray);
void	draw_line(t_window *window, t_ray *ray, int x);
int		closed(t_window *window);
void	turn_right(t_window *window);
void	turn_left(t_window *window);
void	free_setted_array(t_window *window, char **array);
void	free_mlx(t_window *window);
void	free_textures(t_window *window);
int		free_map(t_window *window, char **arguments, char *line, int fd);
#endif
