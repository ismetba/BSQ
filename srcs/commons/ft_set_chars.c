/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_chars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzeybek <yzeybek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:30:52 by yzeybek           #+#    #+#             */
/*   Updated: 2024/09/04 09:32:51 by yzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	ft_set_chars(char empty, char obstacle, char full, t_map *map)
{
	(*map).empty = empty;
	(*map).obstacle = obstacle;
	(*map).full = full;
}
