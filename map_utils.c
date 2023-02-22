/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgavioli <vgavioli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:07:30 by vgavioli          #+#    #+#             */
/*   Updated: 2022/06/27 09:08:39 by vgavioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**check_map_file(int argc, char **argv, t_map *field)
{
	int	fd;

	if (argc != 2)
		pf_error("Invalid number of arguments.");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		pf_error("File not found!");
	info_free(ft_strjoin("File Selected: ", argv[1]));
	if (ft_strrncmp(".ber", argv[1], 4))
		pf_error("Not a file .ber, please use one!");
	return (check_map_field(fd, field));
}

char	**check_map_field(int fd, t_map *field)
{
	char	*map_str;
	char	**map;
	t_err	map_err;

	map_str = NULL;
	map = NULL;
	new_field_err(field, &map_err);
	map_str = map_generation(fd, field, map_str, &map_err);
	info_free(ft_strjoin("Map generation completed\n", map_str));
	if (display_map_errors(map_err))
	{
		free(map_str);
		exit(0);
	}
	map = ft_split(map_str, '\n');
	free(map_str);
	return (map);
}

void	check_row(char *line, t_map *field, t_err *map_err, int last)
{
	if (!field->cols)
		field->cols = ft_strlen(line) - 1;
	field->player += count_char(line, 'P');
	field->exit += count_char(line, 'E');
	field->collect += count_char(line, 'C');
	field->enemies += count_char(line, 'S');
	set_errors(line, field, map_err, last);
}
