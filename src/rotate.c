/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:14:20 by thaley            #+#    #+#             */
/*   Updated: 2019/10/11 21:48:57 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	rotate_around_x(t_point *src, int angle, float degree)
{
	float	radian;
	float	cos;
	float	sin;
	float	z;
	float	y;

	radian = degree * angle;
	z = src->z;
	y = src->y;
	cos = cosf(radian);
	sin = sinf(radian);
	src->y = y * cos - z * sin;
	src->z = y * sin + z * cos;
}

static void	rotate_around_y(t_point *src, int angle, float degree)
{
	float	radian;
	float	cos;
	float	sin;
	float	z;
	float	x;

	radian = degree * angle;
	z = src->z;
	x = src->x;
	cos = cosf(radian);
	sin = sinf(radian);
	src->x = x * cos + z * sin;
	src->z = -x * sin + z * cos;
}

static void	rotate_around_z(t_point *src, int angle, float degree)
{
	float	radian;
	float	cos;
	float	sin;
	float	y;
	float	x;

	radian = degree * angle;
	x = src->x;
	y = src->y;
	cos = cosf(radian);
	sin = sinf(radian);
	src->x = x * cos - y * sin;
	src->y = x * sin + y * cos;
}

void		rotate_point(t_fdf *fdf)
{
	if (fdf->angle_x)
	{
		rotate_around_x(&fdf->src, fdf->angle_x, fdf->degree);
		rotate_around_x(&fdf->dst, fdf->angle_x, fdf->degree);
	}
	if (fdf->angle_y)
	{
		rotate_around_y(&fdf->src, fdf->angle_y, fdf->degree);
		rotate_around_y(&fdf->dst, fdf->angle_y, fdf->degree);
	}
	if (fdf->angle_z)
	{
		rotate_around_z(&fdf->src, fdf->angle_z, fdf->degree);
		rotate_around_z(&fdf->dst, fdf->angle_z, fdf->degree);
	}
}
