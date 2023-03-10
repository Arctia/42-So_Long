/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgavioli <vgavioli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:27:41 by vgavioli          #+#    #+#             */
/*   Updated: 2022/10/17 14:22:55 by vgavioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return (1);
	else if (ch >= 'a' && ch <= 'z')
		return (1);
	else if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}
