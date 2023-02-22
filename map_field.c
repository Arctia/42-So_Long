/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_field.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgavioli <vgavioli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:13:02 by vgavioli          #+#    #+#             */
/*   Updated: 2022/06/27 09:17:36 by vgavioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_field_err(t_map *field, t_err *merr)
{
	field->cols = 0;
	field->rows = 0;
	field->exit = 0;
	field->player = 0;
	field->collect = 0;
	field->enemies = 0;
	merr->diff_cols = 0;
	merr->player = 0;
	merr->exit = 0;
	merr->inv_char = 0;
	merr->inv_bord = 0;
	merr->collect = 0;
	merr->empty = 0;
}

char	*map_generation(int fd, t_map *field, char *map, t_err *map_err)
{
	char	*line;
	char	*ending_line;

	line = NULL;
	ending_line = NULL;
	while (5 == 5)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (!field->rows)
				map_err->empty = 1;
			else
				check_row(ending_line, field, map_err, 1);
			free(ending_line);
			break ;
		}
		free(ending_line);
		check_row(line, field, map_err, 0);
		ending_line = ft_substr(line, 0, ft_strlen(line));
		map = so_strjoin(map, line);
		field->rows++;
	}
	return (map);
}
