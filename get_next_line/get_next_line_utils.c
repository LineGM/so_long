/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:33:15 by lhanna            #+#    #+#             */
/*   Updated: 2022/06/16 17:33:19 by lhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	k = ft_strlen(s1);
	str = malloc(sizeof(char) * (k + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < k)
	{
		str[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	char	*s;

	s = (char *)str;
	if ((unsigned char)c == 0)
		return (s + ft_strlen(s));
	while (*s && *s != (unsigned char)c)
		s++;
	if (*s && *s == (unsigned char)c)
		return (s);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
