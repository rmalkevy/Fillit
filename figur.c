/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figur.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteslenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 13:33:00 by yteslenk          #+#    #+#             */
/*   Updated: 2016/12/21 13:35:37 by yteslenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfill.h"

void	fgwrite(char **square, int *var, t_struct *figur)
{
	int	i;
	int	y;
	int	x;
	int	j;

	i = 0;
	y = var[0];
	x = var[1];
	j = var[2];
	while (i < 4)
	{
		square[y + figur[j].y[i]][x + figur[j].x[i]] = 'A' + j;
		i++;
	}
}

void	fgclear(char **square, int *var, t_struct *figur)
{
	int	i;
	int	y;
	int	x;
	int	j;

	i = 0;
	y = var[0];
	x = var[1];
	j = var[2];
	while (i < 4)
	{
		square[y + figur[j].y[i]][x + figur[j].x[i]] = '.';
		i++;
	}
}

int		*fvar(int y, int x, int j)
{
	int	*var;

	var = (int*)malloc(sizeof(int) * 3);
	var[0] = y;
	var[1] = x;
	var[2] = j;
	return (var);
}
