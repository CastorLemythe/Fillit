/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:30:53 by lufranco          #+#    #+#             */
/*   Updated: 2017/12/23 18:08:31 by lufranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_name_tetris(char *tab)
{
	char	letter;
	int		nb_hash;
	int		cur;

	if (tab == NULL)
		return ;
	letter = 'A';
	nb_hash = 0;
	cur = 0;
	while (tab[cur] != '\0')
	{
		if (tab[cur] == '#')
		{
			tab[cur] = letter;
			nb_hash++;
		}
		if (nb_hash == 4)
		{
			nb_hash = 0;
			letter++;
		}
		cur++;
	}
}

char	*ft_get_tab(char *sample, int fd)
{
	char	*dest;
	int		i;
	int		b;

	dest = (char *)malloc(sizeof(char *) * 21);
	i = 0;
	b = 1;
	while (b)
	{
		b = read(fd, dest, 20);
		i += b;
	}
	free(dest);
	dest = (char *)malloc(sizeof(char *) * (i + 1));
	if (dest == NULL)
		return (NULL);
	close(fd);
	fd = open(sample, O_RDONLY);
	if (fd == -1)
		return (NULL);
	read(fd, dest, i);
	dest[i] = '\0';
	return (dest);
}

int		main(int argc, char **argv)
{
	t_case	*stock;
	char	*in_file;
	int		fd;

	stock = malloc(sizeof(t_case));
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("error\n");
		return (0);
	}
	in_file = ft_get_tab(argv[1], fd);
	if (!(ft_sample_valid(in_file, stock)) || !(in_file))
	{
		ft_putstr("error\n");
		return (0);
	}
	ft_name_tetris(in_file);
	ft_resolve_tetris(in_file, stock);
	return (0);
}
