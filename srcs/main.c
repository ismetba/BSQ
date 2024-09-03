/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:23:34 by yzeybek           #+#    #+#             */
/*   Updated: 2024/09/03 16:19:40 by yzeybek          ###   ########.fr       */
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

void	process_map(char *file_name)
{
	char				*content;
	struct s_solution	solution;
	struct s_map		map;
	int					line;

	content = read_file(file_name);
	line = split_content(content, &map);
	if (line)
	{
		write(2, "map error\n", 11);
		free_matrix(map.map_content ,line);
		free(content);
		return ;
	}
	free(content);
	solution = ft_solution_matrix(map.map_content, map.line_count,
			map.column_count);
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
