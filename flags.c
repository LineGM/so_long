/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:34:01 by lhanna            #+#    #+#             */
/*   Updated: 2022/06/16 17:34:02 by lhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flag_right(t_vars *vars)
{
	if (vars->flag_right || (!vars->flag_right && vars->last_step_r))
	{
		if (vars->image.image_player == vars->image.image_player_r1)
			vars->image.image_player = vars->image.image_player_r2;
		else if (vars->image.image_player == vars->image.image_player_r2)
			vars->image.image_player = vars->image.image_player_r3;
		else if (vars->image.image_player == vars->image.image_player_r3)
			vars->image.image_player = vars->image.image_player_r2;
		if (!vars->flag_right && vars->last_step_r)
			vars->last_step_r--;
	}
	else if (!vars->flag_right && vars->flag_dir == 4)
		vars->image.image_player = vars->image.image_player_r1;
}

void	flag_left(t_vars *vars)
{
	if (vars->flag_left || (!vars->flag_left && vars->last_step_l))
	{
		if (vars->image.image_player == vars->image.image_player_l1)
			vars->image.image_player = vars->image.image_player_l2;
		else if (vars->image.image_player == vars->image.image_player_l2)
			vars->image.image_player = vars->image.image_player_l3;
		else if (vars->image.image_player == vars->image.image_player_l3)
			vars->image.image_player = vars->image.image_player_l2;
		if (!vars->flag_left && vars->last_step_l)
			vars->last_step_l--;
	}
	else if (!vars->flag_left && vars->flag_dir == 3)
		vars->image.image_player = vars->image.image_player_l1;
}

void	flag_up(t_vars *vars)
{
	if (vars->flag_up || (!vars->flag_up && vars->last_step_u))
	{
		if (vars->image.image_player == vars->image.image_player_u1)
			vars->image.image_player = vars->image.image_player_u2;
		else if (vars->image.image_player == vars->image.image_player_u2)
			vars->image.image_player = vars->image.image_player_u3;
		else if (vars->image.image_player == vars->image.image_player_u3)
			vars->image.image_player = vars->image.image_player_u2;
		if (!vars->flag_up && vars->last_step_u)
			vars->last_step_u--;
	}
	else if (!vars->flag_up && vars->flag_dir == 1)
		vars->image.image_player = vars->image.image_player_u1;
}

void	flag_down(t_vars *vars)
{
	if (vars->flag_down || (!vars->flag_down && vars->last_step_d))
	{
		if (vars->image.image_player == vars->image.image_player_d1)
			vars->image.image_player = vars->image.image_player_d2;
		else if (vars->image.image_player == vars->image.image_player_d2)
			vars->image.image_player = vars->image.image_player_d3;
		else if (vars->image.image_player == vars->image.image_player_d3)
			vars->image.image_player = vars->image.image_player_d2;
		if (!vars->flag_down && vars->last_step_d)
			vars->last_step_d--;
	}
	else if (!vars->flag_down && vars->flag_dir == 2)
		vars->image.image_player = vars->image.image_player_d1;
}
