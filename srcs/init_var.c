/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:19:57 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/07 19:27:05 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <mlx.h>

t_var	init_map(char *file_name)
{
	char		***parts;
	t_var	var;

	parts = get_parts(file_name);
	if (!parts)
	{
		var.map = NULL;
		return (var);
	}
	var.size = parts_size(parts);
	ft_printf("x%i y%i\n", var.size.x, var.size.y);
	var.map = get_map(parts, var.size);
	if (var.map)
		ft_printf("map created\n");
	else
		ft_printf("map error creation\n");
	free_parts(parts);
	return (var);
}

t_mlx	init_mlx(char *title)
{
	t_mlx		mlx;

	mlx.ptr = mlx_init();
	if (mlx.ptr)
		mlx.win = mlx_new_window(mlx.ptr, WIN_SIZE_X, WIN_SIZE_Y, title);
	return (mlx);
}

t_data	init_img(t_mlx mlx, int width, int height)
{
	t_data		img;

	img.img = mlx_new_image(mlx.ptr, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	return (img);
}

t_zoom	init_zoom(t_coord size)
{
	t_zoom	zoom;

	if (WIN_SIZE_X / size.x >= WIN_SIZE_Y / size.y)
		zoom.len = (double)(WIN_SIZE_Y - 1) / (size.y + 1);
	else
		zoom.len = (double)(WIN_SIZE_X - 1) / (size.x + 1);
	zoom.push_h = 0;
	zoom.push_v = 0;
	return (zoom);
}