/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arctia <arctia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:44:48 by vgavioli          #+#    #+#             */
/*   Updated: 2024/06/11 18:41:21 by arctia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./libft/ft_printf/ft_printf.h"
# include "./libft/get_next_line/get_next_line.h"
# include "minilibx/mlx.h"
# include <X11/X.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define FRAME_RATE_L 1200
# define FRAMEP_RAT_L 300

# define FRAME_RATE 16200
# define FRAMEP_RATE 4050
# define SZ 48
# define OFFSET 1
# define WISP_FRAMES 4
# define COLL_FRAMES 3
# define WHITE 0xFFFFFFFF
# define RED 0xFFFF4444
# define GREEN 0xFF44FF44

# define ARR_UP 126
# define KEY_W 13
# define ARR_RIGHT 124
# define KEY_D 2
# define ARR_DOWN 125
# define KEY_S 1
# define ARR_LEFT 123
# define KEY_A 0

# define KEY_ESC 53

# define ARR_UP_L 65362//126
# define KEY_W_L 119//13
# define ARR_RIGHT_L 65363//124
# define KEY_D_L 100//2
# define ARR_DOWN_L 65364//125
# define KEY_S_L 115//1
# define ARR_LEFT_L 65361//123
# define KEY_A_L 97//0

# define KEY_ESC_L 65307//53

typedef struct s_map
{
	int		cols;
	int		rows;
	int		collect;
	int		enemies;
	int		player;
	int		boxes;
	int		exit;
}				t_map;

typedef struct s_err
{
	int		empty;
	int		diff_cols;
	int		player;
	int		exit;
	int		collect;
	int		inv_char;
	int		inv_bord;
}				t_err;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}				t_window;

typedef struct s_image
{
	t_window	*win;
	void		*img_ptr;
	char		*addr;
	int			h;
	int			w;
	int			bpp;
	int			endian;
	int			line_len;
}				t_image;

typedef struct s_img
{
	void	*mlx;
	t_image	ground;
	t_image	wisp[4];
	t_image	hero;
	t_image	coll[3];
	t_image	wall;
	t_image	exit[2];
	t_image	void_;
	t_image	box;
	int		w;
	int		h;
	int		wisp_cf;
	int		coll_cf;
}				t_img;

typedef struct s_hero
{
	t_image	idle;
	t_image	right[5];
	t_image	left[5];
	char	direction;
	char	pre_dir;
	int		reach_x;
	int		reach_y;
	char	moving;
	int		frame;
	int		maxf;
	int		posx;
	int		posy;
}				t_hero;

typedef struct s_gm
{
	char			**map;
	t_window		*window;
	t_image			bg;
	void			*mlx_win;
	void			*mlx;
	int				p_pos[2];
	int				sz[2];
	t_map			field;
	t_img			images;
	long long int	frame;
	int				refresh;
	int				frame_rate;
	int				moves;
	int				score;
	int				death;
	int				deathd;
	int				win;
	int				won;
	int				wond;
	t_hero			hero;
}				t_gm;

//utils_000.c
int		info(char *str);
int		info_free(char *str);
int		pf_error(char *str);
int		count_char(char *str, char c);
char	*so_strjoin(char *dst, char *src);

//map_utils.c
void	check_row(char *line, t_map *field, t_err *map_err, int last);
char	**check_map_file(int argc, char **argv, t_map *field);
char	**check_map_field(int fd, t_map *field);

//map_errors.c
void	set_errors(char *line, t_map *field, t_err *map_err, int last);
int		row_len_err(char *line, t_map *field);
int		display_map_errors(t_err maer);

//map_field.c
char	*map_generation(int fd, t_map *field, char *map, t_err *map_err);
void	new_field_err(t_map *field, t_err *merr);

//map_draw.c
void	draw_image(t_gm gm, int pos[5], t_image img);
void	draw_all(t_gm *gm, int d[5], char id);
void	init_game_struct(t_gm *g);
void	draw_game_map(t_gm *gm);
void	init_images(t_img *i, t_window win);

//player_draw.c
void	animate_movement(t_gm *gm, t_hero *h);
void	set_movement(t_gm *gm, t_hero *h);
void	refresh_hero(t_gm *gm, t_hero *h);
void	init_hero(t_hero *i, t_window win);

//player.c
void	player_move(t_gm *gm, char dir, int rec);
int		check_win(t_gm *gm, char dir);
void	death(t_gm *gm);

//key_bindings.c
int		linux_key_hook(int key, t_gm *gm);
int		key_hook(int key, t_gm *gm);

//game_draw.c
void	draw_black_background(t_gm g);
void	draw_rectangle(int sx, int sy, t_gm g);
void	draw_moves(t_gm gm);
void	draw_death(t_gm gm);
void	draw_won(t_gm gm);

//game.c
void	game_init(char **map, t_map *field);
int		exit_game(t_gm *gm);

//free_memory.c
void	main_free(t_gm *gm);

int		is_box_near_obstacle(t_gm *gm, int x, int y, char dir);
void	move_box(t_gm *gm, int x, int y, char dir);
int		is_not_obstacle(char obj);

t_image		new_background_img(t_window *window, int width, int height);
t_window	*new_window(int height, int width, char *str);
t_image		*new_image(t_window *win, int height, int width);
t_image		new_file_img(char * path, t_window window);
void		put_pixel_img(t_image img, int x, int y, int color);
void	put_img_to_img(t_image dst, t_image src, int x, int y);

#endif
