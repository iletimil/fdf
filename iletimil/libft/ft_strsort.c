/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iletimil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 20:26:36 by iletimil          #+#    #+#             */
/*   Updated: 2018/06/08 20:33:43 by iletimil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strsort(char const *s, char c)
{
	int	sort1;
	int	sort2;

	sort1 = 0;
	sort2 = 0;
	while (s[sort1])
	{
		if (s[sort1] == c)
			;
		else if (!sort1 || !(s[sort1 - 1] == c))
			sort2++;
		sort1++;
	}
	return (sort2);
}
