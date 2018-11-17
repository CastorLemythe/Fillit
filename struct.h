/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 11:20:51 by kehuang           #+#    #+#             */
/*   Updated: 2017/12/09 11:19:43 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_case
{
	int		piece_total;
	int		piece_place;
	int		jump_dot;
	int		len;
	int		x;
	int		y;
	char	c;
}				t_case;
#endif
