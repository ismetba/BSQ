/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ops.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:22:12 by yzeybek           #+#    #+#             */
/*   Updated: 2024/09/04 11:10:29 by yzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_OPS_H
# define MATRIX_OPS_H

# include "bsq.h"

int			split_content(char *content, t_map *map);
t_solution	ft_solution_matrix(int **original_matrix, int row, int column);
void		print_solution(t_solution solution, t_map map);

#endif