/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:19:53 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 18:46:46 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <stdlib.h>

t_point	**get_map(t_list *parts, t_coord size)
{
	t_point	**map;
	t_coord	i;

	map = wati_calloc(sizeof(t_point *), size.y + 1);
	if (!map)
		return (NULL);
	i.y = 0;
	while (parts)
	{
		map[i.y] = get_line(parts->content, i, size);
		if (!*map)
		{
			wati_free_tab(map);
			return (NULL);
		}
		parts = parts->next;
		i.y++;
	}
	return (map);
}

t_point	*get_line(char **part, t_coord i, t_coord size)
{
	t_point	*line;

	line = malloc(sizeof(t_point) * size.x);
	if (!line)
		return (NULL);
	i.x = 0;
	while (*part)
	{
		line[i.x] = get_point(*part, i, size);
		part++;
		i.x++;
	}
	return (line);
}

t_point	get_point(char *str, t_coord i, t_coord size)
{
	t_point	point;

	point.coord = set_coord(i.x - size.x / 2, i.y - size.y / 2, wati_atoi(str));
	point.color0 = NULL;
	wati_lstadd_back(&point.color0, lstnew_color(set_color_hex(0x00ffffff)));
	wati_lstadd_back(&point.color0, lstnew_color(get_color(skip_nb(str))));
	wati_lstadd_back(&point.color0,
		lstnew_color(set_color_height(point.coord.z)));
	point.color = point.color0;
	return (point);
}
