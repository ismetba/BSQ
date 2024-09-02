/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:23:34 by yzeybek           #+#    #+#             */
/*   Updated: 2024/09/02 13:51:43 by yzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_ops.h"
#include "../includes/matrices.h"
#include <libc.h>
#include <unistd.h>

void	free_map(t_map *map)
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
	char				*content;
	struct s_solution	solution;
	struct s_map		map;
	int					i;
	int					j;

	content = read_file(file_name);
	if (!split_content(content, &map))
	{
		write(2, "map error\n", 11);
		free_map(&map);
		free(content);
		return ;
	}
	free(content);
	i = 0;
	while (i < map.line_count)
	{
		j = 0;
		while (j < map.column_count)
		{
			printf("%i", map.map_content[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	solution = ft_solution_matrix(map.map_content, map.line_count,
			map.column_count);
	i = 0;
	printf("\n");
	while (map.line_count > i)
	{
		j = 0;
		while (j < map.column_count)
		{
			printf("%d ", solution.sol_matrix[i][j++]);
		}
		printf("\n");
		i++;
	}
	printf("%i\n", solution.size);
	printf("%i\n", solution.y);
	printf("%i\n", solution.x);
	free_map(&map);
}

int	main(int argc, char *argv[])
{
	(void)argc;
	process_map(argv[1]);
	return (0);
}
