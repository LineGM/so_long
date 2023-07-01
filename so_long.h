/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:35:02 by lhanna            #+#    #+#             */
/*   Updated: 2022/06/16 17:35:05 by lhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "stdio.h"
# include "minilibx/mlx.h"
# include <string.h>

# define PIXEL 64

typedef struct s_coord
{
	int	x;
	int	y;	
}				t_coord;

typedef struct s_image
{
	void	*image_wall;
	void	*image_floor;
	void	*image_collectibles;
	void	*image_collectibles1;
	void	*image_collectibles2;
	void	*image_collectibles3;
	void	*image_player;
	void	*image_exit_1;
	void	*image_exit_2;
	void	*image_player_r1;
	void	*image_player_r2;
	void	*image_player_r3;
	void	*image_player_l1;
	void	*image_player_l2;
	void	*image_player_l3;
	void	*image_player_u1;
	void	*image_player_u2;
	void	*image_player_u3;
	void	*image_player_d1;
	void	*image_player_d2;
	void	*image_player_d3;
	void	*image_player_down;
	void	*image_enemy;
	void	*image_enemy_1;
	void	*image_enemy_2;
	void	*image_enemy_3;
}		t_image;

typedef struct s_vars
{
	void				*mlx;
	void				*win;
	char				**arr;
	int					length;
	int					count;
	int					move_player1;
	int					fd;
	int					collectibles;
	int					players;
	int					exits;
	unsigned int		random_for_enemy;
	int					frame_enemy_patrol;
	int					flag_dir;
	t_image				image;
	void				*tmp_image;
	int					flag_delta;
	int					flag_sigma;
	int					flag_right;
	int					flag_left;
	int					flag_up;
	int					flag_down;
	int					last_step_r;
	int					last_step_l;
	int					last_step_u;
	int					last_step_d;
	int					flag_free_enemy;
	char				*c;
}				t_vars;

void	error(int n);
void	fill(t_vars *vars, char *argv);
void	memory(t_vars *vars);
int		map(t_vars *vars, char *argv);
void	map_check(t_vars *vars, int *flag_n, char *line);
int		map_check2(t_vars *vars, char *line, int flag_n);
int		check_symbols(t_vars *vars, char *line);
void	init(t_vars *vars);
void	image(t_vars *vars, int h, int w);
void	image2(t_vars *vars, int h, int w);
int		keypress(int keysym, t_vars *vars);
int		keypress_flag(int keysym, t_vars *vars);
int		keypress2(int keysym, t_vars *vars);
int		draw_map(t_vars *vars);
void	rename_enemy(t_vars *vars, char a, char b);
void	enemy_cordinate(t_vars *vars, t_coord *enemy_coord, int a, int b);
void	draw_images(t_vars *vars, char c, int i, int j);
void	move_enemy(t_vars *vars, int i, int j);
void	cnt_moves(t_vars *vars);
void	flag_right(t_vars *vars);
void	flag_left(t_vars *vars);
void	flag_up(t_vars *vars);
void	flag_down(t_vars *vars);
void	draw_images_e_c_v(t_vars *vars, char c, int i, int j);
void	move_player(int a, int b, t_vars *vars);
void	move_player2(int *i, int a, int b, t_vars *vars);
int		close_window(t_vars *vars);
char	*ft_itoa(int i);
char	*val(char *str, int i, int cnt);
int		get_size(int i);
void	move_col(t_vars *vars);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	print_moves(t_vars *vars);

#endif
