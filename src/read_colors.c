/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaeron-g <aaeron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:59:51 by aaeron-g          #+#    #+#             */
/*   Updated: 2019/10/16 14:09:16 by aaeron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int		pow_16(int n)
{
	int res;

	res = 1;
	while (n > 0)
	{
		res *= 16;
		n--;
	}
	return (res);
}

static int		ft_hexatoi(char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res += (((int)str[i] - 48) * pow_16(ft_strlen(str) - i));
		if (str[i] >= 'a' && str[i] <= 'f')
			res += (((int)str[i] - 87) * pow_16(ft_strlen(str) - i));
		if (str[i] >= 'A' && str[i] <= 'F')
			res += (((int)str[i] - 55) * pow_16(ft_strlen(str) - i));
		i++;
	}
	return (res);
}

static void		put_point_colors(t_fdf *fdf, int i, int j, char **tmp)
{
	fdf->crd[j][i].z = ft_atoi(tmp[0]);
	if (!tmp[1])
		fdf->crd[j][i].color = -1;
	else
		fdf->crd[j][i].color = ft_hexatoi(tmp[1] + 2);
	fdf->crd[j][i].x = i;
	fdf->crd[j][i].y = j;
	if (fdf->crd[j][i].z < fdf->low_p)
		fdf->low_p = fdf->crd[j][i].z;
	if (fdf->crd[j][i].z > fdf->top_p)
		fdf->top_p = fdf->crd[j][i].z;
}

void			read_colors(char *str, t_fdf *fdf, int j)
{
	int		i;
	char	**txt;
	char	**tmp;

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
		tmp = ft_strsplit(txt[i], ',');
		put_point_colors(fdf, i, j, tmp);
		free_arr(tmp);
		i++;
	}
	free_arr(txt);
}
