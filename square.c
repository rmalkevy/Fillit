/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 16:51:26 by rmalkevy          #+#    #+#             */
/*   Updated: 2016/12/21 16:06:14 by yteslenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfill.h"

int			size_square(int len)
{
	int size;
	int res;
	int fnum;

	fnum = (len + 1) / 21;
	size = fnum * 4;
	res = 0;
	while (res * res < size)
		res++;
	return (res);
}

char		**ft_square(int size)
{
	char	**square;
	int		index;
	int		i;

	index = 0;
	square = (char **)malloc(sizeof(char *) * (size + 1));
	while (index < size)
	{
		i = 0;
		square[index] = (char*)malloc(sizeof(char) * (size + 1));
		while (i < size)
		{
			square[index][i] = '.';
			i++;
		}
		square[index][i] = '\0';
		index++;
	}
	square[size] = 0;
	return (square);
}
