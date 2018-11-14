/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sud_solver_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 15:51:28 by amendelo          #+#    #+#             */
/*   Updated: 2018/11/04 20:24:41 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sud_header.h"

int		in_row(char *av[], char num, int row)
{
	int col;

	col = -1;
	while (++col < 9)
	{
		if (av[row][col] == num)
			return (1);
	}
	return (0);
}

int		in_col(char *av[], char num, int col)
{
	int row;

	row = -1;
	while (++row < 9)
	{
		if (av[row][col] == num)
			return (1);
	}
	return (0);
}

int		in_box(char *av[], char num, int box_top_r, int box_top_c)
{
	int row;
	int col;

	row = -1;
	while (++row < 3)
	{
		col = -1;
		while (++col < 3)
			if (av[row + box_top_r][col + box_top_c] == num)
				return (1);
	}
	return (0);
}

int		is_move_ok(char *av[], char num, int row, int col)
{
	return (!in_row(av, num, row) &&
			!in_col(av, num, col) &&
			!in_box(av, num, row - row % 3, col - col % 3));
}

int		find_unassigned(char *av[], int *row, int *col)
{
	*row = -1;
	while (++(*row) < 9)
	{
		*col = -1;
		while (++(*col) < 9)
			if (av[*row][*col] == '.')
				return (1);
	}
	return (0);
}
