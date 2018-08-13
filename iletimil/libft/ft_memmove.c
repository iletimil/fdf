/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iletimil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:10:39 by iletimil          #+#    #+#             */
/*   Updated: 2018/06/08 16:49:03 by iletimil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*s1;
	char			*s2;

	i = 0;
	s1 = (char *)dest;
	s2 = (char *)src;
	if (s2 < s1)
	{
		while (n-- > 0)
			s1[n] = s2[n];
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (s1);
}
