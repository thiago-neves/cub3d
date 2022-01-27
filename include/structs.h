/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves </var/mail/tneves>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:05:36 by tneves            #+#    #+#             */
/*   Updated: 2021/11/16 15:06:46 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_image {
	void	*img;
	char	*addr;
	int		endian;
	int		line_length;
	int		width;
	int		height;
	int		bits_per_pixel;
}				t_image;

typedef struct s_ray
{
	int		side;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	camera_x;
	double	dir_x;
	double	dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
}				t_ray;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_player;

typedef struct s_line
{
	int	x;
	int	y;
	int	y0;
	int	y1;
	int	tex_x;
	int	tex_y;
}			t_line;

typedef struct s_textures
{
	t_image	*no;
	t_image	*so;
	t_image	*we;
	t_image	*ea;
	int		*floor;
	int		*ceilling;
}			t_textures;

typedef struct s_map
{
	char	**map;
	int		y;
	int		initial_line;
	int		n_breaks;
	int		is_after;
}				t_map;

typedef struct s_key
{
	int	up;
	int	back;
	int	left;
	int	right;
	int	turn_left;
	int	turn_right;
}				t_key;

typedef struct s_window
{
	int			x;
	int			y;
	t_key		key;
	t_map		map;
	void		*win;
	void		*mlx;
	char		*path;
	t_image		image;
	t_player	player;
	t_textures	*textures;
}				t_window;

#endif
