/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:05:14 by yzeybek           #+#    #+#             */
/*   Updated: 2024/08/31 11:33:46 by yzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	check_malloc(void *size)
{
	if (size == NULL)
	{
		write(2, "Error allocating memory !\n", 27);
		exit(EXIT_FAILURE);
	}
}

void	check_file(int res)
{
	if (res == -1)
	{
		write(2, "Error opening/closing file !\n", 30);
		exit(EXIT_FAILURE);
	}
}

void	check_bytes(int bytes_read, char **content)
{
	if (bytes_read == -1)
	{
		write(2, "Error reading bytes !\n", 23);
		free(*content);
		exit(EXIT_FAILURE);
	}
}
