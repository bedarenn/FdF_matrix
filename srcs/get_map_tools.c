/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:59:37 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/24 10:36:18 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf_struct.h>
#include <stdlib.h>

void	free_map(t_point **map, t_coord size)
{
	t_coord	i;

	i.y = 0;
	while (i.y < size.y)
	{
		i.x = 0;
		while (i.x < size.x)
		{
			wati_lstclear(&map[i.y][i.x].color, free);
			i.x++;
		}
		free(map[i.y]);
		i.y++;
	}
	free(map);
}
