/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_part2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteslenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:25:14 by yteslenk          #+#    #+#             */
/*   Updated: 2016/12/21 17:43:56 by yteslenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfill.h"

int		valid_15_17(char *s, int i)
{
	int	count;

	count = 0;
	if (s[i + 1] == '#')
		count++;
	if (s[i - 1] == '#')
		count++;
	if (s[i - 5] == '#')
		count++;
	return (count);
}

int		valid_part2(char *s, int i)
{
	int	count;

	count = 0;
	if (i == 15 || i == 16 || i == 17)
		count = valid_15_17(s, i);
	if (i == 18)
	{
		if (s[i - 5] == '#')
			count++;
		if (s[i - 1] == '#')
			count++;
	}
	if (i == 1 || i == 2)
	{
		if (s[i + 1] == '#')
			count++;
		if (s[i - 1] == '#')
			count++;
		if (s[i + 5] == '#')
			count++;
	}
	return (count);
}
