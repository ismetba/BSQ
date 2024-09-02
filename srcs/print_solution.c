/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:34:58 by yzeybek           #+#    #+#             */
/*   Updated: 2024/09/02 15:49:59 by yzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	print_solution(t_solution solution, t_map map)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map.line_count)
	{
		x = -1;
		while (++x < map.column_count)
		{
			if (x > solution.x - solution.size && x <= solution.x
				&& y > solution.y - solution.size && y <= solution.y)
				write(1, &(map.full), 1);
			else if (solution.sol_matrix[y][x] == 0)
				write(1, &(map.obstacle), 1);
			else
				write(1, &(map.empty), 1);
		}
		write(1, "\n", 1);
	}
}
