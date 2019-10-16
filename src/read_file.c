/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaeron-g <aaeron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 22:57:49 by thaley            #+#    #+#             */
/*   Updated: 2019/10/16 14:11:14 by aaeron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		count_lines(t_fdf *fdf, char *file_name)
{
	int		fd;
	int		ret;
	int		count;
	char	buf;

	ret = 1;
	count = 0;
	fd = open(file_name, O_RDONLY);
	while ((read(fd, &buf, 1)))
	{
		if (buf == '\n')
			count++;
	}
	if (count < 2)
		ft_exit(fdf, 0);
	close(fd);
	return (count);
}

void	ft_read_file(t_fdf *fdf, char *file_name)
{
	int y;
	int fd;

	y = 1;
	fd = 0;
	fdf->row = count_lines(fdf, file_name);
	if (!(fdf->crd = (t_crd **)malloc(sizeof(t_point *)\
						* (fdf->row + 1))))
		ft_exit(fdf, 0);
	fd = open(file_name, O_RDONLY);
	write_lines(fdf, fd);
	close(fd);
}
