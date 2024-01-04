/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parts_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:37:56 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/04 21:08:10 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf_struct.h>
#include <libft.h>
#include <stdlib.h>

size_t	file_size(char **file0)
{
	char	**file;

	file = file0;
	while (*file)
		file++;
	return (file - file0);
}

t_coord	parts_size(char ***parts0)
{
	char	***parts;
	t_coord	size;

	size.x = file_size(*parts0);
	parts = parts0;
	while (*parts)
	{
		if ((int)file_size(*parts) != size.x)
			break ;
		parts++;
	}
	size.y = parts - parts0;
	return (size);
}

void	free_parts(char ***parts0)
{
	char	***parts;

	parts = parts0;
	while (*parts)
	{
		ft_free_tab(*parts);
		parts++;
	}
	free(parts0);
}
