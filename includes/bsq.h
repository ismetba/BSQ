/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:27:55 by yzeybek           #+#    #+#             */
/*   Updated: 2024/08/31 13:28:31 by yzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define BUFFER_SIZE 1024

typedef struct s_map
{
	char	empty;
	char	obstacle;
	char	full;
	int		line_count;
	char	**map;

}	t_map;

#endif