/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:57:12 by ibayandu          #+#    #+#             */
/*   Updated: 2024/09/01 19:04:00 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/commons.h"
#include <libc.h>

int	**ft_solution_matrix(int **original_matrix, int row, int column)
{
	int	**sol_matrix;
	int	i;
	int	j;

	i = 0;
	sol_matrix = (int **)malloc(row * sizeof(int *));
	while (i < row)
		sol_matrix[i++] = (int *)malloc(column * sizeof(int));
	i = -1;
	while (++i < row)
	{
		j = -1;
		while (++j < column)
		{
			if (i == 0 || j == 0)
				sol_matrix[i][j] = original_matrix[i][j];
			else if (original_matrix[i][j] == 1)
				sol_matrix[i][j] = ft_min(sol_matrix[i - 1][j], sol_matrix[i][j
						- 1], sol_matrix[i - 1][j - 1]) + 1;
			else
				sol_matrix[i][j] = 0;
		}
	}
	return (sol_matrix);
}
