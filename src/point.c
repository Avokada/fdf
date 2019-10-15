/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 19:11:02 by thaley            #+#    #+#             */
/*   Updated: 2019/10/15 17:59:19 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int				point_color(int color, t_fdf *fdf, float z)
{
	double percent;

	if (color != -1)
		return (color);
	percent = get_percent(fdf->low_p, fdf->top_p, z);
	if (percent < 0.2)
		return (DARK_TURQUOISE);
	else if (percent < 0.4)
		return (MID_TURQUOISE);
	else if (percent < 0.6)
		return (GREEN);
	else if (percent < 0.8)
		return (YELLOW);
	else
		return (WHITE);
}

void			put_points_right(t_fdf *fdf, int y, int x)
{
	fdf->src.x = fdf->crd[y][x].x - fdf->col / 2;
	fdf->src.y = fdf->crd[y][x].y - fdf->row / 2;
	fdf->src.z = fdf->crd[y][x].z / fdf->scale_z;
	fdf->dst.x = fdf->crd[y][x + 1].x - fdf->col / 2;
	fdf->dst.y = fdf->crd[y][x + 1].y - fdf->row / 2;
	fdf->dst.z = fdf->crd[y][x + 1].z / fdf->scale_z;
	fdf->src.color = point_color(fdf->crd[y][x].color, fdf, fdf->src.z);
	fdf->dst.color = point_color(fdf->crd[y][x + 1].color, fdf, fdf->dst.z);
	rotate_point(fdf);
	fdf->src.x = fdf->src.x * fdf->scale + fdf->offset_x;
	fdf->src.y = fdf->src.y * fdf->scale + fdf->offset_y;
	fdf->dst.x = fdf->dst.x * fdf->scale + fdf->offset_x;
	fdf->dst.y = fdf->dst.y * fdf->scale + fdf->offset_y;
	draw_line(fdf->pixels, &fdf->src, &fdf->dst);
}

void			put_points_down(t_fdf *fdf, int y, int x)
{
	fdf->src.x = fdf->crd[y][x].x - fdf->col / 2;
	fdf->src.y = fdf->crd[y][x].y - fdf->row / 2;
	fdf->src.z = fdf->crd[y][x].z / fdf->scale_z;
	fdf->dst.x = fdf->crd[y + 1][x].x - fdf->col / 2;
	fdf->dst.y = fdf->crd[y + 1][x].y - fdf->row / 2;
	fdf->dst.z = fdf->crd[y + 1][x].z / fdf->scale_z;
	fdf->src.color = point_color(fdf->crd[y][x].color, fdf, fdf->src.z);
	fdf->dst.color = point_color(fdf->crd[y + 1][x].color, fdf, fdf->dst.z);
	rotate_point(fdf);
	fdf->src.x = fdf->src.x * fdf->scale + fdf->offset_x;
	fdf->src.y = fdf->src.y * fdf->scale + fdf->offset_y;
	fdf->dst.x = fdf->dst.x * fdf->scale + fdf->offset_x;
	fdf->dst.y = fdf->dst.y * fdf->scale + fdf->offset_y;
	draw_line(fdf->pixels, &fdf->src, &fdf->dst);
}
