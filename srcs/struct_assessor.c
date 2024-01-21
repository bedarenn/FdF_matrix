/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_assessor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:21:10 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 18:05:46 by bedarenn         ###   ########.fr       */
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

t_trigo	set_trigo(double x, double y, double z)
{
	t_trigo	trigo;

	trigo.x = x;
	trigo.y = y;
	trigo.z = z;
	return (trigo);
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

t_list	*lstnew_color(t_color new)
{
	t_list	*list;
	t_color	*color;

	color = malloc(sizeof(t_color));
	if (!color)
		return (NULL);
	*color = new;
	list = wati_lstnew(color);
	if (!list)
	{
		free(color);
		return (NULL);
	}
	return (list);
}
