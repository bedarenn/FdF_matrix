/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:49:54 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 18:55:32 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	mutiply_map(t_point **map, t_coord size, int **matrix)
{
	t_coord	i;

	i.y = 0;
	while (i.y < size.y)
	{
		i.x = 0;
		while (i.x < size.x)
		{
			map[i.y][i.x].coord = multiply_matrix(map[i.y][i.x].coord, matrix);
			i.x++;
		}
		i.y++;
	}
}

t_coord	multiply_matrix(t_coord coord, int **matrix)
{
	(void)matrix;
	return (coord);
}
