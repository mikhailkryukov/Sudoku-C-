/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sud_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 10:22:16 by amendelo          #+#    #+#             */
/*   Updated: 2018/11/04 20:25:34 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sud_header.h"

int		is_valid_sud(int ac, char *av[])
{
	int i;
	int j;
	int val_lines;

	if (ac != 10)
		return (0);
	else
	{
		i = 0;
		val_lines = 0;
		while (++i <= 9 && ft_strlen(av[i]) == 9)
		{
			j = -1;
			while (++j < 9)
			{
				if (!((av[i][j] >= '1' && av[i][j] <= '9') || av[i][j] == '.'))
					return (0);
			}
			val_lines++;
		}
		if (val_lines == 9)
			return (1);
		else
			return (0);
	}
}

int		solve_sud19(char *av[])
{
	int		row;
	int		col;
	char	num;

	if (!find_unassigned(av, &row, &col))
		return (1);
	num = '0';
	while (++num <= '9')
	{
		if (is_move_ok(av, num, row, col))
		{
			av[row][col] = num;
			if (solve_sud19(av))
				return (1);
			av[row][col] = '.';
		}
	}
	return (0);
}

int		solve_sud91(char *av[])
{
	int		row;
	int		col;
	char	num;

	if (!find_unassigned(av, &row, &col))
		return (1);
	num = '9' + 1;
	while (--num >= '1')
	{
		if (is_move_ok(av, num, row, col))
		{
			av[row][col] = num;
			if (solve_sud91(av))
				return (1);
			av[row][col] = '.';
		}
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	char **mat1;
	char **mat2;

	if (is_valid_sud(argc, argv))
	{
		mat1 = mat_dup(argv);
		mat2 = mat_dup(argv);
		if (solve_sud19(mat1) &&
			solve_sud91(mat2) &&
			mats_same(mat1, mat2))
			print_board(mat1);
		else
		{
			write(1, "Error\n", 6);
		}
		mat_clear(mat1);
		mat_clear(mat2);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
