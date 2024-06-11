/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arctia <arctia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:32:05 by vgavioli          #+#    #+#             */
/*   Updated: 2024/06/11 18:40:56 by arctia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_hero(t_hero *i, t_window win)
{
	int	w;
	int	h;

	w = SZ;
	h = SZ;
	i->right[0] = new_file_img("res/move_r0.xpm", win);
	i->right[1] = new_file_img("res/move_r1.xpm", win);
	i->right[2] = new_file_img("res/move_r2.xpm", win);
	i->right[3] = new_file_img("res/move_r3.xpm", win);
	i->right[4] = new_file_img("res/move_r4.xpm", win);
	i->left[0] = new_file_img("res/move_l0.xpm", win);
	i->left[1] = new_file_img("res/move_l1.xpm", win);
	i->left[2] = new_file_img("res/move_l2.xpm", win);
	i->left[3] = new_file_img("res/move_l3.xpm", win);
	i->left[4] = new_file_img("res/move_l4.xpm", win);
	i->idle = new_file_img("res/standby.xpm", win);
	i->direction = 'n';
	i->pre_dir = 'r';
	i->reach_x = 0;
	i->reach_y = 0;
	i->moving = 0;
	i->frame = 0;
	i->maxf = 4;
	i->posx = 0;
	i->posy = 0;
}

int	player_check_position(t_gm *gm)
{
	int	x;
	int	y;

	x = gm->p_pos[0];
	y = gm->p_pos[1];
	if (gm->map[y][x] == 'C' && !gm->hero.moving)
	{
		gm->map[y][x] = '0';
		gm->score++;
		if (gm->field.collect == gm->score)
			gm->win = 1;
	}
	else if (gm->map[y][x] == 'E' && !gm->hero.moving)
		return (check_win(gm, 'e'));
	else if (gm->map[y][x] == 'S' && !gm->hero.moving)
		death(gm);
	return (1);
}

void	set_movement(t_gm *gm, t_hero *h)
{
	h->reach_x = (gm->p_pos[0] + 1) * SZ;
	h->reach_y = (gm->p_pos[1] + 1) * SZ;
	if (h->posx < h->reach_x)
		h->direction = 'r';
	else if (h->posx > h->reach_x)
		h->direction = 'l';
	else if (h->posy > h->reach_y || h->posy < h->reach_y)
		h->direction = h->pre_dir;
	else if (h->posy == h->reach_y && h->posx == h->reach_x)
		h->direction = 'n';
	if (h->direction == 'n')
	{
		h->moving = 0;
		player_check_position(gm);
	}
	else
	{
		h->pre_dir = h->direction;
		h->moving = 1;
	}
}

void	animate_movement(t_gm *gm, t_hero *h)
{
	t_image	img;

	if (h->direction == 'r')
		img = h->right[h->frame];
	else if (h->direction == 'l')
		img = h->left[h->frame];
	else
		img = h->idle;
	if (!gm->death && !gm->won)
		put_img_to_img(gm->bg, img, h->posx, h->posy);
		// mlx_put_image_to_window(gm->mlx, gm->mlx_win, img, h->posx, h->posy);
}

void	refresh_hero(t_gm *gm, t_hero *h)
{
	if (!(gm->frame % FRAMEP_RATE) && h->moving)
	{
		h->frame++;
		if (h->frame >= h->maxf)
			h->frame = 0;
		gm->refresh = 1;
		if (h->posx < h->reach_x)
			h->posx += SZ / 6;
		else if (h->posx > h->reach_x)
			h->posx -= SZ / 6;
		else if (h->posy < h->reach_y)
			h->posy += SZ / 6;
		else if (h->posy > h->reach_y)
			h->posy -= SZ / 6;
		set_movement(gm, h);
	}
}
