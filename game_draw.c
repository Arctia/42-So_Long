/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arctia <arctia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:11:16 by vgavioli          #+#    #+#             */
/*   Updated: 2024/06/11 18:50:04 by arctia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_black_background(t_gm g)
{
	int x = 0; int y = 0;
	int px = 0;	int py = 0;

	while (y < g.field.rows + 2)
	{
		while (x < g.field.cols + 2)
		{
			put_img_to_img(g.bg, g.images.void_, px, py);
			px = SZ * ++x;
		}
		py = SZ * ++y;
		px = 0; x = 0;
	}
}

void	draw_rectangle(int sx, int sy, t_gm g)
{
	int	xi;
	int	yi;
	int	x;
	int	y;

	y = 0;
	x = 0;
	xi = 0;
	yi = 0;
	while (yi < sy)
	{
		while (xi < sx)
		{
			put_img_to_img(g.bg, g.images.void_, x, y);
			x = SZ * ++xi;
		}
		y = SZ * ++yi;
	}
}

void	draw_moves(t_gm gm)
{
	char	*str;
	char	*num;
	char	*res;
	int		x;
	int		y;

	x = SZ * 1.2;
	y = SZ / 4;
	str = "Moves: ";
	num = ft_itoa(gm.moves);
	res = ft_strjoin(str, num);
	draw_rectangle(5, 1, gm);
	mlx_string_put(gm.mlx, gm.mlx_win, x, y, WHITE, res);
	free(num);
	free(res);
}

void	draw_death(t_gm gm)
{
	int	x;
	int	y;

	x = SZ * 1.2;
	y = (SZ * (gm.field.rows + 1)) + (SZ / 4);
	mlx_string_put(gm.mlx, gm.mlx_win, x, y, RED, "Death has come.. Press ESC");
}

void	draw_won(t_gm gm)
{
	int	x;
	int	y;

	x = SZ * 1.2;
	y = (SZ * (gm.field.rows + 1)) + (SZ / 4);
	mlx_string_put(gm.mlx, gm.mlx_win, x, y, GREEN, "Game won! Press ESC");
}
