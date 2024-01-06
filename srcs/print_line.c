/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:36:34 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/06 13:33:01 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <stdio.h>

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

void	print_line(t_point p1, t_point p2, t_data *data, t_zoom zoom)
{
	t_trigo	vector;
	size_t	lenght;
	t_coord	i_coord;
	t_trigo	i_vector;

	p1.coord = set_coord(p1.coord.x * zoom.len + WIN_SIZE_X / 2,
			p1.coord.y * zoom.len + WIN_SIZE_Y / 2, 0);
	p2.coord = set_coord(p2.coord.x * zoom.len + WIN_SIZE_X / 2,
			p2.coord.y * zoom.len + WIN_SIZE_Y / 2, 0);
	vector = set_trigo(p2.coord.x - p1.coord.x,
			p2.coord.y - p1.coord.y,
			0);
	//i_vector = set_trigo(, , 0)
	lenght = ft_abs(p2.coord.x - p1.coord.x) * ft_abs(p2.coord.y - p1.coord.y);
	printf("p1 %i %i %i\n", p1.coord.x, p1.coord.y, p1.coord.z);
	printf("p2 %i %i %i\n", p2.coord.x, p2.coord.y, p2.coord.z);
	printf("vector %f %f %f\n", vector.x, vector.y, vector.z);
	printf("lenght %zu\n", lenght);
	i_coord = set_coord(0, 0, 0);
}

/*void	print_line(t_point p1, t_point p2, t_data *data, t_zoom zoom)
{
	t_coord	v;
	int		lenght;
	t_coord	index;
	int		i;

	v = set_coord(p2.coord.x - p1.coord.x, p2.coord.y - p1.coord.y);
	v = set_coord(v.x + (1 * ft_sig(v.x)), v.y + (1 * ft_sig(v.y)));
	lenght = ft_abs(v.x) * ft_abs(v.y);
	index = set_coord(0, 0);
	p1.coord = set_coord(p1.coord.x + zoom.move.x,
			p1.coord.y + zoom.move.y);
	p2.coord = set_coord(p2.coord.x + zoom.move.x,
			p2.coord.y + zoom.move.y);
	i = 0;
	while (i < lenght)
	{
		if (index.x < i / ft_abs(v.y))
			index.x++;
		if (index.y < i / ft_abs(v.x))
			index.y++;
		put_pxl(data, p1.coord.x + (index.x * ft_sig(v.x)),
			p1.coord.y + (index.y * ft_sig(v.y)),
			get_average_color(*p2.color, *p1.color, (float)i / lenght).h);
		i++;
	}
}*/
