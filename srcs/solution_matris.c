/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_matris.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:44:05 by ibayandu          #+#    #+#             */
/*   Updated: 2024/09/01 11:58:05 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	**ft_solution_matris(int **original_matris, unsigned long row,
		unsigned long column)
{
	int	**solution_matris;
	int	i;

	i = 0;
	solution_matris = (int **)malloc(row * sizeof(int *));
	while (i < row)
	{
		solution_matris[i++] = (int *)malloc(column * sizeof(int));
	}
	i = 0;
	return (0);
}
