/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:04:28 by thaley            #+#    #+#             */
/*   Updated: 2019/10/12 17:08:48 by thaley           ###   ########.fr       */
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
# define NUM_1 83
# define NUM_2 84
# define NUM_3 85
# define NUM_4 86
# define NUM_5 87
# define NUM_6 88
# define NUM_7 89
# define NUM_8 91
# define NUM_9 92
# define PLUS_K 69
# define MINUS_K 78

typedef struct		s_crd
{
	int				x;
	int				y;
    int				z;
    int        		color;
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
	int				pix_inf[3];
	int				*pixels;
	int				col;
	int				row;
	int				offset_x;
	int				offset_y;
	int				scale_z;
	int				angle_x;
	int				angle_y;
	int				angle_z;
	char			*prog_name;
}					t_fdf;

/*
**	exit.c
*/

int					ft_exit(t_fdf *fdf, int err);

/*
**	key_press.c
*/

int					key_press(int key, t_fdf *fdf);

/*
**	draw.c
*/

void				draw_image(t_fdf *fdf);

/*
** rotate.c
*/

void				rotate_point(t_fdf *fdf);

void				write_lines(t_fdf *fdf, int fd);
void	ft_read_file(t_fdf *fdf, char *file_name);

#endif
