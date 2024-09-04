/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:06:41 by yzeybek           #+#    #+#             */
/*   Updated: 2024/09/04 11:15:00 by yzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../includes/bsq.h"

char	*fc_alloc(char *content, int total_size, char *buffer, int bytes_read)
{
	int		i;
	char	*new_content;

	new_content = malloc(total_size + bytes_read + 1);
	if (!new_content)
	{
		free(content);
		return (NULL);
	}
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
	int			total_size;
	char		*content;

	content = NULL;
	total_size = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		content = fc_alloc(content, total_size, buffer, bytes_read);
		if (!content)
			return (NULL);
		total_size += bytes_read;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read == -1)
	{
		free(content);
		return (NULL);
	}
	return (content);
}

int	read_file(const char *filename, char **content)
{
	int		fd;

	(*content) = NULL;
	if (filename)
	{
		fd = open(filename, O_RDONLY);
		if (fd == -1)
			return (0);
	}
	else
		fd = 0;
	(*content) = read_fc(fd);
	if (!(*content) || (filename && close(fd) == -1))
		return (0);
	return (1);
}
