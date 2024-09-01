/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:27:55 by yzeybek           #+#    #+#             */
/*   Updated: 2024/09/01 15:16:07 by ibayandu         ###   ########.fr       */
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
	char	**map_content;
}	t_map;

#endif
