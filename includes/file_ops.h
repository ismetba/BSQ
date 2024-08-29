/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ops.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:11:53 by yzeybek           #+#    #+#             */
/*   Updated: 2024/08/29 21:10:35 by yzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_OPS_H
# define FILE_OPS_H

# define BUFFER_SIZE 1024

char	**read_file(char *file_name);
char	*read_fc(int fd, int *total);
int		count_line(char *fc);
char	**allocate_map(char *fc, int line);

#endif