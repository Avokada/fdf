/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaeron-g <aaeron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 19:09:14 by thaley            #+#    #+#             */
/*   Updated: 2019/10/15 17:08:40 by aaeron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static double	get_percent(int z_min, int z_max, int z)
{
	double place;
	double dist;
	double ret;

	ret = 1.0;
	place = z - z_min;
	dist = z_max - z_min;
	if (dist != 0)
		ret = place / dist;
	return (ret);
}

int				get_color_with_z(int color, t_fdf *fdf, float z)
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

static int		change_color(int src, int dst, float percent)
{
	int ret;

	ret = (1 - percent) * src + percent * dst;
	return (ret);
}

int				get_color(t_draw t, t_point *src, t_point *dst)
{
	int		red;
	int		green;
	int		blue;
	double	percent;

	if (t.tmp.color == dst->color)
		return (t.tmp.color);
	if (t.lenght_x > t.lenght_y)
		percent = get_percent(src->x, dst->x, t.tmp.x);
	else
		percent = get_percent(src->y, dst->y, t.tmp.y);
	red = change_color((src->color >> 16) & 0xFF,\
				(dst->color >> 16) & 0xFF, percent);
	green = change_color((src->color >> 8) & 0xFF,\
				(dst->color >> 8) & 0xFF, percent);
	blue = change_color(src->color & 0xFF, dst->color & 0xFF, percent);
	return ((red << 16) | (green << 8) | blue);
}

void			put_color(t_draw tmp, t_point *src, t_point *dst, int *pixels)
{
	while (tmp.step > 0)
	{
		if ((int)tmp.tmp.x >= 0 && (int)tmp.tmp.x < WIN_WIDTH\
			&& (int)tmp.tmp.y >= 0 && (int)tmp.tmp.y < WIN_HEIGHT)
			pixels[(int)tmp.tmp.x + (int)tmp.tmp.y\
			* WIN_WIDTH] = get_color(tmp, src, dst);
		tmp.tmp.x += tmp.step_x;
		tmp.tmp.y += tmp.step_y;
		tmp.step--;
	}
}
