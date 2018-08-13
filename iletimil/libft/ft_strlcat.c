/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iletimil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 17:05:36 by iletimil          #+#    #+#             */
/*   Updated: 2018/06/07 16:52:57 by iletimil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t len;

	i = 0;
	len = 0;
	while (dst[i] && dstsize > i)
		i++;
	while (src[len] && (i + len + 1) < dstsize)
	{
		dst[len + i] = src[len];
		len++;
	}
	if (i != dstsize)
		dst[i + len] = '\0';
	return (i + ft_strlen(src));
}
