/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_tetris.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 18:19:25 by lufranco          #+#    #+#             */
/*   Updated: 2017/12/09 11:20:39 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_choose_piece(char **dest, int actual_piece)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	while (dest[y])
	{
		if (dest[y][x] == 'A' + actual_piece)
		{
			actual_piece++;
			x = 0;
			y = 0;
		}
		x++;
		if (dest[y][x] == '\0')
		{
			x = 0;
			y++;
		}
	}
	return (actual_piece);
}

int		ft_solution(char **dest, char *sample, t_case *stock, int actual_piece)
{
	int		jump_dot;

	if (stock->piece_place == stock->piece_total)
		return (1);
	while (actual_piece < stock->piece_total)
	{
		jump_dot = 0;
		stock->jump_dot = 0;
		while (ft_place(dest, sample, stock, actual_piece))
		{
			stock->piece_place++;
			if (ft_solution(dest, sample, stock, ft_choose_piece(dest, 0)))
				return (1);
			stock->piece_place--;
			ft_clean(dest, actual_piece);
			jump_dot++;
			stock->jump_dot = jump_dot;
		}
		if (jump_dot == 0)
			return (0);
		actual_piece = ft_choose_piece(dest, ++actual_piece);
	}
	return (0);
}

void	ft_resolve_tetris(char *sample, t_case *stock)
{
	char	**dest;
	int		actual_piece;
	int		found;

	stock->piece_place = 0;
	stock->x = 0;
	stock->y = 0;
	stock->len = 0;
	actual_piece = 0;
	found = 0;
	while (!(found))
	{
		dest = ft_init_tab(dest, sample, stock);
		found = ft_solution(dest, sample, stock, actual_piece);
		stock->len++;
	}
	ft_put_solution(dest);
	free(dest);
}
