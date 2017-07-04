/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteslenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:30:22 by yteslenk          #+#    #+#             */
/*   Updated: 2016/12/21 17:45:05 by yteslenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfill.h"

int		block_5_13(char *s, int i)
{
	int	count;

	count = 0;
	if (s[i + 5] == '#')
		count++;
	if (s[i - 5] == '#')
		count++;
	if (s[i + 1] == '#')
		count++;
	if (s[i - 1] == '#')
		count++;
	return (count);
}

int		valid_part1(char *s, int i)
{
	int	count;

	count = 0;
	if ((i >= 5 && i <= 8) || (i >= 10 && i <= 13))
		count = block_5_13(s, i);
	if (i == 0)
	{
		if (s[i + 1] == '#')
			count++;
		if (s[i + 5] == '#')
			count++;
	}
	if (i == 3)
	{
		if (s[i - 1] == '#')
			count++;
		if (s[i + 5] == '#')
			count++;
	}
	return (count);
}

int		figure(char *s)
{
	int	i;
	int	count;
	int	res;

	i = 0;
	count = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] == '#')
		{
			if (i == 0 || (i >= 3 && i <= 13))
			{
				count = valid_part1(s, i);
				res = res + count;
			}
			if ((i >= 15 && i <= 18) || i == 1 || i == 2)
			{
				count = valid_part2(s, i);
				res = res + count;
			}
		}
		i++;
	}
	return (res);
}
