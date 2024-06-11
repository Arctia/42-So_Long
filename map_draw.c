/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arctia <arctia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:54:42 by vgavioli          #+#    #+#             */
/*   Updated: 2024/06/11 18:50:20 by arctia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_image(t_gm gm, int pos[5], t_image img)
{
	pos[2] = (pos[0] + OFFSET) * SZ;
	pos[3] = (pos[1] + OFFSET) * SZ;
	put_img_to_img(gm.bg, img, pos[2], pos[3]);
	// mlx_put_image_to_window(gm.mlx, gm.mlx_win, img, pos[2], pos[3]);
}

void	init_images(t_img *i, t_window win)
{
	i->w = SZ;
	i->h = SZ;
	i->box = new_file_img("res/box.xpm", win);
	i->hero = new_file_img("res/hero.xpm", win);
	i->void_ = new_file_img("res/void.xpm", win);
	i->ground = new_file_img("res/ground1.xpm", win);
	i->coll[0] = new_file_img("res/coll_0.xpm", win);
	i->coll[1] = new_file_img("res/coll_1.xpm", win);
	i->coll[2] = new_file_img("res/coll_2.xpm", win);
	i->wisp[0] = new_file_img("res/wisp0.xpm", win);
	i->wisp[1] = new_file_img("res/wisp1.xpm", win);
	i->wisp[2] = new_file_img("res/wisp2.xpm", win);
	i->wisp[3] = new_file_img("res/wisp3.xpm", win);
	i->exit[0] = new_file_img("res/exit2.xpm", win);
	i->exit[1] = new_file_img("res/exit1.xpm", win);
	i->wall = new_file_img("res/wall1.xpm", win);
	i->wisp_cf = 0;
	i->coll_cf = 0;
}

void	init_game_struct(t_gm *gm)
{
	gm->win = 0;
	gm->won = 0;
	gm->wond = 0;
	gm->moves = 0;
	gm->score = 0;
	gm->death = 0;
	gm->deathd = 0;
	gm->sz[0] = SZ;
	gm->sz[1] = SZ;
	gm->p_pos[0] = -1;
	gm->p_pos[1] = -1;
	gm->images.mlx = gm->mlx;
	init_images(&gm->images, *gm->window);
	init_hero(&gm->hero, *gm->window);
}

//draw all elements
void	draw_all(t_gm *gm, int d[5], char id)
{
	if (id == '1')
		draw_image(*gm, d, gm->images.wall);
	else if (id == '0' || id == 'P' || id == 'S' || id == 'C' || id == 'B')
		draw_image(*gm, d, gm->images.ground);
	if (id == 'P' && gm->p_pos[0] == -1)
	{
		gm->p_pos[0] = d[0];
		gm->p_pos[1] = d[1];
		gm->hero.posx = (d[0] + 1) * SZ;
		gm->hero.posy = (d[1] + 1) * SZ;
	}
	if (id == 'C')
		draw_image(*gm, d, gm->images.coll[gm->images.coll_cf]);
	else if (id == 'S')
		draw_image(*gm, d, gm->images.wisp[gm->images.wisp_cf]);
	else if (id == 'B')
		draw_image(*gm, d, gm->images.box);
	else if (id == 'E')
		draw_image(*gm, d, gm->images.exit[gm->win]);
}

void	draw_game_map(t_gm *gm)
{
	int		d[5];
	char	id;

	d[1] = 0;
	d[4] = 0;
	draw_black_background(*gm);
	while (d[1] < gm->field.rows)
	{
		d[0] = 0;
		while (d[0] < gm->field.cols)
		{
			id = gm->map[d[1]][d[0]];
			draw_all(gm, d, id);
			d[0]++;
		}
		d[1]++;
	}
	animate_movement(gm, &gm->hero);
	mlx_put_image_to_window(gm->mlx, gm->mlx_win, gm->bg.img_ptr, 0, 0);
	// mlx_put_image_to_window (base_image.win.mlx_ptr, , base_image.img_ptr, 0, 0);
	gm->refresh = 0;
}
