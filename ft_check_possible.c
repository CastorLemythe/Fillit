/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_possible.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 14:20:33 by kehuang           #+#    #+#             */
/*   Updated: 2017/12/08 11:26:42 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_find_first_block(char *sample, char c)
{
	int		i;
	int		x;
	int		y;

	x = 0;
	while (sample[x] != c)
		x++;
	y = (x / 21) * 21;
	x = x % 21;
	while (sample[y] != c)
	{
		i = -1;
		while (++i < 4 && sample[y] != c)
			y = y + 5;
		if (i == 4)
			y = y - 19;
	}
	y = y % 21;
	if (y == x)
		return (0);
	if (y - x == 3)
		return (-2);
	else
		return (-1);
}

int		ft_check(char **dest, char *sample, t_case *stock, int cur)
{
	int		nb_bloc;
	int		index;
	int		x;
	int		y;

	x = stock->x;
	y = stock->y;
	nb_bloc = -1;
	index = 0;
	while (sample[index] != stock->c)
		index++;
	index = index + ft_find_first_block(sample, stock->c);
	while (++nb_bloc < 4)
	{
		while (sample[index + cur] != stock->c)
			cur++;
		x = stock->x + cur % 5 + ft_find_first_block(sample, stock->c);
		y = stock->y + cur / 5;
		if (y > stock->len - 1 || dest[y][x] != '.')
			return (0);
		dest[y][x] = stock->c;
		cur++;
	}
	return (1);
}

int		ft_place(char **dest, char *sample, t_case *stock, int actual_piece)
{
	stock->y = 0;
	stock->x = 0;
	while (dest[stock->y])
	{
		while (dest[stock->y][stock->x] != '\0' &&
				dest[stock->y][stock->x] != '.')
			stock->x++;
		if (dest[stock->y][stock->x] == '\0')
		{
			stock->x = 0;
			stock->y++;
		}
		else
		{
			stock->c = 'A' + actual_piece;
			if (ft_check(dest, sample, stock, 0))
				if (stock->jump_dot-- == 0)
					return (1);
			ft_clean(dest, actual_piece);
			stock->x++;
		}
	}
	return (0);
}
