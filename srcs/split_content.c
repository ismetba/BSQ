/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:50:12 by yzeybek           #+#    #+#             */
/*   Updated: 2024/08/31 15:19:01 by yzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/bsq.h"
#include "../includes/errors.h"
#include "../includes/validate.h"

int	ft_atoi_light(char *first_line, struct s_map *map)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (first_line[i] >= '0' && first_line[i] <= '9')
	{
		res = res * 10 + first_line[i] - '0';
		i++;
	}
	(*map).line_count = res;
	return (i);
}

int	get_chars(char *first_line, int i, struct s_map *map)
{
	if (first_line[i] <= 126 && first_line[i] >= 32
		&& first_line[i + 1] <= 126 && first_line[i + 1] >= 32
		&& first_line[i + 2] <= 126 && first_line[i + 2] >= 32)
	{
		(*map).empty = first_line[i];
		(*map).obstacle = first_line[i + 1];
		(*map).full = first_line[i + 2];
		return (1);
	}
	else
		return (0);
}

int	split_first(char *content, struct s_map *map, int i)
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
	nbr_length = ft_atoi_light(first_line, map);
	if (!nbr_length)
		return (0);
	if (!get_chars(first_line, nbr_length, map))
		return (0);
	return (1);
}

int	split_content(char *content, struct s_map *map)
{
	int	i;

	i = 0;
	while (content[i] != '\n')
		i++;
	if (!check_max_length(i))
		return (0);
	if (!split_first(content, map, i))
		return (0);
//FUNCTION WILL KEEP SPLITING AND CHEKING OTHER LINES OF MAP
	return (1);
}
