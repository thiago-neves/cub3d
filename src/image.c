/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves </var/mail/tneves>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:58:04 by tneves            #+#    #+#             */
/*   Updated: 2021/11/16 14:58:06 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	pixel_put_to_image(int *color, int x, int y, t_image *img)
{
	img->addr[y * img->line_length + x \
		* img->bits_per_pixel / 8] = color[2];
	img->addr[y * img->line_length + x \
		* img->bits_per_pixel / 8 + 1] = color[1];
	img->addr[y * img->line_length + x \
		* img->bits_per_pixel / 8 + 2] = color[0];
}

void	put_xpm_to_image(t_window *win, t_image *img, t_line *line, t_ray *ray)
{
	int	d;

	d = line->y * img->line_length - (win->y) * img->line_length / 2 \
			+ ray->line_height * img->line_length / 2;
	line->tex_y = ((d * img->height) / ray->line_height) / img->line_length;
	win->image.addr[line->y * win->image.line_length + line->x
		* win->image.bits_per_pixel / 8] = img->addr[line->tex_y
		* img->line_length + line->tex_x * (img->bits_per_pixel / 8)];
	win->image.addr[line->y * win->image.line_length + line->x
		* win->image.bits_per_pixel / 8 + 1] = img->addr[line->tex_y
		* img->line_length + line->tex_x * (img->bits_per_pixel / 8) + 1];
	win->image.addr[line->y * win->image.line_length + line->x
		* win->image.bits_per_pixel / 8 + 2] = img->addr[line->tex_y
		* img->line_length + line->tex_x * (img->bits_per_pixel / 8) + 2];
}
