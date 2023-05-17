/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bindings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgavioli <vgavioli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:44:35 by vgavioli          #+#    #+#             */
/*   Updated: 2023/05/16 23:01:54 by vgavioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//pfn("[key	]: %d", key);

int	key_hook(int key, t_gm *gm)
{
	
	if (!gm->death && !gm->won && !gm->hero.moving)
	{
		if (key == KEY_W || key == ARR_UP)
			player_move(gm, 'u', 0);
		if (key == KEY_S || key == ARR_DOWN)
			player_move(gm, 'd', 0);
		if (key == KEY_D || key == ARR_RIGHT)
			player_move(gm, 'r', 0);
		if (key == KEY_A || key == ARR_LEFT)
			player_move(gm, 'l', 0);
	}
	if (key == KEY_ESC)
		exit_game(gm);
	return (0);
}

int	linux_key_hook(int key, t_gm *gm)
{
	if (!gm->death && !gm->won && !gm->hero.moving)
	{
		if (key == KEY_W_L || key == ARR_UP_L)
			player_move(gm, 'u', 0);
		if (key == KEY_S_L || key == ARR_DOWN_L)
			player_move(gm, 'd', 0);
		if (key == KEY_D_L || key == ARR_RIGHT_L)
			player_move(gm, 'r', 0);
		if (key == KEY_A_L || key == ARR_LEFT_L)
			player_move(gm, 'l', 0);
	}
	if (key == KEY_ESC_L)
		exit_game(gm);
	return (0);
}
