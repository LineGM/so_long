/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:34:14 by lhanna            #+#    #+#             */
/*   Updated: 2022/06/16 17:34:15 by lhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image(t_vars *vars, int h, int w)
{
	vars->image.image_wall
		= mlx_xpm_file_to_image(vars->mlx, "./images/4.xpm", &h, &w);
	vars->image.image_floor
		= mlx_xpm_file_to_image(vars->mlx, "./images/3.xpm", &h, &w);
	vars->image.image_player_r1
		= mlx_xpm_file_to_image(vars->mlx, "./images/r1.xpm", &h, &w);
	vars->image.image_player_r2
		= mlx_xpm_file_to_image(vars->mlx, "./images/r2.xpm", &h, &w);
	vars->image.image_player_r3
		= mlx_xpm_file_to_image(vars->mlx, "./images/r3.xpm", &h, &w);
	vars->image.image_player_l1
		= mlx_xpm_file_to_image(vars->mlx, "./images/l1.xpm", &h, &w);
	vars->image.image_player_l2
		= mlx_xpm_file_to_image(vars->mlx, "./images/l2.xpm", &h, &w);
	vars->image.image_player_l3
		= mlx_xpm_file_to_image(vars->mlx, "./images/l3.xpm", &h, &w);
	vars->image.image_player_u1
		= mlx_xpm_file_to_image(vars->mlx, "./images/u1.xpm", &h, &w);
	vars->image.image_player_u2
		= mlx_xpm_file_to_image(vars->mlx, "./images/u2.xpm", &h, &w);
	vars->image.image_player_u3
		= mlx_xpm_file_to_image(vars->mlx, "./images/u3.xpm", &h, &w);
	image2(vars, 0, 0);
}

void	image2(t_vars *vars, int h, int w)
{
	vars->image.image_player_d1
		= mlx_xpm_file_to_image(vars->mlx, "./images/d1.xpm", &h, &w);
	vars->image.image_player_d2
		= mlx_xpm_file_to_image(vars->mlx, "./images/d2.xpm", &h, &w);
	vars->image.image_player_d3
		= mlx_xpm_file_to_image(vars->mlx, "./images/d3.xpm", &h, &w);
	vars->image.image_enemy_1
		= mlx_xpm_file_to_image(vars->mlx, "./images/Monster-4.xpm", &h, &w);
	vars->image.image_enemy_2
		= mlx_xpm_file_to_image(vars->mlx, "./images/Monster-5.xpm", &h, &w);
	vars->image.image_exit_1
		= mlx_xpm_file_to_image(vars->mlx, "./images/door-1.xpm", &h, &w);
	vars->image.image_exit_2
		= mlx_xpm_file_to_image(vars->mlx, "./images/door-2.xpm", &h, &w);
	vars->image.image_collectibles1
		= mlx_xpm_file_to_image(vars->mlx, "./images/art 1.xpm", &h, &w);
	vars->image.image_collectibles2
		= mlx_xpm_file_to_image(vars->mlx, "./images/art 2.xpm", &h, &w);
	vars->image.image_collectibles3
		= mlx_xpm_file_to_image(vars->mlx, "./images/art 3.xpm", &h, &w);
}

void	draw_images(t_vars *vars, char c, int i, int j)
{
	if (c == '0' || c == 'C' || c == 'P' || c == 'E' || c == 'V')
	{
		vars->tmp_image = vars->image.image_floor;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->tmp_image, j * PIXEL, i * PIXEL);
	}
	if (c == '1')
	{		
		vars->tmp_image = vars->image.image_wall;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->tmp_image, j * PIXEL, i * PIXEL);
	}
	else if (c == 'P')
	{
		flag_right(vars);
		flag_left(vars);
		flag_up(vars);
		flag_down(vars);
		vars->tmp_image = vars->image.image_player;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->tmp_image, j * PIXEL, i * PIXEL);
	}
	else if (c == 'E' || c == 'C' || c != '0')
		draw_images_e_c_v(vars, c, i, j);
}

int	draw_map(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	if (vars->frame_enemy_patrol % 10 == 0)
	{
		rename_enemy(vars, 'V', 'K');
		rename_enemy(vars, 'K', 'V');
		vars->frame_enemy_patrol = 0 ;
	}
	move_col(vars);
	while (++i < vars->count)
	{
		j = -1;
		while (++j < vars->length)
			draw_images(vars, vars->arr[i][j], i, j);
	}
	cnt_moves(vars);
	vars->frame_enemy_patrol++;
	return (0);
}

void	draw_images_e_c_v(t_vars *vars, char c, int i, int j)
{
	if (c == 'E')
	{
		if (vars->collectibles == 0)
			vars->tmp_image = vars->image.image_exit_2;
		else
			vars->tmp_image = vars->image.image_exit_1;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->tmp_image, j * PIXEL, i * PIXEL);
	}
	else if (c == 'C')
	{	
		vars->tmp_image = vars->image.image_collectibles;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->tmp_image, (j * PIXEL) + 8, (i * PIXEL) + 8);
	}
	else if (c != '0')
	{
		vars->tmp_image = vars->image.image_enemy_1;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->tmp_image, j * PIXEL, i * PIXEL);
	}
}
