/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgavioli <vgavioli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:11:16 by vgavioli          #+#    #+#             */
/*   Updated: 2022/06/26 19:16:01 by vgavioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			mlx_put_image_to_window(g.mlx, g.mlx_win, g.images.void_, x, y);
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
