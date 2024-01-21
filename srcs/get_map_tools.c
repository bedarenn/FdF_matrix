/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:59:37 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 17:11:23 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf_struct.h>
#include <stdlib.h>

void	print_point(t_point point)
{
	t_color	*color;

	if (!point.color0)
		wati_printf("x : %i | y : %i | z : %i | (nil)\n",
			point.coord.x, point.coord.y, point.coord.z);
	else if (!point.color0->content)
		wati_printf("x : %i | y : %i | z : %i | (null)\n",
			point.coord.x, point.coord.y, point.coord.z);
	else
	{
		color = point.color->content;
		wati_printf("x : %i | y : %i | z : %i | color : %p\n",
			point.coord.x, point.coord.y, point.coord.z, color->h);
	}
}

void	free_map(t_point **map, t_coord size)
{
	t_coord	i;

	i.y = 0;
	while (i.y < size.y)
	{
		i.x = 0;
		while (i.x < size.x)
		{
			wati_lstclear(&map[i.y][i.x].color0, free);
			i.x++;
		}
		free(map[i.y]);
		i.y++;
	}
	free(map);
}
