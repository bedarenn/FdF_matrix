/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_apply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:49:54 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/06 13:03:40 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	apply_to_map(t_point **map, t_coord size, t_theta t, t_zoom zoom)
{
	t_coord		i;
	t_trigo		m;
	t_matrix	matrix;
	long double	matrix_f[3][3];

	matrix_xy(matrix.xy, t.xy / 180 * PI);
	matrix_yz(matrix.yz, t.yz / 180 * PI);
	matrix_zx(matrix.zx, t.zx / 180 * PI);
	matrix_multiply(matrix_f, matrix.yz, matrix.zx);
	i.y = 0;
	while (i.y < size.y)
	{
		i.x = 0;
		while (i.x < size.x)
		{
			m = map[i.y][i.x].coord;
			m.z *= zoom.high;
			m = set_trigo(m.x * zoom.zoom, m.y * zoom.zoom, m.z * zoom.zoom);
			m = vector_multiply(m, matrix.xy);
			m = vector_multiply(m, matrix_f);
			map[i.y][i.x].pixel.coord = apply_zoom(m, zoom);
			i.x++;
		}
		i.y++;
	}
}

t_coord	apply_zoom(t_trigo m, t_zoom zoom)
{
	t_coord	coord;

	coord = set_coord(zoom.push_h + m.x, zoom.push_v + m.y, 0);
	return (coord);
}

int	in_window(int x, int y)
{
	if (x >= 0 && x < WIN_SIZE_X && y >= 0 && y < WIN_SIZE_Y)
		return (1);
	return (0);
}
