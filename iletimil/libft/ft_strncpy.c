/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iletimil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:47:30 by iletimil          #+#    #+#             */
/*   Updated: 2018/06/26 09:55:56 by iletimil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = n;
	while (src[i] != '\0' && i != n)
	{
		dest[i] = src[i];
		i++;
		j--;
	}
	while (j != 0)
	{
		dest[i] = '\0';
		i++;
		j--;
	}
	return (dest);
}
