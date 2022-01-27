/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves </var/mail/tneves>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:57:25 by tneves            #+#    #+#             */
/*   Updated: 2021/11/16 14:57:27 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char *argv[])
{
	t_window	window;

	window.mlx = mlx_init();
	if (verify_args(&window, argc, argv) || verify_map(&window, argv[1]))
		return (0);
	window.x = 640;
	window.y = 480;
	window.win = mlx_new_window(window.mlx, window.x, window.y, "Cub3d");
	window.image.img = mlx_new_image(window.mlx, window.x, window.y);
	window.image.addr = mlx_get_data_addr(window.image.img, \
			&window.image.bits_per_pixel, &window.image.line_length, \
			&window.image.endian);
	draw_map(&window);
	mlx_put_image_to_window(window.mlx, window.win, window.image.img, 0, 0);
	mlx_hook(window.win, 2, 1L << 0, key_hook, &window);
	mlx_hook(window.win, 33, 1L << 17, closed, &window);
	mlx_loop_hook(window.mlx, draw_map, &window);
	mlx_loop(window.mlx);
	return (0);
}
