/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commons.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 13:26:15 by yzeybek           #+#    #+#             */
/*   Updated: 2024/09/04 11:12:03 by yzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMONS_H
# define COMMONS_H

# include "bsq.h"

int		ft_min(int a, int b, int c);
int		ft_strlen_n(char *str);
int		ft_is_printable(char a, char b, char c);
void	ft_set_chars(char empty, char obstacle, char full, t_map *map);

#endif