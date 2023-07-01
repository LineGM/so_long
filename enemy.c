/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:35:20 by lhanna            #+#    #+#             */
/*   Updated: 2022/06/16 17:35:21 by lhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + 48);
}

void	rename_enemy(t_vars *vars, char a, char b)
{
	int	i;
	int	j;

	i = -1;
	while (++i < vars->count)
	{
		j = -1;
		while (++j < vars->length)
		{
			if (vars->arr[i][j] == a)
			{
				vars->arr[i][j] = b;
				if (a == 'V' && b == 'K')
					move_enemy(vars, i, j);
			}
		}
	}
}
