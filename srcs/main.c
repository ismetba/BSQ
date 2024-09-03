/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:23:34 by yzeybek           #+#    #+#             */
/*   Updated: 2024/09/03 15:25:35 by yzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_ops.h"
#include "../includes/matrix_ops.h"
#include <stdio.h>

void	free_matrix(int **matrix, int line)
{
	int	i;

	i = -1;
	if (line != -1)
		while (++i < line)
			free(matrix[i]);
	else
		while (matrix[++i])
			free(matrix[i]);
	free(matrix);
}

void	ft_error(char *content, int **matrix, int line)
{
	write(2, "map error", 9);
	free_matrix(matrix, line);
	free(content);
}

void	process_map(char *file_name)
{
	char				*content;
	struct s_solution	solution;
	struct s_map		map;
	int					line;

	content = read_file(file_name, &content);
	if (!content)
		return (ft_error(content, map.map_content, 0));
	line = split_content(content, &map);
	if (line)
		return (ft_error(content, map.map_content, line));
	free(content);
	solution = ft_solution_matrix(map.map_content, map.line_count,
			map.column_count);
	if (!(solution.sol_matrix))
	{
		free_matrix(solution.sol_matrix, -1);
		return (ft_error(content, map.map_content, line));
	}
	print_solution(solution, map);
	free_matrix(map.map_content, map.line_count);
	free_matrix(solution.sol_matrix, map.line_count);
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			process_map(argv[i]);
			if (i != argc - 1)
				write(1, "\n", 1);
			i++;
		}
	}
	else
	{
		process_map(NULL);
	}
	return (0);
}
