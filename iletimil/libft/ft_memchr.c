/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iletimil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 16:20:39 by iletimil          #+#    #+#             */
/*   Updated: 2018/06/07 15:19:25 by iletimil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*as;

	as = (char *)s;
	i = 0;
	while (n > i)
	{
		if ((unsigned char)as[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
