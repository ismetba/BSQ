/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:06:41 by yzeybek           #+#    #+#             */
/*   Updated: 2024/08/29 21:18:14 by yzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../includes/errors.h"

char	**allocate_map(char *file_content, int map_size, int start, int line)
{
	char	**map;
	int		i;
	int		line_length;

	map = malloc((map_size + 1) * sizeof(char *));
	check_malloc(map);
	i = -1;
	while (file_content[++i])
	{
		if (file_content[i] == '\n')
		{
			line_length = i - start;
			map[line] = malloc(line_length + 1);
			check_malloc(map[line]);
			start = -1;
			while (++start < line_length)
				map[line][start] = file_content[i - line_length + start];
			map[line++][line_length] = '\0';
			start = i + 1;
		}
	}
	map[map_size] = NULL;
	return (map);
}

int	count_line(char *file_content)
{
	int	i;
	int	map_size;

	i = 0;
	map_size = 0;
	while (file_content[i])
	{
		if (file_content[i] == '\n')
			map_size++;
		i++;
	}
	return (map_size);
}

char	*read_fc(int fd, int *total_size, int i)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*file_content;
	int		bytes_read;
	char	*temp;

	file_content = NULL;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	check_bytes(bytes_read);
	while (bytes_read > 0)
	{
		temp = malloc(*total_size + bytes_read + 1);
		check_malloc(temp);
		i = -1;
		while (++i < *total_size)
			temp[i] = file_content[i];
		i = -1;
		while (++i < bytes_read)
			temp[*total_size + i] = buffer[i];
		temp[*total_size + bytes_read] = '\0';
		free(file_content);
		file_content = temp;
		*total_size += bytes_read;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (file_content);
}

char	**read_file(char *file_name)
{
	int		fd;
	int		total_size;
	char	*file_content;
	int		map_size;
	char	**map;

	total_size = 0;
	fd = open(file_name, O_RDONLY);
	check_open(fd);
	file_content = read_fc(fd, &total_size, 0);
	map_size = count_line(file_content);
	map = allocate_map(file_content, map_size, 0, 0);
	free(file_content);
	close(fd);
	return (map);
}
