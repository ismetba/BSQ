/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:23:34 by yzeybek           #+#    #+#             */
/*   Updated: 2024/09/01 12:38:18 by yzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_ops.h"
#include "../includes/split_content.h"
#include <libc.h>
#include <unistd.h>

void	free_map(struct s_map *map)
{
	int	i;

	i = 0;
	while (i <= (*map).line_count)
	{
		free((*map).map_content[i]);
		i++;
	}
	free((*map).map_content);
}

void	process_map(char *file_name)
{
	char			*content;
	struct s_map	map;

	content = read_file(file_name);
	if (!split_content(content, &map))
	{
		write(2, "map error\n", 11);
		return ;
	}
	free(content);
	// TODO: PROCESS WILL CONTINUE FROM CONVERTING MAP_CONTENT TO MATRIX
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
