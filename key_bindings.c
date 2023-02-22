/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bindings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgavioli <vgavioli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:44:35 by vgavioli          #+#    #+#             */
/*   Updated: 2022/10/17 15:41:32 by vgavioli         ###   ########.fr       */
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
