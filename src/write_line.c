/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaeron-g <aaeron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 23:57:49 by thaley            #+#    #+#             */
/*   Updated: 2019/10/16 14:09:01 by aaeron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		free_arr(char **str)
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
		if (fdf->crd[fdf->row][i].z > fdf->top_p)
			fdf->top_p = fdf->crd[fdf->row][i].z;
		if (fdf->crd[fdf->row][i].z < fdf->low_p)
			fdf->low_p = fdf->crd[fdf->row][i].z;
		fdf->crd[fdf->row][i].color = 0;
		i++;
	}
}

void		write_lines(t_fdf *fdf, int fd)
{
	char	*line;
	char	**tmp;

	fdf->row = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		tmp = ft_strsplit(line, ' ');
		free(line);
		line = NULL;
		write_x_z(tmp, fdf);
		free_arr(tmp);
		fdf->row++;
	}
	free(line);
	fdf->crd[fdf->row] = NULL;
}
