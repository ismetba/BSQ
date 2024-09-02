/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:57:12 by ibayandu          #+#    #+#             */
/*   Updated: 2024/09/02 13:43:20 by yzeybek          ###   ########.fr       */
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

t_solution	ft_solution_matrix(int **original_matrix, int row, int column)
{
	struct s_solution		solution;
	int						**sol_matrix;
	int						i;
	int						j;

	i = -1;
	solution.size = 0;
	solution.x = 0;
	solution.y = 0;
	sol_matrix = (int **)malloc(row * sizeof(int *));
	check_malloc(sol_matrix);
	while (++i < row)
	{
		sol_matrix[i] = (int *)malloc(column * sizeof(int));
		check_malloc(sol_matrix[i]);
	}
	i = -1;
	while (++i < row)
	{
		j = -1;
		while (++j < column)
		{
			if (ft_fill_matrix(&sol_matrix, original_matrix, i, j)
				> solution.size)
			{
				solution.size = sol_matrix[i][j];
				solution.x = j;
				solution.y = i;
			}
		}
	}
	solution.sol_matrix = sol_matrix;
	return (solution);
}
