/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:34:30 by lhanna            #+#    #+#             */
/*   Updated: 2022/06/16 17:34:39 by lhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_size(int i)
{
	int	cnt;

	if (i == 0)
		return (1);
	cnt = 0;
	while (i)
	{
		i /= 10;
		cnt++;
	}
	return (cnt);
}

char	*val(char *str, int i, int cnt)
{
	long	j;

	j = i;
	if (j < 0)
	{
		j *= -1;
		str[0] = '-';
	}
	if (j == 0)
		str[0] = '0';
	while (j)
	{
		str[cnt - 1] = j % 10 + 48;
		j /= 10;
		cnt--;
	}
	return (str);
}

char	*ft_itoa(int i)
{
	char	*str;
	int		cnt;

	cnt = get_size(i);
	if (i < 0)
		cnt++;
	str = malloc(cnt + 1);
	if (!str)
		return (0);
	str[cnt] = '\0';
	return (val(str, i, cnt));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
