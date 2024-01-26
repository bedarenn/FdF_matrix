/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:49:54 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/26 14:27:24 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	mutiply_map(t_point **map, t_coord size, t_theta t, t_zoom zoom)
{
	t_coord		i;
	t_trigo		m;
	t_matrix	matrix;

	matrix_xy(matrix.xy, t.xy / 180 * PI);
	matrix_yz(matrix.yz, t.yz / 180 * PI);
	matrix_zx(matrix.zx, t.zx / 180 * PI);
	i.y = 0;
	while (i.y < size.y)
	{
		i.x = 0;
		while (i.x < size.x)
		{
			m = map[i.y][i.x].coord;
			m.z *= zoom.high;
			m = set_trigo(m.x * zoom.zoom, m.y * zoom.zoom, m.z * zoom.zoom);
			m = multiply_matrix(m, matrix.xy);
			m = multiply_matrix(m, matrix.yz);
			m = multiply_matrix(m, matrix.zx);
			map[i.y][i.x].pixel.coord = apply_zoom(m, zoom);
			i.x++;
		}
		i.y++;
	}
}

t_trigo	multiply_matrix(t_trigo m, long double matrix[3][3])
{
	m = set_trigo(m.x * matrix[0][0] + m.y * matrix[0][1] + m.z * matrix[0][2],
			m.x * matrix[1][0] + m.y * matrix[1][1] + m.z * matrix[1][2], m.x
			* matrix[2][0] + m.y * matrix[2][1] + m.z * matrix[2][2]);
	return (m);
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
