/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duplicated_x_element.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgavioli <vgavioli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:26:10 by arctia            #+#    #+#             */
/*   Updated: 2022/10/17 15:16:55 by vgavioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_duplicated_s_element(char **mat)
{
	int	i;
	int	j;

	i = -1;
	while (mat[++i])
	{
		j = i;
		while (mat[++j])
		{
			if (ft_strcmp(mat[i], mat[j]))
				return (1);
		}
	}
	return (0);
}


int	ft_duplicated_i_element(int	*array)
{
	int	i;
	int	j;

	i = -1;
	while (array[++i])
	{
		j = i;
		while (array[++j])
		{
			if (array[i] == array[j])
				return (1);
		}
	}
	return (0);
}
