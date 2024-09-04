/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:57:12 by ibayandu          #+#    #+#             */
/*   Updated: 2024/09/04 11:12:39 by yzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/commons.h"

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

int	ft_allocate_solution(t_solution *solution, int row, int column)
{
	int	i;

	i = -1;
	(*solution).sol_matrix = (int **)malloc(row * sizeof(int *));
	if (!((*solution).sol_matrix))
	{
		(*solution).size = -1;
		(*solution).x = -1;
		return (0);
	}
	while (++i < row)
	{
		(*solution).sol_matrix[i] = (int *)malloc(column * sizeof(int));
		if (!((*solution).sol_matrix[i]))
		{
			(*solution).size = -1;
			(*solution).x = i;
			return (0);
		}
	}
	return (1);
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
	int						i;
	int						j;

	i = -1;
	ft_set_solution(&solution, 0, 0, 0);
	if (!ft_allocate_solution(&solution, row, column))
		return (solution);
	while (++i < row)
	{
		j = -1;
		while (++j < column)
		{
			if (ft_fill_matrix(&(solution.sol_matrix), original_matrix, i, j)
				> solution.size)
			{
				ft_set_solution(&solution, solution.sol_matrix[i][j], j, i);
			}
		}
	}
	return (solution);
}
