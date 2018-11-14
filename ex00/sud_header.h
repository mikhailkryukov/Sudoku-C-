/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sud_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 15:41:34 by amendelo          #+#    #+#             */
/*   Updated: 2018/11/04 20:27:51 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUD_HEADER_H
# define SUD_HEADER_H
# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(char *str);
int		mats_same(char **mat1, char **mat2);
char	**mat_dup(char *av[]);
void	mat_clear(char *mat[]);
void	print_board(char *av[]);
int		is_valid_sud(int ac, char *av[]);
int		in_row(char *av[], char num, int row);
int		in_col(char *av[], char num, int col);
int		in_box(char *av[], char num, int box_top_r, int box_top_c);
int		is_move_ok(char *av[], char num, int row, int col);
int		find_unassigned(char *av[], int *row, int *col);
int		solve_sud(char *av[]);
int		main(int argc, char *argv[]);

#endif
