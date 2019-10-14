/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 19:11:02 by thaley            #+#    #+#             */
/*   Updated: 2019/10/14 19:11:34 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void			point_color(t_fdf *fdf, int y, int x, int scale)
{
	if (fdf->crd[y][x].color != 0)
		fdf->src.color = fdf->crd[y][x].color;
	else if (fdf->src.z <= 0)
		fdf->src.color = BLUE;
	else if (fdf->src.z <= 3)
		fdf->dst.color = MID_TURQUOISE;
	else if (fdf->src.z > 3 && fdf->src.z < 7)
		fdf->src.color = YELLOW;
	else
		fdf->src.color = WHITE;
	if (scale)
		x += 1;
	else
		y += 1;
	if (fdf->crd[y][x].color != 0)
		fdf->dst.color = fdf->crd[y][x].color;
	else if (fdf->dst.z <= 0)
		fdf->dst.color = BLUE;
	else if (fdf->dst.z <= 3)
		fdf->dst.color = MID_TURQUOISE;
	else if (fdf->dst.z > 3 && fdf->dst.z < 7)
		fdf->dst.color = YELLOW;
	else
		fdf->dst.color = WHITE;
}

static void		put_points_right(t_fdf *fdf, int y, int x)
{
	fdf->src.x = fdf->crd[y][x].x - fdf->col / 2;
	fdf->src.y = fdf->crd[y][x].y - fdf->row / 2;
	fdf->src.z = fdf->crd[y][x].z / fdf->scale_z;
	fdf->dst.x = fdf->crd[y][x + 1].x - fdf->col / 2;
	fdf->dst.y = fdf->crd[y][x + 1].y - fdf->row / 2;
	fdf->dst.z = fdf->crd[y][x + 1].z / fdf->scale_z;
	point_color(fdf, y, x, 1);
	rotate_point(fdf);
	fdf->src.x = fdf->src.x * fdf->scale + fdf->offset_x;
	fdf->src.y = fdf->src.y * fdf->scale + fdf->offset_y;
	fdf->dst.x = fdf->dst.x * fdf->scale + fdf->offset_x;
	fdf->dst.y = fdf->dst.y * fdf->scale + fdf->offset_y;
	draw_line(fdf->pixels, &fdf->src, &fdf->dst);
}

static void		put_points_down(t_fdf *fdf, int y, int x)
{
	fdf->src.x = fdf->crd[y][x].x - fdf->col / 2;
	fdf->src.y = fdf->crd[y][x].y - fdf->row / 2;
	fdf->src.z = fdf->crd[y][x].z / fdf->scale_z;
	fdf->dst.x = fdf->crd[y + 1][x].x - fdf->col / 2;
	fdf->dst.y = fdf->crd[y + 1][x].y - fdf->row / 2;
	fdf->dst.z = fdf->crd[y + 1][x].z / fdf->scale_z;
	point_color(fdf, y, x, 0);
	rotate_point(fdf);
	fdf->src.x = fdf->src.x * fdf->scale + fdf->offset_x;
	fdf->src.y = fdf->src.y * fdf->scale + fdf->offset_y;
	fdf->dst.x = fdf->dst.x * fdf->scale + fdf->offset_x;
	fdf->dst.y = fdf->dst.y * fdf->scale + fdf->offset_y;
	draw_line(fdf->pixels, &fdf->src, &fdf->dst);
}
