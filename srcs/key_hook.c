/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:11:49 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/24 14:34:58 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <fdf_keymap.h>
#include <mlx.h>
#include <stdlib.h>

int	key_hook(int keycode, t_var *var)
{
	if (keycode == KEY_ESCAPE)
		win_close(var);
	else if (keycode == KEY_C)
		change_color(var->map, var->size);
	else if (key_arrow(keycode, var))
		;
	else if (key_wasd(keycode, var))
		;
	if (var->t.xy >= 360)
		var->t.xy -= 360;
	if (var->t.xy <= -360)
		var->t.xy += 360;
	print_data(*var);
	return (0);
}

int	key_wasd(int keycode, t_var *var)
{
	if (keycode == KEY_A)
	{
		var->t.xy -= 5;
		mutiply_map(var->map, var->size, var->t, var->zoom);
	}
	else if (keycode == KEY_D)
	{
		var->t.xy += 5;
		mutiply_map(var->map, var->size, var->t, var->zoom);
	}
	else if (keycode == KEY_W)
	{
		var->t.yz += 5;
		mutiply_map(var->map, var->size, var->t, var->zoom);
	}
	else if (keycode == KEY_S)
	{
		var->t.yz -= 5;
		mutiply_map(var->map, var->size, var->t, var->zoom);
	}
	else
		return (0);
	return (1);
}

int	key_arrow(int keycode, t_var *var)
{
	if (keycode == KEY_LEFT)
	{
		var->zoom.push_h -= 10;
		mutiply_map(var->map, var->size, var->t, var->zoom);
	}
	else if (keycode == KEY_RIGHT)
	{
		var->zoom.push_h += 10;
		mutiply_map(var->map, var->size, var->t, var->zoom);
	}
	else if (keycode == KEY_UP)
	{
		var->zoom.push_v -= 10;
		mutiply_map(var->map, var->size, var->t, var->zoom);
	}
	else if (keycode == KEY_DOWN)
	{
		var->zoom.push_v += 10;
		mutiply_map(var->map, var->size, var->t, var->zoom);
	}
	else
		return (0);
	return (1);
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
	print_map(var.map, var.size, &var.data);
	mlx_put_image_to_window(var.mlx.ptr, var.mlx.win, var.data.img, 0, 0);
}
