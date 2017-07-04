/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mass.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteslenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 13:36:01 by yteslenk          #+#    #+#             */
/*   Updated: 2016/12/21 17:36:34 by yteslenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfill.h"

static	int			ft_yflag(char **buf)
{
	int	y;
	int	x;

	y = 0;
	while (buf[y])
	{
		x = 0;
		while (buf[y][x])
		{
			if (buf[y][x] == '#')
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

static	int			ft_xflag(char **buf)
{
	int	y;
	int	x;

	y = 0;
	while (buf[y])
	{
		x = 0;
		while (buf[y][x])
		{
			if (buf[y][x] == '#')
				return (x);
			x++;
		}
		y++;
	}
	return (0);
}

static	void		ft_coordinate(char **buf, t_struct *array, int index)
{
	int	y;
	int	x;
	int	xflag;
	int	yflag;
	int	cell;

	y = 0;
	cell = 0;
	xflag = ft_xflag(buf);
	yflag = ft_yflag(buf);
	while (buf[y])
	{
		x = 0;
		while (buf[y][x])
		{
			if (buf[y][x] == '#')
			{
				array[index].x[cell] = x - xflag;
				array[index].y[cell] = y - yflag;
				cell++;
			}
			x++;
		}
		y++;
	}
}

static	char		**ft_string(char **buf, char *abc, int size)
{
	int	i;
	int	j;
	int	line;
	int	limit;

	i = 0;
	line = 0;
	limit = 5;
	while (line < size)
	{
		buf[line] = (char *)malloc(sizeof(char *) * 5 + 1);
		j = 0;
		while (i < limit)
		{
			buf[line][j] = abc[i];
			i++;
			j++;
		}
		buf[line][j] = '\0';
		line++;
		limit = limit + 5;
	}
	buf[line] = 0;
	return (buf);
}

t_struct			*ft_mass(char **argv, int size)
{
	char		abc[22];
	char		**buf;
	t_struct	*array;
	int			fd;
	int			index;

	size = (size + 1) / 21;
	fd = open(argv[1], O_RDONLY);
	array = (t_struct *)malloc(sizeof(t_struct) * size);
	buf = (char **)malloc(sizeof(char *) * 5);
	index = 0;
	while (read(fd, abc, 21))
	{
		buf = ft_string(buf, abc, 5);
		ft_coordinate(buf, array, index);
		index++;
	}
	return (array);
}
