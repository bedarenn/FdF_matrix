/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:33:44 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/25 09:03:27 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

char	*skip_nb(char *str)
{
	while (wati_isspace(*str))
		str++;
	if (*str == '-')
		str++;
	else if (*str == '+')
		str++;
	while (wati_isdigit(*str))
		str++;
	return (str);
}

t_color	set_color_height(int height)
{
	t_color	color;
	float	height_color;

	height_color = height - HEIGHT_ABYSS;
	if (height < HEIGHT_ABYSS - (HEIGHT_MOUNTAIN - HEIGHT_ABYSS))
		color = set_color(255, 0, 0, 0);
	else if (height <= HEIGHT_ABYSS)
		color = set_color(255, 0, 0,
				255 - (255 * (height_color)
					/ -(HEIGHT_MOUNTAIN - HEIGHT_ABYSS)));
	else if (height < HEIGHT_ABYSS + ((HEIGHT_MOUNTAIN - HEIGHT_ABYSS) / 2))
		color = set_color(255, 0, 64 + (192 * (height_color
						/ ((HEIGHT_MOUNTAIN - HEIGHT_ABYSS) / 2))), 0);
	else if (height <= HEIGHT_MOUNTAIN)
		color = set_color(255, 255 * ((height_color
						- ((HEIGHT_MOUNTAIN - HEIGHT_ABYSS) / 2))
					/ ((HEIGHT_MOUNTAIN - HEIGHT_ABYSS) / 2)),
				255, 255 * ((height_color
						- ((HEIGHT_MOUNTAIN - HEIGHT_ABYSS) / 2))
					/ ((HEIGHT_MOUNTAIN - HEIGHT_ABYSS) / 2)));
	else
		color = set_color(255, 255, 255, 255);
	return (color);
}
