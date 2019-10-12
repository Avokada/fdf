/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:04:35 by thaley            #+#    #+#             */
/*   Updated: 2019/10/12 17:38:55 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*cpdst;
	size_t	i;
	size_t	count;

	i = 0;
	count = len;
	cpdst = dst;
	while (src[i] != '\0')
		i++;
	while (count-- && *src != '\0')
		*cpdst++ = *src++;
	while (i < len)
	{
		*cpdst++ = '\0';
		i++;
	}
	return (dst);
}
