/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:47:35 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/06 13:24:16 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <mlx.h>
#include <ft_printf.h>

t_hook_var	init_map(char *file_name)
{
	char		***parts;
	t_hook_var	var;

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

int	main(int argc, char **argv)
{
	t_hook_var	var;
	t_point		p1;
	t_point		p2;

	if (argc == 1)
		return (1);
	p1.coord = set_coord(-1, 0, -1);
	p2.coord = set_coord(1, 0, 1);
	var.zoom.len = 100;
	print_line(p2, p1, NULL, var.zoom);
	/*var = init_map(argv[1]);
	if (!var.map)
		return (1);
	var.mlx = init_mlx(argv[1]);
	var.data = init_img(var.mlx, WIN_SIZE_X, WIN_SIZE_Y);
	mlx_key_hook(var.mlx.win, key_hook, &var);
	mlx_hook(var.mlx.win, 17, 1L << 17, win_close, &var);
	mlx_loop(var.mlx.ptr);
	free_map(var.map, var.size);*/
	return (0);
}
