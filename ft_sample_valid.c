/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sample_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:54:37 by lufranco          #+#    #+#             */
/*   Updated: 2017/12/23 17:59:55 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_nbr_bond(int *pos_hash)
{
	int		index_hash;
	int		i;
	int		n;

	index_hash = 3;
	n = 0;
	while (index_hash >= 0)
	{
		i = 0;
		while (i < 4)
		{
			if (pos_hash[index_hash] - 5 == pos_hash[i] && index_hash != i)
				n++;
			if (pos_hash[index_hash] + 5 == pos_hash[i] && index_hash != i)
				n++;
			if (pos_hash[index_hash] - 1 == pos_hash[i] && index_hash != i)
				n++;
			if (pos_hash[index_hash] + 1 == pos_hash[i] && index_hash != i)
				n++;
			i++;
		}
		index_hash--;
	}
	return (n);
}

int		ft_exist_tetris(char *tab)
{
	int		pos_hash[4];
	int		count_hash;
	int		nb_bond;
	int		cur;
	int		i;

	cur = 0;
	while (tab[cur] != '\0')
	{
		count_hash = 0;
		nb_bond = 0;
		i = 0;
		while (tab[cur] != '\0' && i++ <= 20)
		{
			if (tab[cur++] == '#')
			{
				pos_hash[count_hash] = cur + 1;
				count_hash++;
			}
		}
		nb_bond = ft_nbr_bond(pos_hash);
		if (nb_bond != 6 && nb_bond != 8)
			return (0);
	}
	return (1);
}

int		ft_grill_correct(char *tab)
{
	int		i;
	int		x;
	int		y;

	i = -1;
	while (tab[++i] != '\0')
	{
		y = 0;
		while (y++ < 4)
		{
			x = 0;
			while (x++ < 4)
			{
				if (tab[i] != '.' && tab[i] != '#')
					return (0);
				i++;
			}
			if (tab[i] != '\n')
				return (0);
			i++;
		}
		if (tab[i] == '\0')
			return (1);
	}
	return (0);
}

int		ft_nbr_piece(char *tab)
{
	int		nb_piece;
	int		i;

	nb_piece = 0;
	i = 0;
	if (tab[0] == '.' || tab[0] == '#')
		nb_piece = 1;
	while (tab[i] != '\0')
	{
		if (tab[i] == '\n' && tab[i + 1] == '\n')
		{
			while (tab[i] == '\n' && tab[i] != '\0')
				i++;
			if (tab[i] == '.' || tab[i] == '#')
				nb_piece++;
		}
		if (tab[i] != '\0')
			i++;
	}
	return (nb_piece);
}

int		ft_sample_valid(char *tab, t_case *stock)
{
	int		count_hash;
	int		i;

	i = -1;
	count_hash = 0;
	stock->piece_total = ft_nbr_piece(tab);
	if (stock->piece_total == 0 || stock->piece_total > 26)
		return (0);
	if (!(ft_grill_correct(tab)))
		return (0);
	while (tab[++i])
		if (tab[i] == '#')
			count_hash++;
	if (count_hash / 4 != stock->piece_total || count_hash % 4 != 0)
		return (0);
	if (!(ft_exist_tetris(tab)))
		return (0);
	return (1);
}
