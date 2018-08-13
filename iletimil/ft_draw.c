/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iletimil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 13:09:01 by iletimil          #+#    #+#             */
/*   Updated: 2018/08/13 01:29:59 by iletimil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

void	ft_draw_line(t_coord *f)
{
	double		tx;
	double		dx;
	double		dy;

	tx = 0;
	dx = f->x2 - f->x1;
	dy = f->y2 - f->y1;
	while (tx <= 1)
	{
		f->x = f->x1 + (dx * tx);
		f->y = f->y1 + (dy * tx);
		mlx_pixel_put(f->mlx, f->win, f->x + f->move_x,
				f->y + f->move_y, f->colour);
		tx += 1 / sqrt((dx * dx) + (dy * dy));
	}
}

void	draw_vert(t_coord *f, int j, int i)
{
	f->x1 = f->startx + (i * f->zoom) + (j * f->zoom);
	f->x2 = f->startx + (i * f->zoom) + ((j + 1) * f->zoom);
	f->y1 = ((f->starty + (j * f->zoom)) * 1 / 2) - (((i * f->zoom)
				+ (f->z * f->tab[j][i])) * 1 / 2);
	f->y2 = ((f->starty + ((j + 1) * f->zoom)) * 1 / 2) - (((i * f->zoom)
				+ (f->z * f->tab[j + 1][i])) * 1 / 2);
	ft_draw_line(f);
}

void	draw_horiz(t_coord *f, int j, int i)
{
	f->x1 = f->startx + (i * f->zoom) + (j * f->zoom);
	f->x2 = f->startx + (((i + 1) * f->zoom) + (j * f->zoom));
	f->y1 = ((f->starty + (j * f->zoom)) * 1 / 2) - (((i * f->zoom)
				+ (f->z * f->tab[j][i])) * 1 / 2);
	f->y2 = ((f->starty + (j * f->zoom)) * 1 / 2) - ((((i + 1) * f->zoom)
				+ (f->z * f->tab[j][i + 1])) * 1 / 2);
	ft_draw_line(f);
}

int		ft_draw_map(t_coord *f)
{
	int			i;
	int			j;

	j = 0;
	while (j < f->l)
	{
		i = 0;
		while (i < f->i - 1)
			draw_horiz(f, j, i++);
		j++;
	}
	j = 0;
	while (j < f->l - 1)
	{
		i = 0;
		while (i < f->i)
			draw_vert(f, j, i++);
		j++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int			nbl;
	int			nbi;
	char		**arr;
	t_coord		*map;

	if (argc == 2)
	{
		map = (t_coord *)malloc(sizeof(t_coord));
		arr = ft_read(argv[1]);
		map->tab = convert(arr, argv[1]);
		ft_scopedy(map, argv[1]);
		nbi = num_digits(arr[0]);
		nbl = num_lines(argv[1]);
		map->l = nbl;
		map->i = nbi;
		if (map->l >= map->i)
			map->zoom = 500 / map->l;
		else
			map->zoom = 500 / map->i;
		ft_draw_map(map);
		mlx_key_hook(map->win, close, 0);
		mlx_loop(map->mlx);
	}
	return (0);
}
