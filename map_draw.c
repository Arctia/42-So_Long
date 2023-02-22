/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgavioli <vgavioli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:54:42 by vgavioli          #+#    #+#             */
/*   Updated: 2022/06/26 19:06:56 by vgavioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_image(t_gm gm, int pos[5], void *img)
{
	pos[2] = (pos[0] + OFFSET) * SZ;
	pos[3] = (pos[1] + OFFSET) * SZ;
	mlx_put_image_to_window(gm.mlx, gm.mlx_win, img, pos[2], pos[3]);
}

void	init_images(t_img *i)
{
	i->w = SZ;
	i->h = SZ;
	i->wall = mlx_xpm_file_to_image(i->mlx, "res/wall1.xpm", &i->w, &i->h);
	i->hero = mlx_xpm_file_to_image(i->mlx, "res/hero.xpm", &i->w, &i->h);
	i->void_ = mlx_xpm_file_to_image(i->mlx, "res/void.xpm", &i->w, &i->h);
	i->ground = mlx_xpm_file_to_image(i->mlx, "res/ground1.xpm", &i->w, &i->h);
	i->coll[0] = mlx_xpm_file_to_image(i->mlx, "res/coll_0.xpm", &i->w, &i->h);
	i->coll[1] = mlx_xpm_file_to_image(i->mlx, "res/coll_1.xpm", &i->w, &i->h);
	i->coll[2] = mlx_xpm_file_to_image(i->mlx, "res/coll_2.xpm", &i->w, &i->h);
	i->wisp[0] = mlx_xpm_file_to_image(i->mlx, "res/wisp0.xpm", &i->w, &i->h);
	i->wisp[1] = mlx_xpm_file_to_image(i->mlx, "res/wisp1.xpm", &i->w, &i->h);
	i->wisp[2] = mlx_xpm_file_to_image(i->mlx, "res/wisp2.xpm", &i->w, &i->h);
	i->wisp[3] = mlx_xpm_file_to_image(i->mlx, "res/wisp3.xpm", &i->w, &i->h);
	i->exit[0] = mlx_xpm_file_to_image(i->mlx, "res/exit2.xpm", &i->w, &i->h);
	i->exit[1] = mlx_xpm_file_to_image(i->mlx, "res/exit1.xpm", &i->w, &i->h);
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
	init_images(&(gm->images));
	init_hero(&gm->hero, gm);
}

//draw all elements
void	draw_all(t_gm *gm, int d[5], char id)
{
	if (id == '1')
		draw_image(*gm, d, gm->images.wall);
	else if (id == '0' || id == 'P' || id == 'S' || id == 'C')
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
	if (id == 'S')
		draw_image(*gm, d, gm->images.wisp[gm->images.wisp_cf]);
	if (id == 'E')
		draw_image(*gm, d, gm->images.exit[gm->win]);
}

void	draw_game_map(t_gm *gm)
{
	int		d[5];
	char	id;

	d[1] = 0;
	d[4] = 0;
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
	gm->refresh = 0;
}
