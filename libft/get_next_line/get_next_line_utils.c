/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arctia <arctia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:05:14 by vgavioli          #+#    #+#             */
/*   Updated: 2022/06/16 14:04:16 by arctia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	line_len_n(char *str)
{
	int	i;

	i = 0;
	while (!(str[i] == '\n' || str[i] == '\0'))
		i++;
	return (i);
}

size_t	gnl_strlen(char	*str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*free_buffer(char *buffer)
{
	if (buffer)
		free(buffer);
	return (NULL);
}

char	*gnl_strchr(char *s, int c)
{
	char	*ptr;

	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[gnl_strlen(s)]);
	ptr = (char *)s;
	while (*ptr != (unsigned char)(c))
	{
		if (*ptr == '\0')
			return (NULL);
		ptr++;
	}
	return (ptr);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = (char *) malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) +1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	free(s1);
	str[i] = 0;
	return (str);
}
