/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iletimil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 10:08:56 by iletimil          #+#    #+#             */
/*   Updated: 2018/06/26 10:30:05 by iletimil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include "libft/includes/libft.h"

static int		getc_fd(char **str, char **line)
{
	char		*tmp;
	size_t		i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '\n')
		{
			tmp = *str;
			*line = ft_strsub(*str, 0, i);
			*str = ft_strsub(*str, i + 1, ft_strlen(*str) - i);
			free(tmp);
			return (1);
		}
		++i;
	}
	return (0);
}

static int		ft_endl(char *str, char **line)
{
	if (str[0])
	{
		*line = ft_strdup(str);
		ft_strclr(str);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char		*c;
	char			*buf;
	int				ret;

	buf = ft_strnew(BUFF_SIZE);
	if (!c)
		c = ft_strnew(BUFF_SIZE);
	if (fd < 0 || !line || BUFF_SIZE < 1 || (read(fd, buf, 0) < 0))
		return (-1);
	if (getc_fd(&c, line))
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		c = ft_strjoin_clr(c, buf);
		if (getc_fd(&c, line))
		{
			free(buf);
			return (1);
		}
	}
	if (ft_endl(c, line))
		return (1);
	return (0);
}
