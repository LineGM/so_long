/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:35:40 by lhanna            #+#    #+#             */
/*   Updated: 2022/06/16 17:35:41 by lhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(t_vars *vars)
{
	write (1, "MOVES: ", 7);
	ft_putnbr(vars->move_player1);
	write (1, "\n", 1);
}

int	keypress(int keysym, t_vars *vars)
{
	if (keysym == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0);
	}
	else if (keysym == 126 || keysym == 13 || keysym == 125
		|| keysym == 1 || keysym == 123 || keysym == 0)
		keypress2(keysym, vars);
	else if (keysym == 124 || keysym == 2)
	{
		vars->flag_dir = 4;
		vars->flag_right = 1;
		vars->last_step_r = 1;
		move_player(0, 1, vars);
		vars->image.image_player = vars->image.image_player_r1;
	}
	return (0);
}

int	keypress2(int keysym, t_vars *vars)
{
	if (keysym == 126 || keysym == 13)
	{
		vars->flag_dir = 1;
		vars->flag_up = 1;
		vars->last_step_u = 1;
		move_player(1, 0, vars);
		vars->image.image_player = vars->image.image_player_u1;
	}
	else if (keysym == 125 || keysym == 1)
	{
		vars->flag_dir = 2;
		vars->flag_down = 1;
		vars->last_step_d = 1;
		move_player(-1, 0, vars);
		vars->image.image_player = vars->image.image_player_d1;
	}
	else if (keysym == 123 || keysym == 0)
	{
		vars->flag_dir = 3;
		vars->flag_left = 1;
		vars->last_step_l = 1;
		move_player(0, -1, vars);
		vars->image.image_player = vars->image.image_player_l1;
	}
	return (0);
}

int	keypress_flag(int keysym, t_vars *vars)
{
	if (keysym == 124 || keysym == 2)
		vars->flag_right = 0;
	if (keysym == 123 || keysym == 0)
		vars->flag_left = 0;
	if (keysym == 126 || keysym == 13)
		vars->flag_up = 0;
	if (keysym == 125 || keysym == 1)
		vars->flag_down = 0;
	return (0);
}
