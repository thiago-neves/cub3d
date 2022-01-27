/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves </var/mail/tneves>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:58:17 by tneves            #+#    #+#             */
/*   Updated: 2021/11/16 15:12:14 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	get_ray_dir_x(t_window *window, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (window->player.x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - window->player.x) \
			* ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (window->player.y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - window->player.y) \
			* ray->delta_dist_y;
	}
}

static void	initialize_ray(t_window *window, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)window->x - 1;
	ray->dir_x = window->player.dir_x + window->player.plane_x * ray->camera_x;
	ray->dir_y = window->player.dir_y + window->player.plane_y * ray->camera_x;
	ray->map_x = (int)window->player.x;
	ray->map_y = (int)window->player.y;
	ray->delta_dist_x = fabs(1 / ray->dir_x);
	ray->delta_dist_y = fabs(1 / ray->dir_y);
	get_ray_dir_x(window, ray);
}

static void	wall_is_hit(t_window *window, t_ray *ray, int hit)
{
	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			if (ray->step_x == 1)
				ray->side = 0;
			else if (ray->step_x == -1)
				ray->side = 1;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			if (ray->step_y == 1)
				ray->side = 2;
			else if (ray->step_y == -1)
				ray->side = 3;
		}
		if (window->map.map[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

static void	get_draw_height(t_window *window, t_ray *ray)
{
	ray->line_height = (int)(window->y / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + window->y / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + window->y / 2;
	if (ray->draw_end >= window->y)
		ray->draw_end = window->y - 1;
}

int	draw_map(t_window *window)
{
	t_ray	ray;
	int		x;
	int		hit;

	x = 0;
	while (x < window->x)
	{
		initialize_ray(window, &ray, x);
		wall_is_hit(window, &ray, hit);
		if (ray.side == 0 || ray.side == 1)
			ray.perp_wall_dist = (ray.map_x - window->player.x \
				+ (1 - ray.step_x) / 2) / ray.dir_x;
		else
			ray.perp_wall_dist = (ray.map_y - window->player.y \
				+ (1 - ray.step_y) / 2) / ray.dir_y;
		get_draw_height(window, &ray);
		draw_line(window, &ray, x);
		x++;
	}
	mlx_put_image_to_window(window->mlx, window->win, window->image.img, 0, 0);
	return (0);
}
