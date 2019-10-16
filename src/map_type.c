/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaeron-g <aaeron-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:55:15 by aaeron-g          #+#    #+#             */
/*   Updated: 2019/10/16 14:07:49 by aaeron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	ft_ishex(char c)
{
	if ((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
		return (1);
	return (0);
}

static int	ft_iscolor(char *str)
{
	int	i;
	int	caps;

	i = 2;
	caps = 0;
	if (!str[0] || !str[7])
		return (0);
	if ((str[0] && str[0] != '0') || !str[1] || (str[1] && str[1] != 'x'))
		return (0);
	while (str[i] && i < 8)
	{
		if (!ft_ishex(str[i]) && !ft_isdigit(str[i]))
			return (0);
		if (str[i] >= 'a' && str[i] <= 'f' && caps == 0)
			caps = -1;
		if (str[i] >= 'A' && str[i] <= 'F' && caps == 0)
			caps = 1;
		if (str[i] >= 'a' && str[i] <= 'f' && caps == 1)
			return (0);
		if (str[i] >= 'A' && str[i] <= 'F' && caps == -1)
			return (0);
		i++;
	}
	return (1);
}

int			map_type(char *text_map)
{
	int	i;
	int	type;

	i = 0;
	type = 1;
	while (text_map[i])
	{
		if (text_map[i] != ' ' && text_map[i] != ','\
		&& ((!ft_isdigit(text_map[i])\
		&& (text_map[i] == '-' && !ft_isdigit(text_map[i + 1])))))
			return (0);
		else if (text_map[i] == ',')
		{
			if (text_map[i + 1] && ft_iscolor(text_map + i + 1))
			{
				i += 7;
				type = 2;
			}
			else
				return (0);
		}
		i++;
	}
	return (type);
}
