/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:11:49 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/26 14:20:03 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <fdf_keymap.h>
#include <mlx.h>
#include <stdlib.h>

int	key_hook(int keycode, void *var)
{
	wati_printf("%i\n", keycode);
	if (keycode == KEY_ESCAPE)
		win_close(var);
	else if (key_arrow(keycode, var))
		print_data(var);
	else if (key_letter(keycode, var))
		print_data(var);
	if (key_other(keycode, var))
		return (0);
	return (0);
}

int	key_other(int keycode, t_var *var)
{
	if (keycode == KEY_C)
	{
		change_color(var->map, var->size);
		clear_data(var->mlx);
		print_map(var->map, var->size, var->mlx);
		mlx_put_image_to_window(var->mlx.ptr, var->mlx.win, var->mlx.img, 0, 0);
	}
	else
		return (0);
	return (1);
}

int	key_letter(int keycode, t_var *var)
{
	if (keycode == KEY_W)
		var->t.yz += M_INCR;
	else if (keycode == KEY_S)
		var->t.yz -= M_INCR;
	else if (keycode == KEY_Q)
		var->t.zx += M_INCR;
	else if (keycode == KEY_E)
		var->t.zx -= M_INCR;
	else if (keycode == KEY_A)
		var->t.xy -= M_INCR;
	else if (keycode == KEY_D)
		var->t.xy += M_INCR;
	else if (keycode == KEY_R)
		var->zoom.high += H_INCR;
	else if (keycode == KEY_F)
		var->zoom.high -= H_INCR;
	else if (keycode == KEY_T)
		var->zoom.zoom *= Z_INCR;
	else if (keycode == KEY_G)
		var->zoom.zoom /= Z_INCR;
	else
		return (0);
	return (1);
}

int	key_arrow(int keycode, t_var *var)
{
	if (keycode == KEY_LEFT)
		var->zoom.push_h += M_INCR;
	else if (keycode == KEY_RIGHT)
		var->zoom.push_h -= M_INCR;
	else if (keycode == KEY_UP)
		var->zoom.push_v += M_INCR;
	else if (keycode == KEY_DOWN)
		var->zoom.push_v -= M_INCR;
	else
		return (0);
	return (1);
}

int	win_close(t_var *var)
{
	mlx_destroy_image(var->mlx.ptr, var->mlx.img);
	mlx_destroy_window(var->mlx.ptr, var->mlx.win);
	mlx_destroy_display(var->mlx.ptr);
	free_map(var->map, var->size);
	exit(EXIT_SUCCESS);
	return (0);
}
