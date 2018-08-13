/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scopedy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iletimil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 18:22:30 by iletimil          #+#    #+#             */
/*   Updated: 2018/08/13 01:11:17 by iletimil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		close(int key)
{
	if (key == 53)
		exit(1);
	return (0);
}

int		num_lines(char *filename)
{
	int		fd;
	int		numlines;
	char	*line;

	numlines = 0;
	fd = open(filename, O_RDONLY, 1);
	while (get_next_line(fd, &line))
		numlines++;
	free(line);
	close(fd);
	return (numlines);
}

void	ft_scopedy(t_coord *map, char *filename)
{
	map->move_x = 0;
	map->move_y = 0;
	map->z = 2.0;
	map->startx = 200;
	map->starty = 800;
	map->colour = WHITE;
	map->filename = filename;
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, 1000, 1000, "fdf");
}
