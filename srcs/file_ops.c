/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:06:41 by yzeybek           #+#    #+#             */
/*   Updated: 2024/09/03 13:34:45 by yzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../includes/bsq.h"
#include "../includes/errors.h"

char	*fc_alloc(char *content, int total_size, char *buffer, int bytes_read)
{
	int		i;
	char	*new_content;

	new_content = malloc(total_size + bytes_read + 1);
	if (!new_content)
		return (NULL);
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

int	read_fc(int fd, char **content)
{
	char	buffer[BUFFER_SIZE];
	long	bytes_read;
	int		total_size;

	(*content) = NULL;
	total_size = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		(*content) = fc_alloc((*content), total_size, buffer, bytes_read);
		if (!(*content))
			return (0);
		total_size += bytes_read;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read == -1)
		return (0);
	return (1);
}

char	*read_file(const char *filename)
{
	int		fd;
	int		res;
	char	*content;

	if (filename)
	{
		fd = open(filename, O_RDONLY);
		if (fd == -1)
			return (NULL);
	}
	else
		fd = 0;
	res = read_fc(fd, &content);
	if (!res || (filename && close(fd) == -1))
		return (NULL);
	return (content);
}
