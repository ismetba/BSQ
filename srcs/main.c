/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:23:34 by yzeybek           #+#    #+#             */
/*   Updated: 2024/08/31 15:17:10 by yzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_ops.h"
#include "../includes/split_content.h"
#include "../includes/bsq.h"
#include <unistd.h>

void	process_map(char *file_name)
{
	char			*content;
	struct s_map	map;

	content = read_file(file_name);
	if (!split_content(content, &map))
	{
		write(1, "map error\n", 11);
		return ;
	}
}

int	main(int argc, char *argv[])
{
	int		i;

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
