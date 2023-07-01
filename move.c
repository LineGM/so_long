/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:36:59 by lhanna            #+#    #+#             */
/*   Updated: 2022/06/16 17:37:01 by lhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(int a, int b, t_vars *vars)
{
	int	i[2];

	i[0] = -1;
	while (++i[0] < vars->count)
	{
		i[1] = -1;
		while (++i[1] < vars->length)
		{
			if (vars->arr[i[0]][i[1]] == 'P' && (vars->arr[i[0]
				- a][i[1] + b] == '0' || vars->arr[i[0] - a][i[1] + b] == 'C'))
			{
				if (vars->arr[i[0] - a][i[1] + b] == 'C')
					vars->collectibles--;
				vars->arr[i[0] - a][i[1] + b] = 'P';
				vars->arr[i[0]][i[1]] = '0';
				vars->move_player1++;
				print_moves(vars);
				return ;
			}
			else
				move_player2(i, a, b, vars);
		}
	}	
}

void	move_player2(int *i, int a, int b, t_vars *vars)
{
	if (vars->arr[i[0]][i[1]] == 'P' && vars->arr[i[0] - a][i[1] + b] == 'E'
		&& vars->collectibles == 0)
	{
		vars->arr[i[0] - a][i[1] + b] = 'P';
		vars->arr[i[0]][i[1]] = '0';
		vars->move_player1++;
		print_moves(vars);
		write(1, "YOU WIN!\n", 10);
		close_window(vars);
	}
	else if (vars->arr[i[0]][i[1]] == 'P'
		&& vars->arr[i[0] - a][i[1] + b] == 'V')
	{
		write(1, "YOU LOSE!\n", 11);
		close_window(vars);
	}
}

void	move_enemy(t_vars *vars, int i, int j)
{
	t_coord	enemy_coord;

	enemy_coord.x = i;
	enemy_coord.y = j;
	if (vars->random_for_enemy % 4 == 0)
		enemy_cordinate(vars, &enemy_coord, 1, 0);
	else if (vars->random_for_enemy % 4 == 1)
		enemy_cordinate(vars, &enemy_coord, -1, 0);
	else if (vars->random_for_enemy % 4 == 2)
		enemy_cordinate(vars, &enemy_coord, 0, -1);
	else if (vars->random_for_enemy % 4 == 3)
		enemy_cordinate(vars, &enemy_coord, 0, 1);
}

void	enemy_cordinate(t_vars *vars, t_coord *enemy_coord, int a, int b)
{
	if (vars->arr[enemy_coord->x - a][enemy_coord->y - b] == '0' ||
		vars->arr[enemy_coord->x - a][enemy_coord->y - b] == 'P')
	{
		if (vars->arr[enemy_coord->x - a][enemy_coord->y - b] == 'P')
		{
			write (1, "YOU LOSE!\n", 11);
			close_window(vars);
		}
		vars->arr[enemy_coord->x - a][enemy_coord->y - b] = 'K';
		vars->arr[enemy_coord->x][enemy_coord->y] = '0';
		vars->flag_free_enemy = 0;
	}
	else if (vars->flag_free_enemy == 0)
	{
		vars->random_for_enemy += 2;
		vars->flag_free_enemy = 1;
	}
	else if (vars->flag_free_enemy == 1)
	{
		vars->random_for_enemy += 1;
		vars->flag_free_enemy = 0;
	}
	vars->random_for_enemy += 2;
}

void	cnt_moves(t_vars *vars)
{
	char	*moves_str;
	char	*moves_cnt;

	moves_str = ft_strdup("MOVES: ");
	moves_cnt = ft_itoa(vars->move_player1);
	mlx_string_put(vars->mlx, vars->win, 60, 20, 0x000000, moves_str);
	mlx_string_put(vars->mlx, vars->win, 120, 20, 0x000000, moves_cnt);
	free(moves_str);
	free(moves_cnt);
}
