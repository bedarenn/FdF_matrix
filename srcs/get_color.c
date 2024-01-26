/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:52:21 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/26 13:52:30 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_color	get_color(char *str)
{
	t_color	color;

	if (!wati_strncmp(str, ",0x", 3))
		color = set_color_hex(0xff000000
				+ wati_atoi_base(wati_strlower(str + 3),
					"0123456789abcdef", 16));
	else
		color = set_color_hex(0xff808080);
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

t_color	get_average_color(t_color *color1, t_color *color2,
	float percent)
{
	t_color			color;
	float			rpercent;

	rpercent = 1 - percent;
	color.t = color1->t * rpercent + color2->t * percent;
	color.r = color1->r * rpercent + color2->r * percent;
	color.g = color1->g * rpercent + color2->g * percent;
	color.b = color1->b * rpercent + color2->b * percent;
	color = set_color(color.t, color.r, color.g, color.b);
	return (color);
}
