/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:44:54 by thaley            #+#    #+#             */
/*   Updated: 2019/10/12 17:19:15 by thaley           ###   ########.fr       */
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

void	put_color(t_draw tmp, t_point *src, t_point *dst, int *pixels)
{
	while (tmp.step > 0)
	{
		if ((int)tmp.tmp.x >= 0 && (int)tmp.tmp.x < WIN_WIDTH\
			&& (int)tmp.tmp.y >= 0 && (int)tmp.tmp.y < WIN_HEIGHT)
		{
			if (tmp.tmp.z <= 2)
				pixels[(int)tmp.tmp.x + (int)tmp.tmp.y * WIN_WIDTH] = 0x330055;
			else
				pixels[(int)tmp.tmp.x + (int)tmp.tmp.y * WIN_WIDTH] = 0x9988AA;
		}
		tmp.tmp.x += tmp.step_x;
		tmp.tmp.y += tmp.step_y;
		tmp.step--;
	}
}

void	draw_line(int *pixels, t_point *src, t_point *dst)
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

static void	put_points_right(t_fdf *fdf, int y, int x)
{
	fdf->src.x = fdf->crd[y][x].x - fdf->col / 2;
	fdf->src.y = fdf->crd[y][x].y - fdf->row / 2;
	fdf->src.z = fdf->crd[y][x].z / fdf->scale_z;
	fdf->dst.x = fdf->crd[y][x + 1].x - fdf->col / 2;
	fdf->dst.y = fdf->crd[y][x + 1].y - fdf->row / 2;
	fdf->dst.z = fdf->crd[y][x + 1].z / fdf->scale_z;
	rotate_point(fdf);
	fdf->src.x = fdf->src.x * fdf->scale + fdf->offset_x;
	fdf->src.y = fdf->src.y * fdf->scale + fdf->offset_y;
	fdf->dst.x = fdf->dst.x * fdf->scale + fdf->offset_x;
	fdf->dst.y = fdf->dst.y * fdf->scale + fdf->offset_y;
	draw_line(fdf->pixels, &fdf->src, &fdf->dst);
}

static void	put_points_down(t_fdf *fdf, int y, int x)
{
	fdf->src.x = fdf->crd[y][x].x - fdf->col / 2;
	fdf->src.y = fdf->crd[y][x].y - fdf->row / 2;
	fdf->src.z = fdf->crd[y][x].z / fdf->scale_z;
	fdf->dst.x = fdf->crd[y + 1][x].x - fdf->col / 2;
	fdf->dst.y = fdf->crd[y + 1][x].y - fdf->row / 2;
	fdf->dst.z = fdf->crd[y + 1][x].z / fdf->scale_z;
	rotate_point(fdf);
	fdf->src.x = fdf->src.x * fdf->scale + fdf->offset_x;
	fdf->src.y = fdf->src.y * fdf->scale + fdf->offset_y;
	fdf->dst.x = fdf->dst.x * fdf->scale + fdf->offset_x;
	fdf->dst.y = fdf->dst.y * fdf->scale + fdf->offset_y;
	draw_line(fdf->pixels, &fdf->src, &fdf->dst);
}

static void	draw_line_right(t_fdf *fdf)
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
				put_points_right(fdf, i , j);
			j++;
		}
		i++;
	}
}


static void	draw_line_down(t_fdf *fdf)
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

void		draw_image(t_fdf *fdf)
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
