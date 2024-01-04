/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:47:35 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/04 21:14:39 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <ft_printf.h>

t_hook_var	init(char *file_name)
{
	char		***parts;
	t_hook_var	var;

	parts = get_parts(file_name);
	var.size = parts_size(parts);
	free_parts(parts);
	return (var);
}

int	main(int argc, char **argv)
{
	t_hook_var	var;

	if (argc == 1)
		return (1);
	var = init(argv[1]);
	return (0);
}
