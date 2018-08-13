/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iletimil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 13:07:18 by iletimil          #+#    #+#             */
/*   Updated: 2018/06/05 18:50:23 by iletimil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*as;

	as = (char *)s;
	i = 0;
	while ((as[i] != c) && as[i])
		as++;
	if (as[i] == c)
		return (as);
	return (NULL);
}
