/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 19:17:16 by thaley            #+#    #+#             */
/*   Updated: 2019/06/26 18:30:31 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_new;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (!(s_new = ft_strnew(ft_strlen(s1)
		+ ft_strlen(s2))))
		return (NULL);
	while (s1 && s1[++i] != '\0')
	{
		s_new[j] = s1[i];
		j++;
	}
	i = -1;
	while (s2 && s2[++i] != '\0')
	{
		s_new[j] = s2[i];
		j++;
	}
	return (s_new);
}
