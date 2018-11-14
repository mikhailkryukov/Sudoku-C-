/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sud_matrix_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 20:20:07 by amendelo          #+#    #+#             */
/*   Updated: 2018/11/04 20:28:03 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sud_header.h"

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		mats_same(char **mat1, char **mat2)
{
	int row;
	int col;

	row = -1;
	while (++row < 9)
	{
		col = -1;
		while (++col < 9)
			if (mat1[row][col] != mat2[row][col])
				return (0);
	}
	return (1);
}

char	**mat_dup(char *av[])
{
	char	**matrix;
	int		row;
	int		col;

	matrix = (char**)malloc(9 * sizeof(char*));
	row = -1;
	while (++row < 9)
	{
		matrix[row] = (char*)malloc(10 * sizeof(char));
	}
	row = -1;
	while (++row < 9)
	{
		col = -1;
		while (++col < 9)
			matrix[row][col] = av[row + 1][col];
	}
	return (matrix);
}

void	mat_clear(char *mat[])
{
	int		row;

	row = -1;
	while (++row < 9)
	{
		free(mat[row]);
	}
	free(mat);
}

void	print_board(char *av[])
{
	int row;
	int col;

	row = -1;
	while (++row < 9)
	{
		col = -1;
		while (++col < 9)
		{
			write(1, &av[row][col], 1);
			if (col < 8)
				write(1, " ", 1);
			else
				write(1, "\n", 1);
		}
	}
}
