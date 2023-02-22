/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arctia <arctia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:09:10 by vgavioli          #+#    #+#             */
/*   Updated: 2022/07/01 21:57:10 by arctia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	char		*start;
	char		*seg;
	va_list		valist;
	t_pflags	tf;

	tf.dimension = 0;
	seg = (char *) str;
	va_start(valist, str);
	while (*seg)
	{
		reset_struct(&tf);
		start = seg;
		seg = find_percent(seg);
		print_previous_part(start, seg - start, &tf);
		seg = set_flags(seg, &tf);
		check_flags(&tf);
		print_element(&tf, valist);
	}
	va_end(valist);
	return (tf.dimension);
}

int	pfn(const char *str, ...)
{
	char		*start;
	char		*seg;
	va_list		valist;
	t_pflags	tf;

	tf.dimension = 0;
	seg = (char *) str;
	va_start(valist, str);
	while (*seg)
	{
		reset_struct(&tf);
		start = seg;
		seg = find_percent(seg);
		print_previous_part(start, seg - start, &tf);
		seg = set_flags(seg, &tf);
		check_flags(&tf);
		print_element(&tf, valist);
	}
	write(1, "\n", 1);
	va_end(valist);
	return (tf.dimension + 1);
}
