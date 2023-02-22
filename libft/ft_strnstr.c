/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgavioli <vgavioli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:57:17 by vgavioli          #+#    #+#             */
/*   Updated: 2022/02/08 12:38:34 by vgavioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s2);
	if (s1[0] == 0 && s2[0] != 0)
		return (NULL);
	if (!s2[0] || !s1[0])
	{
		if (ft_strncmp((const char *)(s1 + i), s2, j) == 0)
			return ((char *)(s1 + i));
	}
	while (i + j <= n)
	{
		if (ft_strncmp((const char *)(s1 + i), s2, j) == 0)
			return ((char *)(s1 + i));
		i++;
	}
	return (NULL);
}
