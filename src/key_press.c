/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:27:59 by thaley            #+#    #+#             */
/*   Updated: 2019/10/14 19:08:16 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		goto_start_point(t_fdf *fdf, int task)
{
	if (task)
	{
		fdf->offset_x = WIN_WIDTH / 2;
		fdf->offset_y = WIN_HEIGHT / 2;
		fdf->scale = WIN_WIDTH / sqrt(fdf->col\
		* fdf->col + fdf->row * fdf->row);
	}
	else
	{
		fdf->offset_x = WIN_WIDTH / 2;
		fdf->offset_y = WIN_HEIGHT / 2;
		fdf->scale = WIN_WIDTH / sqrt(fdf->col\
		* fdf->col + fdf->row * fdf->row);
		fdf->scale_z = 1;
		fdf->angle_x = 0;
		fdf->angle_y = 0;
		fdf->angle_z = 0;
	}
}

int			key_press_rotate(int key, t_fdf *fdf)
{
	if (key == NUM_SEVEN)
		fdf->angle_x += 5;
	else if (key == NUM_NINE)
		fdf->angle_x -= 5;
	else if (key == NUM_FOUR)
		fdf->angle_y += 5;
	else if (key == NUM_SIX)
		fdf->angle_y -= 5;
	else if (key == NUM_ONE)
		fdf->angle_z += 5;
	else if (key == NUM_THREE)
		fdf->angle_z -= 5;
	else
		return (0);
	return (1);
}

int			key_press_offset_scale(int key, t_fdf *fdf)
{
	if (key == UP_K)
		fdf->offset_y -= 10;
	else if (key == DOWN_K)
		fdf->offset_y += 10;
	else if (key == LEFT_K)
		fdf->offset_x -= 10;
	else if (key == RIGHT_K)
		fdf->offset_x += 10;
	else if (key == PLUS_K)
		fdf->scale *= 1.05;
	else if (key == MINUS_K)
		fdf->scale *= 0.95;
	else if (key == NUM_TWO && fdf->scale_z < 100)
		fdf->scale_z += 1;
	else if (key == NUM_EIGHT && fdf->scale_z > 1)
		fdf->scale_z -= 1;
	else if (key == NUM_FIVE)
		goto_start_point(fdf, 1);
	else if (key == NUM_NULL)
		goto_start_point(fdf, 0);
	else
		return (0);
	return (1);
}

int			key_press(int key, t_fdf *fdf)
{
	if (key == ESC_K)
		ft_exit(fdf, 0);
	if (key_press_offset_scale(key, fdf) || key_press_rotate(key, fdf))
		draw_image(fdf);
	return (0);
}
