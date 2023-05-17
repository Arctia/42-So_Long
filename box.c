/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgavioli <vgavioli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:25:39 by vgavioli          #+#    #+#             */
/*   Updated: 2023/05/17 10:41:56 by vgavioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_not_obstacle(char obj)
{
	if (obj != '0' && obj != 'P')
		return 0;
	return 1;
}

int		is_box_near_obstacle(t_gm *gm, int x, int y, char dir)
{
	if (gm->map[y][x] != 'B')
		return 0;
	if (dir == 'u')
		y--;
	else if (dir == 'd')
		y++;
	else if (dir == 'r')
		x++;
	else if (dir == 'l')
		x--;
	if (is_not_obstacle(gm->map[y][x]))
		return (0);
	return (1);
}

void	move_box(t_gm *gm, int x, int y, char dir)
{
	gm->map[y][x] = '0';
	if (dir == 'u')
		y--;
	else if (dir == 'd')
		y++;
	else if (dir == 'r')
		x++;
	else if (dir == 'l')
		x--;
	gm->map[y][x] = 'B';
}
