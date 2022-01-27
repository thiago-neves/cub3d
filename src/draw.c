/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves </var/mail/tneves>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:57:35 by tneves            #+#    #+#             */
/*   Updated: 2021/11/16 14:57:37 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_line_xpm_image(t_line *l, t_window *win, t_image *img, t_ray *ray)
{
	int	y_max;

	if (l->y0 < l->y1)
	{
		l->y = l->y0;
		y_max = l->y1;
	}
	else
	{
		l->y = l->y1;
		y_max = l->y0;
	}
	if (l->y >= 0)
	{
		while (l->y < y_max)
		{
			put_xpm_to_image(win, img, l, ray);
			l->y++;
		}
	}
}

void	print_line_color(t_line *line, t_window *window, int *color)
{
	int	y;
	int	y_max;

	if (line->y0 < line->y1)
	{
		y = line->y0;
		y_max = line->y1;
	}
	else
	{
		y = line->y1;
		y_max = line->y0;
	}
	if (y >= 0)
	{
		while (y < y_max)
		{
			pixel_put_to_image(color, line->x, y, &window->image);
			y++;
		}
	}
}

static void	print_colors(t_window *win, t_line *l, t_ray *ray, t_image *img)
{
	l->y0 = ray->draw_end;
	l->y1 = ray->draw_start;
	draw_line_xpm_image(l, win, img, ray);
	l->y0 = 0;
	l->y1 = ray->draw_start;
	print_line_color(l, win, win->textures->ceilling);
	l->y0 = win->y;
	l->y1 = ray->draw_end;
	print_line_color(l, win, win->textures->floor);
}

void	draw_line(t_window *window, t_ray *ray, int x)
{
	double	wall_x;
	t_line	line;
	t_image	*img;
	int		tex_x;

	line.x = x;
	if (ray->side == 0 || ray->side == 1)
		wall_x = window->player.y + ray->perp_wall_dist * ray->dir_y;
	else
		wall_x = window->player.x + ray->perp_wall_dist * ray->dir_x;
	wall_x -= floor(wall_x);
	img = window->textures->no;
	if (ray->side == 0)
		img = window->textures->so;
	if (ray->side == 1)
		img = window->textures->ea;
	if (ray->side == 2)
		img = window->textures->we;
	tex_x = (int)(wall_x * (double)img->width);
	if ((ray->side == 0 || ray->side == 1) && ray->dir_x > 0)
		tex_x = img->width - tex_x - 1;
	if ((ray->side == 2 || ray->side == 3) && ray->dir_y < 0)
		tex_x = img->width - tex_x - 1;
	line.tex_x = tex_x;
	print_colors(window, &line, ray, img);
}
