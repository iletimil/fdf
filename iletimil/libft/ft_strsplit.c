/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iletimil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 10:51:12 by iletimil          #+#    #+#             */
/*   Updated: 2018/06/20 11:03:35 by iletimil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static int	nstrings(char const *str, char c)
{
	int		i;
	int		ptr;

	i = 0;
	ptr = 0;
	while (str[i])
	{
		if (str[i] == c)
			;
		else if (!i || str[i - 1] == c)
			ptr++;
		i++;
	}
	return (ptr);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	size_t	j;
	char	**ret;
	int		start;

	i = 0;
	j = 0;
	if (s == 0 || c == 0)
		return (NULL);
	if (!(ret = (char **)malloc(sizeof(char *) * (nstrings(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			ret[j++] = ft_strsub(s, start, (i - start));
		}
	}
	ret[j] = 0;
	return (ret);
}
