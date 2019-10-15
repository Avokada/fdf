/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaeron-g <aaeron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:20:43 by thaley            #+#    #+#             */
/*   Updated: 2019/10/15 16:36:42 by aaeron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		free_struct(t_fdf *fdf)
{
	int		i;

	i = 0;
	if (fdf)
	{
		if (fdf->crd)
		{
			while (fdf->crd[i] && i < fdf->row)
			{
				free(fdf->crd[i]);
				i++;
			}
			free(fdf->crd);
		}
		free(fdf);
	}
}

int			ft_exit(t_fdf *fdf, int err)
{
	if (!fdf)
		perror(NULL);
	else if (err == 3)
	{
		ft_putstr(fdf->prog_name);
		ft_putendl(": Invalid map.");
	}
	if (fdf)
		free_struct(fdf);
	exit(0);
	return (0);
}
