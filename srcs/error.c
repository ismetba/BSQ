/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:05:14 by yzeybek           #+#    #+#             */
/*   Updated: 2024/08/29 17:36:04 by yzeybek          ###   ########.fr       */
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

void	check_open(int fd)
{
	if (fd == -1)
	{
		write(2, "Error opening file !\n", 22);
		exit(EXIT_FAILURE);
	}
}
