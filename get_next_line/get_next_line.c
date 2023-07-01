/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:33:00 by lhanna            #+#    #+#             */
/*   Updated: 2022/06/16 17:33:03 by lhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line.h"

char	*ft_get_line(char **p_p_remainder, char **p_p_line)
{
	char	*p_to_n;
	char	*p_tmp;
	char	pointer;
	char	*p_new_remainder;

	p_new_remainder = NULL;
	p_to_n = NULL;
	p_to_n = ft_strchr(*p_p_remainder, '\n');
	if (p_to_n)
	{
		*p_p_line = ft_strdup("");
		p_tmp = *p_p_line;
		pointer = *(++p_to_n);
		*p_to_n = '\0';
		*p_p_line = ft_strjoin(*p_p_line, *p_p_remainder);
		free(p_tmp);
		*p_to_n = pointer;
		p_new_remainder = ft_strdup(p_to_n);
	}
	else
		*p_p_line = ft_strdup(*p_p_remainder);
	free(*p_p_remainder);
	*p_p_remainder = NULL;
	return (p_new_remainder);
}

int	ft_read_file(int fd, char **p_p_bufer, char **p_p_remainder,
	char **p_p_line)
{
	char	*p_tmp;
	int		simbols_read;

	if (!*p_p_remainder)
		*p_p_remainder = ft_strdup("");
	simbols_read = 1;
	while (!ft_strchr(*p_p_remainder, '\n') && simbols_read)
	{
		simbols_read = read(fd, *p_p_bufer, BUFFER_SIZE);
		(*p_p_bufer)[simbols_read] = '\0';
		p_tmp = *p_p_remainder;
		*p_p_remainder = ft_strjoin(*p_p_remainder, *p_p_bufer);
		free(p_tmp);
	}
	free(*p_p_bufer);
	*p_p_bufer = NULL;
	*p_p_remainder = ft_get_line(p_p_remainder, p_p_line);
	if (**p_p_line == '\0')
	{
		free(*p_p_line);
		*p_p_line = NULL;
	}
	return (simbols_read);
}

char	*get_next_line(int fd)
{
	static char	*p_remainder;
	char		*p_bufer;
	char		*p_line;
	int			simbols_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	p_bufer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!p_bufer)
		return (NULL);
	if (read(fd, p_bufer, 0) < 0)
	{
		free(p_bufer);
		return (NULL);
	}
	simbols_read = ft_read_file(fd, &p_bufer, &p_remainder, &p_line);
	if (simbols_read == 0 && !p_line)
		return (NULL);
	return (p_line);
}
// #include <stdio.h>

// int main()
// {
// 	int fd;
// 	char *line;

// 	fd =  open("map.ber", O_RDONLY);

// 	while ((line = get_next_line(fd)))
// 	{
// 		printf ("%s", line);
// 		free(line);
// 	}
// 	return (0);
// }
