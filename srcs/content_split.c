/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:50:12 by yzeybek           #+#    #+#             */
/*   Updated: 2024/09/02 16:26:52 by yzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"
#include "../includes/errors.h"
#include "../includes/commons.h"

int	ft_atoi_light(char *first_line, struct s_map *map, int length)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (first_line[i] >= '0' && first_line[i] <= '9' && res <= 2147483647
		&& i < length - 3)
	{
		res = res * 10 + first_line[i] - '0';
		i++;
	}
	(*map).line_count = res;
	return (i);
}

int	split_first(char *content, t_map *map, int i)
{
	char	*first_line;
	int		j;
	int		nbr_length;

	first_line = (char *)malloc(sizeof(char) * i);
	check_malloc(first_line);
	j = -1;
	while (++j < i)
		first_line[j] = content[j];
	first_line[j] = '\0';
	nbr_length = ft_atoi_light(first_line, map, j);
	if (!nbr_length || (*map).line_count == 0)
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

int	*get_line(char *content, t_map *map)
{
	int	i;
	int	*res;

	res = (int *)malloc(sizeof(int) * (*map).column_count);
	check_malloc(res);
	i = 0;
	while ((*content) != '\n')
	{
		if ((*content) == (*map).empty)
			res[i] = 1;
		else if ((*content) == (*map).obstacle)
			res[i] = 0;
		else
			return (NULL);
		i++;
		content++;
	}
	return (res);
}

int	split_lines(char *content, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	(*map).map_content = (int **)malloc(sizeof(int *) * ((*map).line_count));
	check_malloc((*map).map_content);
	j = ft_strlen_n(content);
	while (++i < (*map).line_count)
	{
		content += j + 1;
		j = 0;
		while (content[j] != '\n' && content[j])
			j++;
		if (i == 0)
			(*map).column_count = j;
		if (j != (*map).column_count)
			return (i);
		(*map).map_content[i] = get_line(content, map);
		if (!((*map).map_content[i]) || (i == (*map).line_count - 1
				&& content[j + 1] != '\0'))
			return (i + 1);
	}
	return (0);
}

int	split_content(char *content, t_map *map)
{
	int	i;

	i = ft_strlen_n(content);
	if (i > 14)
		return (0);
	if (!split_first(content, map, i))
		return (1);
	if ((*map).empty == (*map).full || (*map).empty == (*map).obstacle
		|| (*map).full == (*map).obstacle)
		return (1);
	return (split_lines(content, map));
}
