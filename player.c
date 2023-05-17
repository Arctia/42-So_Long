/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgavioli <vgavioli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:07:45 by vgavioli          #+#    #+#             */
/*   Updated: 2022/10/17 15:41:30 by vgavioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_back(t_gm *gm, char dir)
{
	if (dir == 'u')
		player_move(gm, 'd', 1);
	if (dir == 'd')
		player_move(gm, 'u', 1);
	if (dir == 'l')
		player_move(gm, 'r', 1);
	if (dir == 'r')
		player_move(gm, 'l', 1);
	if (dir == 'e')
		return (1);
	return (0);
}

int	check_win(t_gm *gm, char dir)
{
	info("Have you got enough collectibles?");
	if (gm->win == 1)
	{
		info("Yep, you won.");
		gm->won = 1;
	}
	else
	{
		info("No, I guess not.");
		dir = 'e';
		return (move_back(gm, dir));
	}
	return (1);
}

void	death(t_gm *gm)
{
	info("death has come.");
	gm->death = 1;
}

int	is_not_obstacle(char obj)
{
	if (obj != '0')
		return 0;
	return 1;
}

int		is_box_near_obstacle(t_gm *gm, int x, int y, char dir)
{
	if (gm->map[y][x] != 'B')
		return 0;
	if (dir == 'u')
		y--;
	else if (dir == 'd')
		y++;
	else if (dir == 'r')
		x++;
	else if (dir == 'l')
		x--;
	if (is_not_obstacle(gm->map[y][x]))
		return (0);
	return (1);
}

void	move_box(t_gm *gm, int x, int y, char dir)
{
	gm->map[y][x] = '0';
	if (dir == 'u')
		y--;
	else if (dir == 'd')
		y++;
	else if (dir == 'r')
		x++;
	else if (dir == 'l')
		x--;
	gm->map[y][x] = 'B';
}

int	check_position(t_gm *gm, char dir)
{
	int	x;
	int	y;

	x = gm->p_pos[0];
	y = gm->p_pos[1];
	if (gm->map[y][x] == '1' || is_box_near_obstacle(gm, x, y, dir))
		return (move_back(gm, dir));
	else if (gm->map[y][x] == 'C' && !gm->hero.moving)
	{
		gm->map[y][x] = '0';
		gm->score++;
		if (gm->field.collect == gm->score)
			gm->win = 1;

	}
	else if (gm->map[y][x] == 'B')
		move_box(gm, x, y, dir);
	else if (gm->map[y][x] == 'E' && !gm->hero.moving)
		return (check_win(gm, dir));
	else if (gm->map[y][x] == 'S' && !gm->hero.moving)
		death(gm);
	return (1);
}

void	player_move(t_gm *gm, char dir, int rec)
{
	gm->refresh = 1;
	if (dir == 'u')
		gm->p_pos[1]--;
	if (dir == 'd')
		gm->p_pos[1]++;
	if (dir == 'r')
		gm->p_pos[0]++;
	if (dir == 'l')
		gm->p_pos[0]--;
	set_movement(gm, &gm->hero);
	if (check_position(gm, dir) && !rec)
	{
		//pfn("[INFO	]: You've moved %d times.", ++gm->moves);
		;
	}
}
