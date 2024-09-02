/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:06:41 by yzeybek           #+#    #+#             */
/*   Updated: 2024/09/02 15:24:16 by yzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/errors.h"
#include "../includes/bsq.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*fc_alloc(char *content, int total_size, char *buffer, int bytes_read)
{
	int		i;
	char	*new_content;

	new_content = malloc(total_size + bytes_read + 1);
	check_malloc(new_content);
	i = -1;
	while (++i < total_size)
		new_content[i] = content[i];
	i = -1;
	while (++i < bytes_read)
		new_content[total_size + i] = buffer[i];
	new_content[total_size + bytes_read] = '\0';
	free(content);
	return (new_content);
}

char	*read_fc(int fd)
{
	char		buffer[BUFFER_SIZE];
	long		bytes_read;
	char		*content;
	int			total_size;

	content = NULL;
	total_size = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		content = fc_alloc(content, total_size, buffer, bytes_read);
		total_size += bytes_read;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	check_bytes(bytes_read, &content);
	return (content);
}

char	*read_file(const char *filename)
{
	int		fd;
	char	*content;

	if (filename)
	{
		fd = open(filename, O_RDONLY);
		check_file(fd);
	}
	else
		fd = 0;
	content = read_fc(fd);
	if (filename)
		check_file(close(fd));
	return (content);
}
