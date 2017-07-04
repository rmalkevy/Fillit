/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteslenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 13:14:00 by yteslenk          #+#    #+#             */
/*   Updated: 2016/12/21 17:46:34 by yteslenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfill.h"

void	print_solution(char **square)
{
	int y;
	int x;

	y = 0;
	while (square[y])
	{
		x = 0;
		while (square[y][x])
		{
			write(1, &square[y][x], 1);
			x++;
		}
		y++;
		write(1, "\n", 1);
	}
}

int		is_safe(char **square, int *var, t_struct *figur)
{
	int	i;
	int	y;
	int	x;
	int	j;
	int	size;

	size = 0;
	i = 0;
	y = var[0];
	x = var[1];
	j = var[2];
	while (square[size])
		size++;
	while (i < 4)
	{
		if (y + figur[j].y[i] >= size || x + figur[j].x[i] >= size
			|| x + figur[j].x[i] < 0)
			return (0);
		if (square[y + figur[j].y[i]][x + figur[j].x[i]] != '.')
			return (0);
		i++;
	}
	return (1);
}

int		recurtion(char **square, int j, int fnum, t_struct *figur)
{
	int	y;
	int	x;
	int	*var;

	y = -1;
	while (square[++y])
	{
		x = 0;
		while (square[y][x])
		{
			var = fvar(y, x, j);
			if (is_safe(square, var, figur))
			{
				fgwrite(square, var, figur);
				if (j == fnum - 1)
					return (1);
				if (recurtion(square, j + 1, fnum, figur))
					return (1);
				fgclear(square, var, figur);
			}
			free(var);
			x++;
		}
	}
	return (0);
}

int		magic(char **square, t_struct *figur, int fnum, int size)
{
	while (recurtion(square, 0, fnum, figur) == 0)
	{
		size++;
		free(square);
		square = ft_square(size);
	}
	print_solution(square);
	return (1);
}
