/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteslenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:51:32 by yteslenk          #+#    #+#             */
/*   Updated: 2016/12/21 17:44:42 by yteslenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfill.h"

int		ft_len(char **argv)
{
	char	box[700];
	int		desc;
	int		len;

	desc = open(argv[1], O_RDONLY);
	len = read(desc, box, 650);
	return (len);
}

int		place_n(char **argv, int blocks)
{
	char	box[22];
	int		i;
	int		j;
	int		desc;
	int		count;

	count = 0;
	desc = open(argv[1], O_RDONLY);
	while (read(desc, box, 21))
	{
		j = 0;
		i = 1;
		while (j < 20)
		{
			if (box[j] == '\n' && i % 5 != 0)
				return (0);
			i++;
			j++;
		}
		count++;
		blocks--;
		if ((box[20] != '\n' && blocks > 0) || count > 26)
			return (0);
	}
	return (1);
}

int		ft_revision(char **argv, char *box, int blocks)
{
	int		dots;
	int		hashes;
	int		i;
	int		res;

	i = 0;
	dots = blocks * 12;
	hashes = blocks * 4;
	while (box[i])
	{
		if (box[i] == '.')
			dots--;
		if (box[i] == '#')
			hashes--;
		i++;
	}
	if (dots > 0 || hashes > 0)
		return (0);
	res = place_n(argv, blocks);
	return (res);
}

int		ft_valid(char **argv)
{
	char	box[700];
	char	tmp[22];
	int		res;
	int		desc;
	int		blocks;

	desc = open(argv[1], O_RDONLY);
	res = read(desc, box, 650);
	if ((res + 1) % 21 != 0)
		return (0);
	blocks = (res + 1) / 21;
	if ((res = ft_revision(argv, box, blocks)) == 0)
		return (0);
	close(desc);
	desc = open(argv[1], O_RDONLY);
	while (read(desc, tmp, 21))
	{
		res = figure(tmp);
		if (res < 6)
			return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int			len;
	int			revision;
	char		**square;
	t_struct	*figur;
	int			fnum;

	if (argc == 2)
	{
		len = ft_len(argv);
		if ((revision = ft_valid(argv)) != 1)
		{
			write(1, "error\n", 6);
			return (0);
		}
		figur = ft_mass(argv, len);
		square = ft_square(size_square(len));
		fnum = (len + 1) / 21;
		magic(square, figur, fnum, size_square(len));
	}
	return (0);
}
