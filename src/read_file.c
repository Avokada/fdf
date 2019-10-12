/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:03:09 by rfrankly          #+#    #+#             */
/*   Updated: 2019/10/11 20:34:42 by thaley           ###   ########.fr       */
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

// void	check_coord_mass_len(char **line_coord, t_map *map)
// {
// 	int i;

// 	i = -1;
// 	while (line_coord[++i])
// 		;
// 	if (map->first_line_len != i)
// 		exit_invalid_map();
// }

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
