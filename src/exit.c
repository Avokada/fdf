/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:20:43 by thaley            #+#    #+#             */
/*   Updated: 2019/10/11 17:35:26 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		free_struct(t_fdf *fdf)
{
	if (fdf)
	{
		free(fdf);
	}
}

int			ft_exit(t_fdf *fdf, int err)
{
	if (!fdf)
		perror(NULL);
	else if (fdf && !err)
		free_struct(fdf);
	exit(0);
	return (0);
}
