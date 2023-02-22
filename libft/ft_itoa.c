/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arctia <arctia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:48:28 by vgavioli          #+#    #+#             */
/*   Updated: 2022/07/10 12:27:59 by arctia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	calc_digits(int n)
{
	int	digits;

	digits = 1;
	while ((n / 10) > 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

int	calc_sign(int *n)
{
	int	sign;

	sign = 0;
	if (*n < 0)
	{
		sign = 1;
		*n *= -1;
	}
	return (sign);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digits;
	int		sign;
	int		i;

	str = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648\0"));
	sign = calc_sign(&n);
	digits = calc_digits(n) + sign;
	str = (char *) malloc(sizeof(char) * (digits + 1));
	if (!str)
		return (NULL);
	if (sign == 1)
		str[0] = '-';
	i = digits - 1;
	while (i >= sign)
	{
		str[i] = (char)(n % 10) + '0';
		n /= 10;
		i--;
	}
	str[digits] = '\0';
	return (str);
}
