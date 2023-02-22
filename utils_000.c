/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_000.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgavioli <vgavioli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:18:33 by vgavioli          #+#    #+#             */
/*   Updated: 2022/06/20 12:24:58 by vgavioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	info(char *str)
{
	ft_printf("[INFO	]: %s\n", str);
	return (1);
}

int	info_free(char *str)
{
	ft_printf("[INFO	]: %s\n", str);
	free(str);
	return (1);
}

int	pf_error(char *str)
{
	ft_printf("Error\n%s\n", str);
	exit(0);
	return (1);
}

int	count_char(char *str, char c)
{
	int	i;
	int	cou;

	i = 0;
	cou = 0;
	while (str[cou])
	{
		if (c == str[cou++])
			i++;
	}
	return (i);
}

char	*so_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (s1 == NULL)
		str = malloc(sizeof(char) * (ft_strlen(s2) + 1));
	else
		str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = 0;
	free(s1);
	free(s2);
	return (str);
}
