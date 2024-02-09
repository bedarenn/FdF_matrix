/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:47:35 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/09 12:22:24 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <mlx.h>

static int	close_hook(int event, void *var)
{
	if (event == 0)
		win_close(var);
	return (0);
}

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
	var.t = init_theta();
	apply_to_map(var.map, var.size, var.t, var.zoom);
	print_map(var.map, var.size, var.mlx);
	mlx_put_image_to_window(var.mlx.ptr, var.mlx.win, var.mlx.img, 0, 0);
	mlx_on_event(var.mlx.ptr, var.mlx.win,
		MLX_KEYDOWN, &key_hook, (void *)&var);
	mlx_on_event(var.mlx.ptr, var.mlx.win,
		MLX_WINDOW_EVENT, &close_hook, (void *)&var);
	mlx_loop(var.mlx.ptr);
	return (0);
}
