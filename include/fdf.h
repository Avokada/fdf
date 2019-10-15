/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:04:28 by thaley            #+#    #+#             */
/*   Updated: 2019/10/15 17:54:48 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define WIN_WIDTH 1400
# define WIN_HEIGHT 1200

# define UP_K 126
# define DOWN_K 125
# define RIGHT_K 124
# define LEFT_K 123
# define ESC_K 53
# define NUM_ONE 83
# define NUM_TWO 84
# define NUM_THREE 85
# define NUM_FOUR 86
# define NUM_FIVE 87
# define NUM_SIX 88
# define NUM_SEVEN 89
# define NUM_EIGHT 91
# define NUM_NINE 92
# define NUM_NULL 82
# define PLUS_K 69
# define MINUS_K 78

# define BLUE 0x00606d
# define DARK_PURPLE 0x330055
# define LIGHT_PURPLE 0x9988AA
# define DARK_TURQUOISE 0x007869
# define MID_TURQUOISE 0x1ff6bb
# define GREEN 0x95ce45
# define YELLOW 0xFFF69E
# define WHITE 0xFFFFFF

typedef struct		s_crd
{
	float			x;
	float			y;
	float			z;
	int				color;
}					t_crd;

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
	int				color;
}					t_point;

typedef struct		s_draw
{
	float			lenght_x;
	float			lenght_y;
	float			step_x;
	float			step_y;
	float			step;
	t_point			tmp;
}					t_draw;

typedef struct		s_fdf
{
	t_crd			**crd;
	t_point			src;
	t_point			dst;
	void			*mlx;
	void			*window;
	void			*image;
	float			scale;
	float			degree;
	int				scale_z;
	int				pix_inf[3];
	int				*pixels;
	int				col;
	int				row;
	int				low_p;
	int				top_p;
	int				offset_x;
	int				offset_y;
	int				angle_x;
	int				angle_y;
	int				angle_z;
	char			*prog_name;
}					t_fdf;

/*
**	exit.c
*/

int					ft_exit(t_fdf *fdf, int err);
void				free_struct(t_fdf *fdf);

/*
**	key_press.c
*/

int					key_press(int key, t_fdf *fdf);

/*
**	draw.c
*/

void				draw_image(t_fdf *fdf);
void				draw_line(int *pixels, t_point *src, t_point *dst);

/*
** rotate.c
*/

void				rotate_point(t_fdf *fdf);

/*
**	color.c
*/

void				put_color(t_draw tmp, t_point *src,\
					t_point *dst, int *pixels);

/*
**	graphics_test.c
*/

t_crd				**val(int argc, char **argv, t_fdf *fdf);

void				write_lines(t_fdf *fdf, int fd);
void				ft_read_file(t_fdf *fdf, char *file_name);
void				free_arr(char **str);
void				put_points_right(t_fdf *fdf, int y, int x);
void				put_points_down(t_fdf *fdf, int y, int x);
double				get_percent(int z_min, int z_max, int z);

#endif
