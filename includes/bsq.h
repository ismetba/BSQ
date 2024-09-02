/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:27:55 by yzeybek           #+#    #+#             */
/*   Updated: 2024/09/02 13:42:52 by yzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define BUFFER_SIZE 42

typedef struct s_map
{
	char	empty;
	char	obstacle;
	char	full;
	int		line_count;
	int		column_count;
	int		**map_content;
}	t_map;

typedef struct s_solution
{
	int	x;
	int	y;
	int	size;
	int	**sol_matrix;

}	t_solution;

#endif
