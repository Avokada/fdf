/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaeron-g <aaeron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:05:46 by thaley            #+#    #+#             */
/*   Updated: 2019/10/15 17:20:26 by aaeron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void		init_struct(t_fdf *fdf)
{
	fdf->col = 0;
	fdf->row = 0;
	fdf->angle_x = 0;
	fdf->angle_y = 0;
	fdf->angle_z = 0;
	fdf->offset_x = WIN_WIDTH / 2;
	fdf->offset_y = WIN_HEIGHT / 2;
	fdf->scale_z = 1;
	fdf->low_p = 0;
	fdf->top_p = 0;
	fdf->degree = 2 * M_PI / 360;
	ft_bzero(fdf->pix_inf, 3);
	fdf->mlx = mlx_init();
	fdf->window = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	fdf->image = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	fdf->pixels = (int *)mlx_get_data_addr(fdf->image, &fdf->pix_inf[0],\
	&fdf->pix_inf[1], &fdf->pix_inf[2]);
}

void			check_input(int argc, char **argv, t_fdf *fdf)
{
	int fd;

	fd = 0;
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
	{
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	close(fd);
}

int				main(int argc, char **argv)
{
	t_fdf	*fdf;

	check_input(argc, argv, fdf);
	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		ft_exit(NULL, 0);
	fdf->prog_name = argv[0];
	init_struct(fdf);
	fdf->crd = val(argc, argv, fdf);
	fdf->scale = WIN_WIDTH / sqrt(fdf->col * fdf->col + fdf->row * fdf->row);
	draw_image(fdf);
	mlx_hook(fdf->window, 2, 0, key_press, fdf);
	mlx_hook(fdf->window, 17, 0, ft_exit, fdf);
	mlx_loop(fdf->mlx);
	free_struct(fdf);
	return (0);
}
