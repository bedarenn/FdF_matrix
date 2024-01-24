/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:36:34 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/24 14:21:19 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libwati.h>

static int	print_line_condition(t_coord v, int i, t_coord *i_coord)
{
	if (i_coord->x < i / wati_abs(v.y))
	{
		i_coord->x++;
		if (i_coord->y < i / wati_abs(v.x))
			i_coord->y++;
		return (1);
	}
	else if (i_coord->y < i / wati_abs(v.x))
	{
		i_coord->y++;
		return (1);
	}
	return (0);
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

static void	print_line_loop(t_pixel p1, t_pixel p2, t_coord v, t_data *data)
{
	int		i;
	t_coord	i_coord;
	int		lenght;

	lenght = wati_abs(v.x) * wati_abs(v.y);
	i_coord = set_coord(0, 0, 0);
	i = 0;
	put_pxl(data, p1.coord.x + (i_coord.x * wati_sig(v.x)),
		p1.coord.y + (i_coord.y * wati_sig(v.y)),
		get_average_color(p1.color->content,
			p2.color->content, 0).h);
	while (i < lenght)
	{
		if (print_line_condition(v, i, &i_coord))
			put_pxl(data, p1.coord.x + (i_coord.x * wati_sig(v.x)),
				p1.coord.y + (i_coord.y * wati_sig(v.y)),
				get_average_color(p1.color->content,
					p2.color->content, (float)i / lenght).h);
		i++;
	}
}

void	print_line(t_point point1, t_point point2, t_data *data)
{
	t_coord	v;

	v = set_coord(point2.pixel.coord.x - point1.pixel.coord.x,
			point2.pixel.coord.y - point1.pixel.coord.y, 0);
	v = set_coord(point2.pixel.coord.x - point1.pixel.coord.x,
			point2.pixel.coord.y - point1.pixel.coord.y, 0);
	v = set_coord(v.x + (1 * wati_sig(v.x)), v.y + (1 * wati_sig(v.y)), 0);
	print_line_loop(point1.pixel, point2.pixel, v, data);
}

void	put_pxl(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_SIZE_X && y >= 0 && y < WIN_SIZE_Y)
	{
		dst = data->addr
			+ (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
