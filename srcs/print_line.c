/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:36:34 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/07 19:22:24 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>
#include <ft_printf.h>

static int	print_line_condition(t_coord v, int i, t_coord *i_coord)
{
	if (i_coord->x < i / ft_abs(v.y))
	{
		i_coord->x++;
		if (i_coord->y < i / ft_abs(v.x))
			i_coord->y++;
		return (1);
	}
	else if (i_coord->y < i / ft_abs(v.x))
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
	color.t = color1->t * percent + color2->t * rpercent;
	color.r = color1->r * percent + color2->r * rpercent;
	color.g = color1->g * percent + color2->g * rpercent;
	color.b = color1->b * percent + color2->b * rpercent;
	color = set_color(color.t, color.r, color.g, color.b);
	return (color);
}

/*get_average_color(p1.color->content, p2.color->content, (float)i / lenght).h*/
static void	print_line_loop(t_point p1, t_point p2, t_coord v, t_data *data)
{
	int		i;
	t_coord	i_coord;
	int		lenght;

	lenght = ft_abs(v.x) * ft_abs(v.y);
	i_coord = set_coord(0, 0, 0);
	i = 0;
	put_pxl(data, p1.coord.x + (i_coord.x * ft_sig(v.x)),
		p1.coord.y + (i_coord.y * ft_sig(v.y)),
		get_average_color(p1.color->content,
			p2.color->content, 0).h);
	while (i < lenght)
	{
		if (print_line_condition(v, i, &i_coord))
			put_pxl(data, p1.coord.x + (i_coord.x * ft_sig(v.x)),
				p1.coord.y + (i_coord.y * ft_sig(v.y)),
				get_average_color(p1.color->content,
					p2.color->content, (float)i / lenght).h);
		i++;
	}
}

void	print_line(t_point p1, t_point p2, t_data *data, t_zoom zoom)
{
	t_coord	v;

	p1.coord = set_coord(p1.coord.x * zoom.len + WIN_SIZE_X / 2 + zoom.push_v,
			p1.coord.y * zoom.len + WIN_SIZE_Y / 2 + zoom.push_h, 0);
	p2.coord = set_coord(p2.coord.x * zoom.len + WIN_SIZE_X / 2 + zoom.push_v,
			p2.coord.y * zoom.len + WIN_SIZE_Y / 2 + zoom.push_h, 0);
	v = set_coord(p2.coord.x - p1.coord.x, p2.coord.y - p1.coord.y, 0);
	v = set_coord(v.x + (1 * ft_sig(v.x)), v.y + (1 * ft_sig(v.y)), 0);
	print_line_loop(p1, p2, v, data);
}

void	put_pxl(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x <= WIN_SIZE_X && y >= 0 && y <= WIN_SIZE_Y)
	{
		dst = data->addr
			+ (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
