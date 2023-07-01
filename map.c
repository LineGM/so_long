/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:34:50 by lhanna            #+#    #+#             */
/*   Updated: 2022/06/16 17:34:52 by lhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map(t_vars *vars, char *argv)
{
	char	*line;
	int		flag_n;

	vars->fd = open(argv, O_RDONLY);
	if (vars->fd < 0)
		error(2);
	line = get_next_line(vars->fd);
	if (line == NULL)
		error(9);
	vars->length = ft_strlen(line);
	vars->count = 0;
	while (line)
	{
		map_check(vars, &flag_n, line);
		free(line);
		line = get_next_line(vars->fd);
	}
	if (flag_n == 1)
		error(6);
	if ((vars->players != 1) || (vars->exits != 1))
		error(7);
	if (vars->collectibles == 0)
		error(8);
	close(vars->fd);
	return (0);
}

void	map_check(t_vars *vars, int *flag_n, char *line)
{
	*flag_n = 0;
	if (line[ft_strlen(line) - 1] == '\n')
		*flag_n = 1;
	vars->count++;
	if ((*flag_n && ((int)ft_strlen(line) != vars->length))
		|| (!(*flag_n) && ((int)ft_strlen(line) != vars->length - 1)))
		error(3);
	map_check2(vars, line, *flag_n);
}

int	map_check2(t_vars *vars, char *line, int flag_n)
{
	int	i;

	i = 0;
	if (flag_n)
		line[vars->length - 1] = '\0';
	if (vars->count == 1 || !flag_n)
	{
		while (i < vars->length - 1)
		{
			if (line[i] != '1')
				error(4);
			i++;
		}
	}
	if (vars->count > 1 && flag_n)
	{
		if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
			error(4);
		check_symbols(vars, line);
	}
	return (0);
}

int	check_symbols(t_vars *vars, char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == 'P')
			vars->players++;
		else if (line[i] == 'E')
			vars->exits++;
		else if (line[i] == 'C')
			vars->collectibles++;
		else if (line[i] != '0' && line[i] != '1' && line[i] != 'V')
			error(5);
	}
	return (0);
}
