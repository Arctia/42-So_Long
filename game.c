/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgavioli <vgavioli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:30:32 by vgavioli          #+#    #+#             */
/*   Updated: 2023/05/16 23:02:05 by vgavioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_gm *gm)
{
	main_free(gm);
	exit(0);
	return (1);
}

void	refresh_sprites_frame(t_gm *gm)
{
	gm->refresh = 0;
	if (!(gm->frame % FRAME_RATE))
	{
		gm->images.wisp_cf++;
		if (gm->images.wisp_cf >= WISP_FRAMES)
			gm->images.wisp_cf = 0;
		gm->refresh = 1;
	}
	if (!(gm->frame % (FRAME_RATE)))
	{
		gm->images.coll_cf++;
		if (gm->images.coll_cf >= COLL_FRAMES)
			gm->images.coll_cf = 0;
		gm->refresh = 1;
	}
	refresh_hero(gm, &gm->hero);
}

int	update(t_gm *gm)
{
	gm->frame++;
	if (gm->frame > FRAME_RATE * 10)
		gm->frame = 0;
	refresh_sprites_frame(gm);
	if (gm->refresh)
	{
		draw_game_map(gm);
		draw_moves(*gm);
	}
	if (gm->death && !gm->deathd)
	{
		gm->deathd = 1;
		draw_death(*gm);
	}
	if (gm->won && !gm->wond)
	{
		gm->wond = 1;
		draw_won(*gm);
	}
	return (0);
}

void	game_init(char **map, t_map *field)
{
	t_gm	game;
	int		h;
	int		w;

	w = field->cols + 2;
	h = field->rows + 2;
	game.field = *field;
	game.map = map;
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, SZ * w, SZ * h, "Last Slime");
	init_game_struct(&game);
	//pfn("MY_OS: %d", MY_OS);
	if (MY_OS == 1)
	{
		mlx_hook(game.mlx_win, KeyPress, KeyPressMask, linux_key_hook, &game);
		mlx_hook(game.mlx_win, 17L, 0L, exit_game, &game);
	}
	else
	{
		mlx_key_hook(game.mlx_win, key_hook, &game);
		mlx_hook(game.mlx_win, 17, 0, exit_game, &game);
	}
	mlx_loop_hook(game.mlx, update, &game);
	draw_game_map(&game);
	mlx_do_key_autorepeaton(game.mlx);
	mlx_loop(game.mlx);
}
