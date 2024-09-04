/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:23:34 by yzeybek           #+#    #+#             */
/*   Updated: 2024/09/04 11:15:35 by yzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_ops.h"
#include "../includes/matrix_ops.h"

void	free_matrix(int **matrix, int line)
{
	int	i;

	i = 0;
	while (i < line)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	ft_error(char *content, int **matrix, int line)
{
	write(2, "map error\n", 10);
	if (content)
		free(content);
	if (line != -1)
		free_matrix(matrix, line);
}

void	process_map(char *file_name)
{
	char				*content;
	struct s_solution	solution;
	struct s_map		map;
	int					line;

	if (!read_file(file_name, &content))
		return (ft_error(content, map.map_content, -1));
	line = split_content(content, &map);
	if (line)
		return (ft_error(content, map.map_content, line));
	solution = ft_solution_matrix(map.map_content, map.line_count,
			map.column_count);
	if (solution.size == -1)
	{
		free_matrix(map.map_content, map.line_count);
		return (ft_error(content, solution.sol_matrix, solution.x));
	}
	free(content);
	free_matrix(map.map_content, map.line_count);
	print_solution(solution, map);
	free_matrix(solution.sol_matrix, map.line_count);
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc > 1)
	{
		i = 0;
		while (++i < argc)
		{
			process_map(argv[i]);
			if (i != argc -1)
				write(1, "\n", 1);
		}
	}
	else
		process_map(NULL);
	return (0);
}
