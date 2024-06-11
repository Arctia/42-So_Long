/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arctia <arctia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:30:32 by vgavioli          #+#    #+#             */
/*   Updated: 2024/06/11 18:51:06 by arctia           ###   ########.fr       */
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
	if (gm->death)
		draw_death(*gm);
	if (gm->won)
		draw_won(*gm);
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
	game.window = new_window(SZ * h, SZ * w, "Last Slime");
	game.bg = new_background_img((game.window), SZ * w, SZ * h);
	game.mlx_win = game.window->win_ptr;
	game.mlx = game.window->mlx_ptr;
	init_game_struct(&game);
	pfn("MY_OS: %d", MY_OS);
	if (MY_OS == 1)
	{
		mlx_hook(game.window->win_ptr, KeyPress, KeyPressMask, linux_key_hook, &game);
		mlx_hook(game.window->win_ptr, 17L, 0, exit_game, &game);
	}
	else
	{
		mlx_key_hook(game.window->win_ptr, key_hook, &game);
		mlx_hook(game.window->win_ptr, 17, 0, exit_game, &game);
	}
	mlx_loop_hook(game.window->mlx_ptr, update, &game);
	draw_game_map(&game);
	mlx_do_key_autorepeaton(game.window->mlx_ptr);
	mlx_loop(game.window->mlx_ptr);
}
