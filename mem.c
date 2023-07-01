/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:36:10 by lhanna            #+#    #+#             */
/*   Updated: 2022/06/16 17:36:12 by lhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	memory(t_vars *vars)
{
	int	i;
	int	k;

	vars->length = vars->length - 1;
	vars->arr = (char **)malloc(vars->count * sizeof(int *));
	if (!vars->arr)
	{
		perror(NULL);
		exit (1);
	}
	i = 0;
	while (i < vars->count)
	{
		vars->arr[i] = malloc((vars->length) * sizeof(char));
		if (!vars->arr[i])
		{
			perror(NULL);
			k = 0;
			while (k < i)
				free(vars->arr[k++]);
			free(vars->arr);
			exit (1);
		}
		i++;
	}
}

void	fill(t_vars *vars, char *argv)
{
	int		i;
	int		j;
	char	*line;

	vars->fd = open(argv, O_RDONLY);
	if (vars->fd < 0)
		error(2);
	line = get_next_line(vars->fd);
	i = 0;
	while (line)
	{
		j = 0;
		while (j < vars->length)
		{
			vars->arr[i][j] = line[j];
			j++;
		}
		i++;
		free(line);
		line = get_next_line(vars->fd);
	}
	close(vars->fd);
}

void	move_col(t_vars *vars)
{
	if (vars->frame_enemy_patrol % 50 == 0)
	{
		if (!ft_strncmp(vars->c, "1", 2))
		{
			vars->image.image_collectibles = vars->image.image_collectibles3;
			vars->c = "2";
		}
		else if (!ft_strncmp(vars->c, "2", 2))
		{
			vars->image.image_collectibles = vars->image.image_collectibles1;
			vars->c = "3";
		}	
		else if (!ft_strncmp(vars->c, "3", 2))
		{
			vars->image.image_collectibles = vars->image.image_collectibles2;
			vars->c = "1";
		}
	}
}
