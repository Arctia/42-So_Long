/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arctia <arctia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:50:42 by vgavioli          #+#    #+#             */
/*   Updated: 2024/06/11 19:36:00 by arctia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images(t_img *i)
{
	// mlx_destroy_image(i->mlx, i->wall);
	// mlx_destroy_image(i->mlx, i->ground);
	// mlx_destroy_image(i->mlx, i->hero);
	// mlx_destroy_image(i->mlx, i->box);
	// mlx_destroy_image(i->mlx, i->wisp[0]);
	// mlx_destroy_image(i->mlx, i->wisp[1]);
	// mlx_destroy_image(i->mlx, i->wisp[2]);
	// mlx_destroy_image(i->mlx, i->wisp[3]);
	// mlx_destroy_image(i->mlx, i->coll[0]);
	// mlx_destroy_image(i->mlx, i->coll[1]);
	// mlx_destroy_image(i->mlx, i->coll[2]);
	// mlx_destroy_image(i->mlx, i->exit[0]);
	// mlx_destroy_image(i->mlx, i->exit[1]);
}

void	free_hero(t_hero *h, t_gm *g)
{
	// mlx_destroy_image(g->mlx, h->idle);
	// mlx_destroy_image(g->mlx, h->right[0]);
	// mlx_destroy_image(g->mlx, h->right[1]);
	// mlx_destroy_image(g->mlx, h->right[2]);
	// mlx_destroy_image(g->mlx, h->right[3]);
	// mlx_destroy_image(g->mlx, h->right[4]);
	// mlx_destroy_image(g->mlx, h->left[0]);
	// mlx_destroy_image(g->mlx, h->left[1]);
	// mlx_destroy_image(g->mlx, h->left[2]);
	// mlx_destroy_image(g->mlx, h->left[3]);
	// mlx_destroy_image(g->mlx, h->left[4]);
}

void	main_free(t_gm *gm)
{
	free_images(&gm->images);
	free_hero(&gm->hero, gm);
	mlx_destroy_window(gm->window->mlx_ptr, gm->window->win_ptr);
	free(gm->window);
	ft_free_cmatrix(gm->map);
}
