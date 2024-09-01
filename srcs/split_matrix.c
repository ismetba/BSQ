/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:18:40 by ibayandu          #+#    #+#             */
/*   Updated: 2024/09/01 17:34:23 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"
#include "../includes/commons.h"
#include "../includes/errors.h"
#include <libc.h>
#include <stdio.h>

int	**ft_splitted_to_matrix(t_map map)
{
	int	**matrix;
	int	i;
	int	j;

	i = -1;
	matrix = (int **)malloc(map.line_count * sizeof(int *));
	check_malloc(matrix);
	while (++i < map.line_count)
	{
		j = -1;
		matrix[i] = (int *)malloc(sizeof(int) * map.column_count);
		check_malloc(matrix[i]);
		while (++j < map.column_count)
		{
			if (map.map_content[i][j] == map.empty)
				matrix[i][j] = 1;
			else
				matrix[i][j] = 0;
		}
	}
	return (matrix);
}
