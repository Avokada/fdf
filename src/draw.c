/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:44:54 by thaley            #+#    #+#             */
/*   Updated: 2019/10/14 19:11:28 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
** fabs - абсолютная величина
** 1) take  coordinates
** 2) rotate_point
** 3) offset to mid point
** 4) draw line
*/

void			draw_line(int *pixels, t_point *src, t_point *dst)
{
	t_draw	line;

	line.lenght_x = dst->x - src->x;
	line.lenght_y = dst->y - src->y;
	if (fabsf(line.lenght_x) >= fabsf(line.lenght_y))
	{
		if (line.lenght_x >= 0)
			line.step_x = 1;
		else
			line.step_x = -1;
		line.step_y = line.lenght_y / fabsf(line.lenght_x);
		line.step = abs((int)line.lenght_x);
	}
	else
	{
		if (line.lenght_y >= 0)
			line.step_y = 1;
		else
			line.step_y = -1;
		line.step_x = line.lenght_x / fabsf(line.lenght_y);
		line.step = abs((int)line.lenght_y);
	}
	line.tmp = (t_point){src->x, src->y, src->z, src->color};
	put_color(line, src, dst, pixels);
}

static void		draw_line_right(t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->row)
	{
		j = 0;
		while (j < fdf->col)
		{
			if (j < fdf->col - 1)
				put_points_right(fdf, i, j);
			j++;
		}
		i++;
	}
}

static void		draw_line_down(t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->row)
	{
		j = 0;
		while (j < fdf->col)
		{
			if (i < fdf->row - 1)
				put_points_down(fdf, i, j);
			j++;
		}
		i++;
	}
}

void			draw_image(t_fdf *fdf)
{
	int		i;

	i = 0;
	while (i < WIN_HEIGHT * WIN_WIDTH)
	{
		fdf->pixels[i] = 0;
		i++;
	}
	draw_line_right(fdf);
	draw_line_down(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image, 0, 0);
}
