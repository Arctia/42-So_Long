/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgavioli <vgavioli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:19:09 by vgavioli          #+#    #+#             */
/*   Updated: 2022/02/04 14:12:43 by vgavioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// src and dest must be null terminated!!
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	c;
	size_t	i;
	size_t	s;
	size_t	cs;

	cs = ft_strlen(dst);
	s = ft_strlen(src);
	c = cs;
	i = 0;
	if (cs > dstsize)
		cs = dstsize;
	if (cs < (dstsize - 1) && dstsize > 0)
	{
		while (src[i] && (cs + i < dstsize - 1))
		{
			dst[c] = src[i];
			c++;
			i++;
		}
		dst[c] = 0;
	}
	return (cs + s);
}
