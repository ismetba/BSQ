/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:57:12 by ibayandu          #+#    #+#             */
/*   Updated: 2024/09/02 16:49:29 by yzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/commons.h"
#include "../includes/bsq.h"
#include "../includes/errors.h"
#include <libc.h>
#include <stdio.h>

int	ft_fill_matrix(int ***sol_matrix, int **original_matrix, int i, int j)
{
	if (i == 0 || j == 0)
		(*sol_matrix)[i][j] = original_matrix[i][j];
	else if (original_matrix[i][j] == 1)
		(*sol_matrix)[i][j] = ft_min((*sol_matrix)[i - 1][j],
				(*sol_matrix)[i][j - 1], (*sol_matrix)[i - 1][j - 1]) + 1;
	else
		(*sol_matrix)[i][j] = 0;
	return ((*sol_matrix)[i][j]);
}

void	ft_allocate_solution(int ***sol_matrix, int row, int column)
{
	int	i;

	i = -1;
	*sol_matrix = (int **)malloc(row * sizeof(int *));
	check_malloc(*sol_matrix);
	while (++i < row)
	{
		(*sol_matrix)[i] = (int *)malloc(column * sizeof(int));
		check_malloc((*sol_matrix)[i]);
	}
}

void	ft_set_solution(t_solution *solution, int size, int x, int y)
{
	(*solution).size = size;
	(*solution).x = x;
	(*solution).y = y;
}

t_solution	ft_solution_matrix(int **original_matrix, int row, int column)
{
	struct s_solution		solution;
	int						**sol_matrix;
	int						i;
	int						j;

	i = -1;
	ft_set_solution(&solution, 0, 0, 0);
	ft_allocate_solution(&sol_matrix, row, column);
	while (++i < row)
	{
		j = -1;
		while (++j < column)
		{
			if (ft_fill_matrix(&sol_matrix, original_matrix, i, j)
				> solution.size)
			{
				ft_set_solution(&solution, sol_matrix[i][j], j, i);
			}
		}
	}
	solution.sol_matrix = sol_matrix;
	return (solution);
}
