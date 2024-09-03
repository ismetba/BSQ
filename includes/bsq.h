/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:27:55 by yzeybek           #+#    #+#             */
/*   Updated: 2024/09/03 20:36:38 by yzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 100000

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
