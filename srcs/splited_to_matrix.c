/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splited_to_matris.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:18:40 by ibayandu          #+#    #+#             */
/*   Updated: 2024/09/01 11:56:33 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"
#include <libc.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i++])
		;
	return (i);
}

int	**ft_splitted_to_matris(t_map map)
{
	int	**matris;
	int	i;
	int	column;

	i = 0;
	column = ft_strlen(map.map_content[1]);
	matris = (int **)malloc(map.line_count * sizeof(int *));
	while (i < map.line_count)
		matris[i++] = (int *)malloc(column * sizeof(int));
	while (map.line_count--)
	{
		column = ft_strlen(map.map_content[1]);
		while (column--)
		{
			if (map.map_content[map.line_count][column] == map.empty)
				matris[map.line_count][column] = 1;
			else if (map.map_content[map.line_count][column] == map.obstacle)
				matris[map.line_count][column] = 0;
		}
	}
	return (matris);
}
