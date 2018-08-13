/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iletimil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 16:55:21 by iletimil          #+#    #+#             */
/*   Updated: 2018/08/13 01:50:08 by iletimil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "get_next_line.h"
# include "libft/includes/libft.h"
# include <string.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define RED 0x00EE0000
# define BLUE 0x000000EE
# define GREEN 0x0000EE00
# define PURPLE 0x00EE00EE
# define YELLOW 0x0000EEDD

typedef struct	s_counters
{
	int			i;
	int			k;
	int			j;
}				t_counters;

typedef	struct	s_coords
{
	double		x;
	double		y;
	int			zoom;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	int			i;
	int			l;
	int			z;
	int			j;
	int			dy;
	int			move_x;
	int			move_y;
	int			startx;
	int			starty;
	int			dx;
	int			xincr;
	int			yincr;
	char		*filename;
	int			**tab;
	int			colour;
	void		*mlx;
	void		*win;
}				t_coord;

char			**ft_read(char *fname);
void			ft_scopedy(t_coord *map, char *filename);
int				num_lines(char *filename);
int				num_digits(char *line);
int				count(char **str);
int				**convert(char **map, char *filename);

#endif
