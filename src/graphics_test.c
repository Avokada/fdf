/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaeron-g <aaeron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:00:15 by aaeron-g          #+#    #+#             */
/*   Updated: 2019/10/16 14:02:43 by aaeron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int		is_space(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f')\
	|| (c >= 'A' && c <= 'F'))
		return (1);
	return (0);
}

void			map_free(t_crd **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(*map);
}

static int		num_items(char *str, int type)
{
	int	res;
	int i;

	res = 0;
	i = 1;
	if (type == 1)
	{
		while (str[i] && str[i - 1])
		{
			if (str[i] == ' ' && str[i - 1] >= '0' && str[i - 1] <= '9')
				res++;
			i++;
		}
	}
	else
	{
		while (str[i] && str[i - 1])
		{
			if (str[i] == ' ' && is_space(str[i - 1]))
				res++;
			i++;
		}
	}
	res++;
	return (res);
}

static int		count_lines(char *argv)
{
	int		fd;
	int		gnl;
	int		lines;
	char	*text_map;

	gnl = 1;
	lines = 0;
	fd = open(argv, O_RDWR);
	while (gnl != 0)
	{
		text_map = NULL;
		gnl = get_next_line(fd, &text_map);
		if (gnl == -1)
		{
			free(text_map);
			return (-1);
		}
		lines++;
		free(text_map);
	}
	close(fd);
	return (lines - 1);
}

t_crd			**val(int argc, char **argv, t_fdf *fdf)
{
	int		fd;
	int		gnl;
	int		makemap;

	if (argc != 2)
		ft_exit(fdf, 2);
	fdf->row = count_lines(argv[1]);
	if (!(fdf->crd = (t_crd **)malloc(sizeof(t_crd *) * (fdf->row + 1))))
		ft_exit(fdf, 0);
	ft_bzero(fdf->crd, fdf->row);
	makemap = make_map(argv[1], fdf);
	if (makemap == -1)
		ft_exit(fdf, 3);
	return (fdf->crd);
}
