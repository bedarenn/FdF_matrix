/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:36:34 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/09 12:26:40 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libwati.h>
#include <mlx.h>
#include <math.h>

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

void	print_line_loop(t_pixel p1, t_pixel p2, t_coord v, t_mlx mlx)
{
	int		i;
	t_coord	i_coord;
	long	lenght;

	lenght = wati_abs(v.x) * wati_abs(v.y);
	i_coord = set_coord(0, 0, 0);
	i = 0;
	put_pixel(mlx, p1.coord.x + (i_coord.x * wati_sig(v.x)), p1.coord.y
		+ (i_coord.y * wati_sig(v.y)), get_average_color(p1.color->content,
			p2.color->content, (float)i / lenght));
	while (i < lenght)
	{
		if (print_line_condition(v, i, &i_coord))
			put_pixel(mlx, p1.coord.x + (i_coord.x * wati_sig(v.x)), p1.coord.y
				+ (i_coord.y * wati_sig(v.y)),
				get_average_color(p1.color->content, p2.color->content, (float)i
					/ lenght));
		i++;
	}
}

void	print_line(t_point p1, t_point p2, t_mlx mlx)
{
	t_coord	v;

	if (!in_window(p1.pixel.coord.x, p1.pixel.coord.y)
		&& !in_window(p2.pixel.coord.x, p2.pixel.coord.y))
		return ;
	v = set_coord(p2.pixel.coord.x - p1.pixel.coord.x, p2.pixel.coord.y
			- p1.pixel.coord.y, 0);
	v = set_coord(p2.pixel.coord.x - p1.pixel.coord.x, p2.pixel.coord.y
			- p1.pixel.coord.y, 0);
	v = set_coord(v.x + (1 * wati_sig(v.x)), v.y + (1 * wati_sig(v.y)), 0);
	print_line_loop(p1.pixel, p2.pixel, v, mlx);
}

void	put_pixel(t_mlx mlx, int x, int y, t_color color)
{
	if (in_window(x, y))
		mlx_set_image_pixel(mlx.ptr, mlx.img, x, y, color.h);
}
