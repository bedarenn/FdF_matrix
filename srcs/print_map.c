/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:38:13 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/31 11:50:42 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <mlx.h>

void	print_data(t_var *var)
{
	apply_to_map(var->map, var->size, var->t, var->zoom);
	clear_data(var->mlx);
	print_map(var->map, var->size, var->mlx);
	mlx_put_image_to_window(var->mlx.ptr, var->mlx.win, var->mlx.img, 0, 0);
}

void	print_map(t_point **map, t_coord size, t_mlx mlx)
{
	t_coord	i;

	i.y = 0;
	while (i.y < size.y)
	{
		i.x = 0;
		while (i.x < size.x)
		{
			if (i.x > 0)
				print_line(map[i.y][i.x], map[i.y][i.x - 1], mlx);
			if (i.y > 0)
				print_line(map[i.y][i.x], map[i.y - 1][i.x], mlx);
			i.x++;
		}
		i.y++;
	}
}

void	clear_data(t_mlx mlx)
{
	t_coord	i;

	i.y = 0;
	while (i.y < WIN_SIZE_Y)
	{
		i.x = 0;
		while (i.x < WIN_SIZE_X)
		{
			mlx_set_image_pixel(mlx.ptr, mlx.img, i.x, i.y, 0xFF000000);
			i.x++;
		}
		i.y++;
	}
}
