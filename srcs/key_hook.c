/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:11:49 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/05 19:18:26 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <mlx.h>

int	key_hook(int keycode, t_hook_var *var)
{
	if (keycode == 65307)
		win_close(var);
	return (0);
}

int	win_close(t_hook_var *var)
{
	mlx_destroy_image(var->mlx.ptr, var->data.img);
	mlx_destroy_window(var->mlx.ptr, var->mlx.win);
	mlx_destroy_display(var->mlx.ptr);
	free(var->mlx.ptr);
	free_map(var->map, var->size);
	exit(EXIT_SUCCESS);
	return (0);
}
