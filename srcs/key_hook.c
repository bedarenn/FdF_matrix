/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:11:49 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 18:26:51 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <mlx.h>
#include <stdlib.h>
#include <fdf_keymap.h>

int	key_hook(int keycode, t_var *var)
{
	wati_printf("key: %i\n", keycode);
	if (keycode == KEY_ESCAPE)
		win_close(var);
	if (keycode == KEY_C)
		change_color(var->map, var->size);
	print_data(*var);
	return (0);
}

int	win_close(t_var *var)
{
	mlx_destroy_image(var->mlx.ptr, var->data.img);
	mlx_destroy_window(var->mlx.ptr, var->mlx.win);
	mlx_destroy_display(var->mlx.ptr);
	free(var->mlx.ptr);
	free_map(var->map, var->size);
	exit(EXIT_SUCCESS);
	return (0);
}

void	print_data(t_var var)
{
	clear_data(&var.data);
	print_map(var.map, var.size, var.zoom, &var.data);
	mlx_put_image_to_window(var.mlx.ptr, var.mlx.win, var.data.img, 0, 0);
}
