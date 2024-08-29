/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:06:41 by yzeybek           #+#    #+#             */
/*   Updated: 2024/08/29 17:38:01 by yzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../includes/errors.h"

char	**allocate_map(char *fc, int line)
{
	char	**map;
	int		i;
	int		j;
	int		start;
	int		current;
	int		length;

	map = malloc(sizeof(char *) * (line + 1));
	check_malloc(map);
	i = 0;
	start = 0;
	current = 0;
	while (fc[i])
	{
		if (fc[i] == '\n')
		{
			length = i - start;
			map[current] = malloc(length + 1);
			check_malloc(map[current]);
			j = 0;
			while (j < length)
			{
				map[current][j] = fc[start + j];
				j++;
			}
			map[current][length] = '\0';
			current++;
			start = i + 1;
		}
		i++;
	}
	map[line] = NULL;
	return (map);
}

int	count_line(char *fc)
{
	int	i;
	int	line;

	i = 0;
	line = 0;
	while (fc[i])
	{
		if (fc[i] == '\n')
			line++;
		i++;
	}
	return (line);
}

char	*read_fc(int fd, int *total)
{
	char	array[BUFFER_SIZE + 1];
	char	*fc = NULL;
	int		bytes;
	int		i;
	char	*temp;

	while ((bytes = read(fd, array, BUFFER_SIZE)) > 0)
	{
		temp = malloc(*total + bytes + 1);
		check_malloc(temp);
		i = -1;
		while (i++ < *total)
			temp[i] = fc[i];
		i = -1;
		while (i++ < bytes)
			temp[*total + i] = array[i];
		temp[*total + bytes] = '\0';
		free(fc);
		fc = temp;
		*total += bytes;
	}
	if (bytes == -1)
		exit(EXIT_FAILURE);
	return (fc);
}

char	**read_file(char *file_name)
{
	int		fd;
	int		total;
	char	*fc;
	int		line;
	char	**map;

	fd = open(file_name, O_RDONLY);
	check_open(fd);
	fc = read_fc(fd, &total);
	line = count_line(fc);
	map = allocate_map(fc, line);
	free(fc);
	close(fd);
	return (map);
}
