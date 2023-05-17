/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgavioli <vgavioli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:19:25 by vgavioli          #+#    #+#             */
/*   Updated: 2022/06/27 09:17:38 by vgavioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	row_len_err(char *line, t_map *field)
{
	int	strlen;

	strlen = (int)ft_strlen(line);
	if (field->cols)
	{
		if (field->cols != strlen -1 && ft_strchr(line, '\n'))
			return (0);
		if (field->cols != strlen && !ft_strchr(line, '\n'))
			return (0);
	}
	return (1);
}

void	set_errors(char *line, t_map *field, t_err *map_err, int last)
{
	if (!row_len_err(line, field))
		map_err->diff_cols = 1;
	if (line[0] != '1' || line[field->cols - 1] != '1' || \
		((count_char(line, '1') != field->cols) && (last || !field->rows)))
		map_err->inv_bord = 1;
	while (line && *line)
	{
		if (!ft_strchr("01CEPGSB\n", *line))
			map_err->inv_char = 1;
		line++;
	}
	map_err->player = field->player < 1;
	map_err->collect = field->collect < 1;
	map_err->exit = field->exit < 1;
}

int	display_map_errors(t_err maer)
{
	int	err;

	err = 0;
	if (maer.empty)
		err = pf_error("Map is empty.");
	if (maer.diff_cols)
		err = pf_error("Map is not rectangular.");
	if (maer.player)
		err = pf_error("Map has no player.");
	if (maer.exit)
		err = pf_error("Map has no exit.");
	if (maer.collect)
		err = pf_error("Map has no collectibles.");
	if (maer.inv_char)
		err = pf_error("Map has an unknown character.");
	if (maer.inv_bord)
		err = pf_error("Map has invalid borders.");
	return (err);
}
