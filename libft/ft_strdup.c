/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 05:08:47 by thaley            #+#    #+#             */
/*   Updated: 2019/07/03 15:47:57 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*scp;

	i = 0;
	if (!s1)
		return (NULL);
	if (!(scp = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	i = 0;
	while (*(s1 + i) != '\0')
	{
		*(scp + i) = *(s1 + i);
		i++;
	}
	*(scp + i++) = '\0';
	return (scp);
}
