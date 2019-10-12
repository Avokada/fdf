/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:27:59 by thaley            #+#    #+#             */
/*   Updated: 2019/10/12 17:13:48 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			key_press(int key, t_fdf *fdf)
{
	printf("%d\n", key);
	if (key == ESC_K)
		ft_exit(fdf, 0);
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
	else if (key == NUM_7)
		fdf->angle_x += 5;
	else if (key == NUM_9)
		fdf->angle_x -= 5;
	else if (key == NUM_4)
		fdf->angle_y += 5;
	else if (key == NUM_6)
		fdf->angle_y -= 5;
	else if (key == NUM_1)
		fdf->angle_z += 5;
	else if (key == NUM_3)
		fdf->angle_z -= 5;
	else
		return (0);
	draw_image(fdf);
	return (1);
}
