/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:47:35 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 18:18:34 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <mlx.h>

int	main(int argc, char **argv)
{
	t_var	var;

	if (argc == 1)
		return (1);
	var = init_map(argv[1]);
	if (!var.map)
		return (1);
	var.mlx = init_mlx(argv[1]);
	if (!var.mlx.ptr || !var.mlx.win)
		return (1);
	var.data = init_img(var.mlx, WIN_SIZE_X, WIN_SIZE_Y);
	var.zoom = init_zoom(var.size);
	print_map(var.map, var.size, var.zoom, &var.data);
	mlx_put_image_to_window(var.mlx.ptr, var.mlx.win, var.data.img, 0, 0);
	mlx_key_hook(var.mlx.win, key_hook, &var);
	mlx_hook(var.mlx.win, 17, 1L << 17, win_close, &var);
	mlx_loop(var.mlx.ptr);
	return (0);
}
