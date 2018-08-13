/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iletimil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 16:38:07 by iletimil          #+#    #+#             */
/*   Updated: 2018/08/13 01:23:26 by iletimil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

int		num_digits(char *line)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			len++;
		i++;
	}
	return (len);
}

char	**ft_read(char *fname)
{
	int			fd;
	int			numlines;
	char		*line;
	char		**map;
	t_counters	z;

	z.k = 0;
	numlines = 0;
	fd = open(fname, O_RDONLY, 1);
	while (get_next_line(fd, &line))
		numlines++;
	map = (char **)malloc(sizeof(char *) * (numlines + 1));
	map[numlines] = 0;
	close(fd);
	fd = open(fname, O_RDONLY, 1);
	while (get_next_line(fd, &line))
	{
		z.i = 0;
		map[z.k] = (char *)malloc(sizeof(char *) * (ft_strlen(line) + 1));
		while (z.i++ < numlines)
			map[z.k] = line;
		z.k++;
	}
	return (map);
}

int		count(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		**convert(char **map, char *filename)
{
	t_counters	z;
	int			y;
	int			**tab;
	char		**arr;

	z.k = 0;
	(void)filename;
	tab = (int **)malloc(sizeof(int *) * num_lines(filename));
	while (z.k < num_lines(filename))
	{
		z.i = 0;
		y = 0;
		z.j = 0;
		arr = ft_strsplit(map[z.k], ' ');
		z.j = count(arr);
		tab[z.k] = (int *)malloc(sizeof(int) * z.j);
		while (z.i < z.j)
			tab[z.k][z.i++] = ft_atoi(arr[y++]);
		while (--z.i >= 0)
			free(arr[z.i--]);
		++z.k;
	}
	return (tab);
}
