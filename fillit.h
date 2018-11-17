/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 11:15:00 by kehuang           #+#    #+#             */
/*   Updated: 2017/12/08 10:18:37 by kehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"
# include "struct.h"

void	ft_put_solution(char **dest);
char	**ft_init_tab(char **dest, char *sample, t_case *stock);
void	ft_clean(char **dest, int actual_piece);
void	ft_name_tetris(char *tab);
void	ft_resolve_tetris(char *sample, t_case *stock);
char	*ft_get_tab(char *sample, int fd);
int		ft_solution(char **dest, char *sample, t_case *stock, int actual_piece);
int		ft_last_sol(char **dest, char *sample, t_case *stock, int actual_piece);
int		ft_first_grill(char *sample);
int		ft_grill_correct(char *tab);
int		ft_sample_valid(char *tab, t_case *stock);
int		ft_exist_tetris(char *tab);
int		ft_hash_bond(int *pos_hash);
int		ft_nbr_piece(char *tab);
int		ft_place(char **dest, char *sample, t_case *stock, int actual_piece);
int		ft_check(char **dest, char *sample, t_case *stock, int cur);
int		ft_choose_piece(char **dest, int actual_piece);
int		ft_retry(char **dest, char *sample, t_case *stock, int actual_piece);
int		ft_isalpha(int c);
void	ft_putchar(char c);
void	ft_putstr(const char *str);
void	*ft_memset(void *b, int c, size_t len);
#endif
