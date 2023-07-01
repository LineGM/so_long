/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:35:58 by lhanna            #+#    #+#             */
/*   Updated: 2022/06/16 17:36:00 by lhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(int n)
{
	if (n == 1)
		printf("Error: wrong number of arguments\n");
	else if (n == 2)
		printf("Error: file read error\n");
	else if (n == 3)
		printf("Map error: invalid string length\n");
	else if (n == 4)
		printf("Map error: map borders are set incorrectly\n");
	else if (n == 5)
		printf("Map error: invalid symbols in the map\n");
	else if (n == 6)
		printf("Map error: empty lines in file\n");
	else if (n == 7)
		printf("Map error: wrong number of players or entering the field\n");
	else if (n == 8)
		printf("Map error: must be collectible on the field\n");
	else if (n == 9)
		printf("Map error: empty\n");
	exit(1);
}

void	init(t_vars *vars)
{
	vars->collectibles = 0;
	vars->exits = 0;
	vars->players = 0;
	vars->move_player1 = 0;
	vars->random_for_enemy = 0;
	vars->frame_enemy_patrol = 0;
	vars->flag_dir = 0;
	vars->mlx = NULL;
	vars->win = NULL;
	vars->arr = NULL;
	vars->flag_right = 0;
	vars->flag_left = 0;
	vars->flag_up = 0;
	vars->flag_down = 0;
	vars->last_step_r = 0;
	vars->last_step_l = 0;
	vars->last_step_u = 0;
	vars->last_step_d = 0;
	vars->flag_free_enemy = 0;
	vars->c = "1";
}

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	vars->win = NULL;
	exit (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
	{
		error (1);
		exit (1);
	}
	init(&vars);
	map(&vars, argv[1]);
	memory(&vars);
	fill(&vars, argv[1]);
	vars.mlx = mlx_init();
	image(&vars, 0, 0);
	vars.image.image_player = vars.image.image_player_r1;
	vars.image.image_enemy = vars.image.image_enemy_1;
	vars.image.image_collectibles = vars.image.image_collectibles1;
	vars.win = mlx_new_window(vars.mlx, PIXEL * vars.length,
			PIXEL * vars.count, "So_long");
	mlx_hook(vars.win, 2, 1L << 0, keypress, &vars);
	mlx_key_hook(vars.win, keypress_flag, &vars);
	mlx_hook(vars.win, 17, 1L << 5, close_window, &vars);
	mlx_loop_hook(vars.mlx, draw_map, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
