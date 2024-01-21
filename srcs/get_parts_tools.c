/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parts_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:37:56 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 17:38:40 by bedarenn         ###   ########.fr       */
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

	if (!parts)
	{
		size.x = 0;
		size.y = 0;
		return (size);
	}
	size.y = 1;
	size.x = part_size(parts->content);
	parts = parts->next;
	while (parts && (int)part_size(parts->content) == size.x)
	{
		size.y++;
		parts = parts->next;
	}
	return (size);
}
