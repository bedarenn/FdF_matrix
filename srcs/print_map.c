/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:38:13 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 18:25:51 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	print_map(t_point **map, t_coord size, t_zoom zoom, t_data *data)
{
	t_coord	i;

	i.y = 0;
	while (i.y < size.y)
	{
		i.x = 0;
		while (i.x < size.x)
		{
			if (i.x > 0)
				print_line(map[i.y][i.x], map[i.y][i.x - 1], data, zoom);
			if (i.y > 0)
				print_line(map[i.y][i.x], map[i.y - 1][i.x], data, zoom);
			i.x++;
		}
		i.y++;
	}
}

void	clear_data(t_data *data)
{
	t_coord	i;

	i.y = 0;
	while (i.y < WIN_SIZE_Y)
	{
		i.x = 0;
		while (i.x < WIN_SIZE_X)
		{
			put_pxl(data, i.x, i.y, 0xFF000000);
			i.x++;
		}
		i.y++;
	}
}
