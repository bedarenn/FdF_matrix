/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parts_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:37:56 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/09 12:49:10 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf_struct.h>
#include <libwati.h>
#include <stdlib.h>

size_t	part_size(char **file0)
{
	char	**file;

	file = file0;
	while (*file)
		file++;
	return (file - file0);
}

t_coord	parts_size(t_list *parts)
{
	t_coord	size;
	int		line_size;

	if (!parts->content)
	{
		size.x = 0;
		return (size);
	}
	size.y = 1;
	line_size = part_size(parts->content);
	size.x = line_size;
	parts = parts->next;
	while (parts && parts->content)
	{
		size.x = part_size(parts->content);
		if (size.x != line_size)
		{
			size.x = 0;
			return (size);
		}
		size.y++;
		parts = parts->next;
	}
	return (size);
}
