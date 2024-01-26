/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:19:57 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/25 13:10:30 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <mlx.h>

t_var	init_map(char *file_name)
{
	t_list	*parts;
	t_var	var;

	parts = get_parts(file_name);
	if (!parts)
	{
		var.map = NULL;
		return (var);
	}
	var.size = parts_size(parts);
	wati_printf("x%i y%i\n", var.size.x, var.size.y);
	var.zoom = init_zoom(var.size);
	var.map = get_map(parts, var.size, var.zoom);
	wati_lstclear(&parts, wati_free_tab);
	if (!var.map)
		wati_printf("map error creation\n");
	wati_printf("map created\n");
	return (var);
}

t_mlx	init_mlx(char *title)
{
	t_mlx		mlx;

	mlx.ptr = mlx_init();
	if (mlx.ptr)
		mlx.win = mlx_new_window(mlx.ptr, WIN_SIZE_X, WIN_SIZE_Y, title);
	else
		return (mlx);
	if (mlx.win)
		mlx.img = mlx_new_image(mlx.ptr, WIN_SIZE_X, WIN_SIZE_Y);
	else
	{
		mlx_destroy_display(mlx.ptr);
		return (mlx);
	}
	if (!mlx.img)
	{
		mlx_destroy_window(mlx.ptr, mlx.win);
		mlx_destroy_display(mlx.ptr);
	}
	return (mlx);
}

t_zoom	init_zoom(t_coord size)
{
	t_zoom	zoom;

	if (WIN_SIZE_X / size.x >= WIN_SIZE_Y / size.y)
		zoom.len = (double)(WIN_SIZE_Y - 1) / (size.y + 1);
	else
		zoom.len = (double)(WIN_SIZE_X - 1) / (size.x + 1);
	zoom.push_h = WIN_SIZE_X / 2;
	zoom.push_v = WIN_SIZE_Y / 2;
	zoom.high = HIGH;
	zoom.zoom = ZOOM;
	return (zoom);
}

t_theta	init_theta(void)
{
	t_theta	t;

	t.xy = R_XY;
	t.yz = R_YZ;
	t.zx = R_ZX;
	return (t);
}
