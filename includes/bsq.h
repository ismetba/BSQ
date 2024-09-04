/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:27:55 by yzeybek           #+#    #+#             */
/*   Updated: 2024/09/04 12:33:29 by ibayandu         ###   ########.fr       */
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
