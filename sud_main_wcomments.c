/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sud_main_wcomments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 10:22:16 by amendelo          #+#    #+#             */
/*   Updated: 2018/11/04 15:33:21 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //for write

int		ft_strlen(char *str)
{
	int len;
	len = 0;
	while(str[len])
		len++;
	return (len);
}

// for printing out the board with spaces between each character
void	print_board(char *av[])
{
	int row;
	int col;
	
	// row goes from 1 to 9
	row = 0;
	while (++row <= 9)
	{
		//col goes from 0 to 8
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

// check valid input puzzle
int		is_valid_sud(int ac, char *av[])
{
	int i;
	int j;
	int val_lines;
	// If have anything other than 10 input params, we know that we don't have 9 rows, so
	//		return error.
	if (ac != 10)
		return (0);
	// Next, we need to check that the rows are the correct length and have valid characters.
	else
	{
		i = 0;
		val_lines = 0;
		// traversing rows...
		while (++i <= 9 && ft_strlen(av[i]) == 9)
		{
			j = -1;
			// traversing columns (characters)...
			while (++j < 9)
			{
				// if the character is not valid, return error.
				if (!((av[i][j] >= '1' && av[i][j] <= '9') || av[i][j] == '.'))
					return (0);
			}
			// increase count of valid lines
			val_lines++;
		}
		// if we've got 9 valid lines, return true
		if (val_lines == 9)
			return (1);
		// otherwise, return false
		else
			return (0);
	}
}

// helper for is_move_ok
int		in_row(char *av[], char num, int row)
{
	int col;

	// columns go from 0 to 8
	col = -1;
	while (++col < 9)
	{
		if (av[row][col] == num)
			return (1);
	}
	return (0);
}

// helper for is_move_ok
int		in_col(char *av[], char num, int col)
{
	int row;
	
	// rows go from 1 to 9
	row = 0;
	while (++row <= 9)
	{
		if (av[row][col] == num)
			return (1);
	}
	return (0);
}

// helper for is_move_ok
int		in_box(char *av[], char num, int box_top_r, int box_top_c)
{
	int row;
	int col;

	// this is row/col for each box - so indices go from 0 to 2
	row = -1;
	while (++row < 3)
	{
		col = -1;
		while (++col < 3)
			if (av[row + box_top_r + 1][col + box_top_c] == num) // adding 1 to row because row starts at 1
				return (1);
	}
	return (0);
}

// check that current move is valid
int		is_move_ok(char *av[], char num, int row, int col)
{
	// need to check move against current row, column, and box to make sure that 
	//		the number has not already been placed
	// in in_box, adjust input row by 1 so that we give it the correct index.
	//		without this correction, when it's on the bottom row of a given box, 
	//		it'll think it's on the next row down. this is because we're using
	//		*argv[] directly, and row 0 on that is the name of the binary rather than
	//		the first row in the puzzle.
	return (!in_row(av, num, row) &&
			!in_col(av, num, col) &&
			!in_box(av, num, (row - 1) - (row - 1) % 3, col - col % 3));
}

// search grid to find next unassigned space. if found, set row/col to those indices,
//		and return (1). if grid is completely assigned, returns (0).
int		find_unassigned(char *av[], int *row, int *col)
{
	// row goes 1 to 9
	*row = 0;
	while (++(*row) <= 9)
	{
		// col goes 0 to 8
		*col = -1;
		while (++(*col) < 9)
			if (av[*row][*col] == '.') // character . represents unassigned space
				return (1);
	}
	return (0);
}

int		solve_sud(char *av[])
{
	int		row;
	int		col;
	char	num;

	// if no unassigned location, board is solved! yay!
	if (!find_unassigned(av, &row, &col))
		return (1);
	
	// once we've got an unassigned location, consider characters 1 to 9 for placement
	num = '0';
	while (++num <= '9')
	{
		// once we find a number that can fit here...
		if (is_move_ok(av, num, row, col))
		{
			// ...make the assignment...
			av[row][col] = num;
			// ...then check that we can solve the rest of the grid with this assignment.
			if (solve_sud(av))
				return (1);
			av[row][col] = '.';
		}
	}
	// if we've made it here, there are no valid assignments based on the last number entered,
	//		so we need to go back and change the previous number placed.
	// ie, this is what triggers backtracking.
	return (0);
}

int		main(int argc, char *argv[])
{
	if (is_valid_sud(argc, argv))
	{
		if (solve_sud(argv))
			print_board(argv);
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
