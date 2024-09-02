/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:22:12 by yzeybek           #+#    #+#             */
/*   Updated: 2024/09/02 15:47:25 by yzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICES_H
# define MATRICES_H

# include "bsq.h"

int			split_content(char *content, struct s_map *map);
int			**ft_splitted_to_matrix(t_map map);
t_solution	ft_solution_matrix(int **original_matrix, int row, int column);
void		print_solution(t_solution solution, t_map map);

#endif