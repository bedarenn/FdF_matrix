/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_assessor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:21:10 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/04 21:24:34 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf_struct.h>
#include <stdlib.h>

t_coord	set_coord(int x, int y, int z)
{
	t_coord	coord;

	coord.x = x;
	coord.y = y;
	coord.z = z;
	return (coord);
}

t_color	set_color(unsigned char t, unsigned char r,
	unsigned char g, unsigned char b)
{
	t_color			color;
	unsigned char	*str;

	color.t = t;
	color.r = r;
	color.g = g;
	color.b = b;
	str = (unsigned char *)&color.h;
	str[3] = color.t;
	str[2] = color.r;
	str[1] = color.g;
	str[0] = color.b;
	return (color);
}

t_color	set_color_hex(unsigned int h)
{
	t_color			color;
	unsigned char	*str;

	str = (unsigned char *)&h;
	color.h = h;
	color.t = str[3];
	color.r = str[2];
	color.g = str[1];
	color.b = str[0];
	return (color);
}

t_color	*add_point_color(t_point point, t_color new)
{
	t_list	*list;
	t_color	*color;

	color = malloc(sizeof(t_color));
	if (color)
		return (NULL);
	*color = new;
	list = ft_lstnew(color);
	if (!list)
	{
		free(color);
		return (NULL);
	}
	if (!point.color)
	{
		list->next = list;
		point.color = list;
	}
	else
	{
		list->next = point.color->next;
		point.color->next = list;
	}
	return (color);
}

