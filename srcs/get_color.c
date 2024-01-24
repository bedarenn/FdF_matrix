/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:52:21 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/24 11:16:07 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_color	get_color(char *str)
{
	t_color	color;

	if (!wati_strncmp(str, ",0x", 3))
		color = set_color_hex(wati_atoi_base(wati_strlower(str + 3),
					"0123456789abcdef", 16));
	else
		color = set_color_hex(0x00808080);
	return (color);
}

void	change_color(t_point **map, t_coord size)
{
	t_coord	i;

	i.y = 0;
	while (i.y < size.y)
	{
		i.x = 0;
		while (i.x < size.x)
		{
			if (!map[i.y][i.x].pixel.color->next)
				map[i.y][i.x].pixel.color = map[i.y][i.x].color;
			else
				map[i.y][i.x].pixel.color = map[i.y][i.x].pixel.color->next;
			i.x++;
		}
		i.y++;
	}
}
