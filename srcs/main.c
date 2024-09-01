/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:23:34 by yzeybek           #+#    #+#             */
/*   Updated: 2024/09/01 18:06:41 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_ops.h"
#include "../includes/matrices.h"
#include <libc.h>
#include <unistd.h>

void	free_map(struct s_map *map)
{
	int	i;

	i = 0;
	while (i < (*map).line_count)
	{
		free((*map).map_content[i]);
		i++;
	}
	free((*map).map_content);
}

void	process_map(char *file_name)
{
	char			*content;
	int				**matrix;
	int				**solution_matrix;
	struct s_map	map;
	int				i;
	int				j;

	content = read_file(file_name);
	if (!split_content(content, &map))
	{
		write(2, "map error\n", 11);
		return ;
	}
	free(content);
	i = 0;
	while (map.line_count > i)
	{
		printf("%s\n", map.map_content[i]);
		i++;
	}
	matrix = ft_splitted_to_matrix(map);
	i = 0;
	while (map.line_count > i)
	{
		j = 0;
		while (j < map.column_count)
		{
			printf("%d ", matrix[i][j++]);
		}
		printf("\n");
		i++;
	}
	solution_matrix = ft_solution_matrix(matrix, map.line_count,
			map.column_count);
	i = 0;
	printf("\n\n");
	while (map.line_count > i)
	{
		j = 0;
		while (j < map.column_count)
		{
			printf("%d ", solution_matrix[i][j++]);
		}
		printf("\n");
		i++;
	}
	free_map(&map);
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc > 1)
	{
		i = 0;
		while (++i < argc)
			process_map(argv[i]);
	}
	else
	{
		process_map(NULL);
	}
}
