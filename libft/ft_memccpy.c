/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 21:30:02 by thaley            #+#    #+#             */
/*   Updated: 2019/10/12 17:38:55 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*cpdst;
	unsigned char	*cpsrc;

	cpdst = (unsigned char *)dst;
	cpsrc = (unsigned char *)src;
	i = 0;
	while (n > i)
	{
		cpdst[i] = cpsrc[i];
		if (cpsrc[i] == (unsigned char)c)
			return ((void *)(dst + i + 1));
		i++;
	}
	return (NULL);
}
