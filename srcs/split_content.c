/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:50:12 by yzeybek           #+#    #+#             */
/*   Updated: 2024/08/31 17:05:56 by yzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/bsq.h"
#include "../includes/errors.h"

int ft_atoi_light(char *first_line, struct s_map *map, int length)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (first_line[i] >= '0' && first_line[i] <= '9'
		&& res <= 2147483647 && i < length - 3)
	{
		res = res * 10 + first_line[i] - '0';
		i++;
	}
	(*map).line_count = res;
	return (i);
}

int split_first(char *content, struct s_map *map, int i)
{
	char *first_line;
	int j;
	int nbr_length;

	first_line = (char *)malloc(sizeof(char) * i);
	check_malloc(first_line);
	j = -1;
	while (++j < i)
		first_line[j] = content[j];
	first_line[j] = '\0';
	nbr_length = ft_atoi_light(first_line, map, j);
	if (!nbr_length)
		return (0);
	if ((first_line[nbr_length] < 127 && first_line[nbr_length] > 31)
		&& (first_line[nbr_length + 1] < 127 && first_line[nbr_length + 1] > 31)
		&& (first_line[nbr_length + 2] < 127 && first_line[nbr_length + 2] > 31)
		&& j == nbr_length + 3)
	{
		(*map).empty = first_line[nbr_length];
		(*map).obstacle = first_line[nbr_length + 1];
		(*map).full = first_line[nbr_length + 2];
	}
	else
		return (0);
	return (1);
}

char *get_line(char *content, struct s_map *map, int index)
{
	int i;
	char *res;

	i = 0;
	while (content[i] != '\n')
		i++;
	res = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while ((*content) != '\n')
	{
		if (index != 0 && (*content) != (*map).empty
			&& (*content) != (*map).obstacle)
			return (NULL);
		res[i] = (*content);
		i++;
		content++;
	}
	res[i] = '\0';
	return (res);
}

int split_lines(char *content, struct s_map *map)
{
	int i;
	int j;
	int line_length;
	char **map_data;

	i = -1;
	map_data = (char **)malloc(sizeof(char *) * ((*map).line_count + 1));
	line_length = 0;
	while (++i <= (*map).line_count)
	{
		j = 0;
		while (content[j] != '\n' && content[j])
			j++;
		if (i == 1)
			while (content[line_length] != '\n')
				line_length++;
		if ((i > 1 && j != line_length))
			return (0);
		map_data[i] = get_line(content, map, i);
		if (map_data[i] == NULL)
			return (0);
		content += j + 1;
	}
	(*map).map_content = map_data;
	return (1);
}

int split_content(char *content, struct s_map *map)
{
	int i;

	i = 0;
	while (content[i] != '\n')
		i++;
	if (i > 14)
		return (0);
	if (!split_first(content, map, i))
		return (0);
	if ((*map).empty == (*map).full
		|| (*map).empty == (*map).obstacle
		|| (*map).full == (*map).obstacle)
		return (0);
	if (!split_lines(content, map))
		return (0);
	return (1);
}
