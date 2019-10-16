/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaeron-g <aaeron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:02:58 by aaeron-g          #+#    #+#             */
/*   Updated: 2019/10/16 14:07:30 by aaeron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void		put_point(t_fdf *fdf, int i, int j, int z)
{
	if (i > fdf->col)
		ft_exit(fdf, 3);
	fdf->crd[j][i].color = -1;
	fdf->crd[j][i].x = i;
	fdf->crd[j][i].y = j;
	fdf->crd[j][i].z = z;
	if (fdf->crd[j][i].z < fdf->low_p)
		fdf->low_p = fdf->crd[j][i].z;
	if (fdf->crd[j][i].z > fdf->top_p)
		fdf->top_p = fdf->crd[j][i].z;
}

static	void	reading(char *str, t_fdf *fdf, int j)
{
	int		i;
	char	**txt;

	txt = ft_strsplit(str, ' ');
	if (fdf->col == 0)
	{
		while (txt[fdf->col])
			fdf->col++;
	}
	i = 0;
	if (!(fdf->crd[j] = (t_crd *)malloc(sizeof(t_crd) * (fdf->col + 1))))
		ft_exit(fdf, 0);
	while (txt[i])
	{
		put_point(fdf, i, j, ft_atoi(txt[i]));
		i++;
	}
	fdf->crd[j + 1] = NULL;
	if (i < fdf->col)
		ft_exit(fdf, 3);
	free_arr(txt);
}

static void		put_row(char *text_map, t_fdf *fdf, int i)
{
	int		type;

	type = map_type(text_map);
	if (!type)
	{
		free(text_map);
		ft_exit(fdf, 3);
	}
	else if (type == 2)
		read_colors(text_map, fdf, i);
	else
		reading(text_map, fdf, i);
}

int				make_map(char *argv, t_fdf *fdf)
{
	char	*text_map;
	int		fd;
	int		gnl;
	int		i;

	gnl = 1;
	i = 0;
	fd = open(argv, O_RDWR);
	while (gnl != 0)
	{
		gnl = get_next_line(fd, &text_map);
		if (gnl == -1)
		{
			free(text_map);
			return (-1);
		}
		else if (gnl == 1)
			put_row(text_map, fdf, i);
		free(text_map);
		i++;
	}
	if (fdf->row < 2 || fdf->col < 2)
		ft_exit(fdf, 3);
	return (1);
}
