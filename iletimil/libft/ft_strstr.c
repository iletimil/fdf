/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iletimil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 18:55:06 by iletimil          #+#    #+#             */
/*   Updated: 2018/06/07 17:35:07 by iletimil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strstr(char *hay, char *needle)
{
	int i;
	int j;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)hay);
	while (hay[i] != '\0')
	{
		j = 0;
		while (needle[j] == hay[i + j])
		{
			if (needle[j + 1] == '\0')
				return ((char *)hay + i);
			j++;
		}
		i++;
	}
	return (0);
}
