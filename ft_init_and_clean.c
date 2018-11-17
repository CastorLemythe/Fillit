/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_and_clean.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:17:25 by lufranco          #+#    #+#             */
/*   Updated: 2017/11/24 17:24:21 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_clean(char **dest, int piece)
{
	int		i;
	int		j;

	j = 0;
	while (dest[j])
	{
		i = 0;
		while (dest[j][i] != '\0')
		{
			if (dest[j][i] == 'A' + piece)
				dest[j][i] = '.';
			i++;
		}
		j++;
	}
}

int		ft_first_grill(char *sample)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (sample[i] != '\0')
	{
		if (ft_isalpha(sample[i]))
			n++;
		i++;
	}
	i = 0;
	while (i * i < n)
		i++;
	return (i);
}

char	**ft_init_tab(char **dest, char *sample, t_case *stock)
{
	int		index;

	if (stock->len == 0)
		stock->len = ft_first_grill(sample);
	else
		free(dest);
	index = 0;
	dest = (char **)malloc(sizeof(*dest) * (stock->len + 1));
	if (!dest)
		return (NULL);
	dest[stock->len] = 0;
	while (index < stock->len)
	{
		dest[index] = (char *)malloc(sizeof(*dest) * (stock->len + 1));
		if (!dest)
			return (NULL);
		ft_memset(dest[index], '.', stock->len);
		dest[index][stock->len] = '\0';
		index++;
	}
	return (dest);
}
