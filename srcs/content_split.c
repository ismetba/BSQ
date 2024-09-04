/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:50:12 by yzeybek           #+#    #+#             */
/*   Updated: 2024/09/04 13:33:24 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	first_line = (char *)malloc(sizeof(char) * (i + 1));
	if (!first_line)
		return (0);
	j = -1;
	while (++j < i)
		first_line[j] = content[j];
	first_line[j] = '\0';
	nbr_length = ft_atoi_light(first_line, map, j);
	if ((!nbr_length || (*map).line_count == 0) || j != nbr_length + 3
		|| !ft_is_printable(first_line[nbr_length],
			first_line[nbr_length + 1], first_line[nbr_length + 2]))
	{
		free(first_line);
		return (0);
	}
	else
		ft_set_chars(first_line[nbr_length], first_line[nbr_length + 1],
			first_line[nbr_length + 2], map);
	free(first_line);
	return (1);
}

int	get_line(char *content, t_map *map, int **dest)
{
	int	i;

	(*dest) = (int *)malloc(sizeof(int) * (*map).column_count);
	if (!(*dest))
	{
		(*dest) = NULL;
		return (-1);
	}
	i = 0;
	while ((*content) != '\n')
	{
		if ((*content) == (*map).empty)
			(*dest)[i] = 1;
		else if ((*content) == (*map).obstacle)
			(*dest)[i] = 0;
		else
			return (0);
		i++;
		content++;
	}
	return (1);
}

int	split_lines(char *content, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	(*map).map_content = (int **)malloc(sizeof(int *) * ((*map).line_count));
	if (!((*map).map_content))
		return (-1);
	j = ft_strlen_n(content);
	while (++i < (*map).line_count)
	{
		content += j + 1;
		j = ft_strlen_n(content);
		if (j == 0)
			return (-1);
		if (i == 0)
			(*map).column_count = j;
		if (j != (*map).column_count
			|| (i == (*map).line_count - 1 && content[j + 1] != '\0'))
			return (i);
		if (!get_line(content, map, &((*map).map_content[i])))
			return (i + 1);
		else if (!((*map).map_content[i]))
			return (i);
	}
	return (0);
}

int	split_content(char *content, t_map *map)
{
	int	i;

	i = 0;
	while (content[i])
		i++;
	if (content[i - 1] != '\n')
		return (-1);
	i = 0;
	while (content[i] != '\n')
		i++;
	if (i > 14)
		return (-1);
	if (!split_first(content, map, i))
		return (-1);
	if ((*map).empty == (*map).full || (*map).empty == (*map).obstacle
		|| (*map).full == (*map).obstacle)
		return (-1);
	return (split_lines(content, map));
}
