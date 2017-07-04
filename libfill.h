/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteslenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 13:08:49 by yteslenk          #+#    #+#             */
/*   Updated: 2016/12/21 17:01:04 by yteslenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFILL_H
# define LIBFILL_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_shape
{
	int			x[4];
	int			y[4];
}				t_struct;
int				valid_part2(char *s, int i);
int				figure(char *s);
t_struct		*ft_mass(char **argv, int size);
char			**ft_square(int len);
int				magic(char **square, t_struct *figur, int fnum, int size);
void			print_solution(char **square);
int				is_safe(char **square, int *var, t_struct *figur);
int				recurtion(char **square, int j, int fnum, t_struct *figur);
int				size_square(int len);
void			fgclear(char **square, int *var, t_struct *figur);
void			fgwrite(char **square, int *var, t_struct *figur);
int				*fvar(int y, int x, int j);
#endif
