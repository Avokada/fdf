/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 23:57:49 by thaley            #+#    #+#             */
/*   Updated: 2019/10/12 17:04:21 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	free_struct(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

static void	write_x_z(char **str, t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (fdf->col == 0)
	{
		while (str[fdf->col])
			fdf->col++;
	}
	fdf->crd[fdf->row] = (t_crd *)malloc(sizeof(t_crd) * (fdf->col + 1));
	while (str[i])
	{
		fdf->crd[fdf->row][i].y = fdf->row;
		fdf->crd[fdf->row][i].x = i;
		fdf->crd[fdf->row][i].z = ft_atoi(str[i]);
		i++;
	}
}

void	write_lines(t_fdf *fdf, int fd)
{
	char	*line;
	char	**tmp;

	fdf->row = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		tmp = ft_strsplit(line, ' ');
		write_x_z(tmp, fdf);
		free_struct(tmp);
		fdf->row++;
	}
	fdf->crd[fdf->row] = NULL;
}
