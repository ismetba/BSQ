/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splited_to_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:18:40 by ibayandu          #+#    #+#             */
/*   Updated: 2024/09/01 14:03:30 by yzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"
#include "../includes/commons.h"
#include <libc.h>


int	**ft_splitted_to_matrix(t_map map)
{
	int	**matrix;
	int	i;
	int	column;

	i = 0;
	column = ft_strlen(map.map_content[1]);
	matrix = (int **)malloc(map.line_count * sizeof(int *));
	while (i < map.line_count)
		matrix[i++] = (int *)malloc(column * sizeof(int));
	while (map.line_count--)
	{
		column = ft_strlen(map.map_content[1]);
		while (column--)
		{
			if (map.map_content[map.line_count][column] == map.empty)
				matrix[map.line_count][column] = 1;
			else if (map.map_content[map.line_count][column] == map.obstacle)
				matrix[map.line_count][column] = 0;
		}
	}
	return (matrix);
}
