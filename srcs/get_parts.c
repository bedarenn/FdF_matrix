/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:09:54 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/09 12:52:15 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

#include <fcntl.h>
#include <libgnl.h>
#include <unistd.h>

#include <libwati.h>

#include <stdlib.h>

static void	*void_split(void *ptr)
{
	return (wati_split(ptr, ' '));
}

t_list	*get_parts(char *file_name)
{
	int		fd;
	t_list	*file;
	t_list	*parts;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	file = get_file_list(fd);
	wati_printf("read done\n");
	close(fd);
	if (!file)
		return (NULL);
	parts = wati_lstmap(file, void_split, free);
	wati_lstclear(&file, free);
	wati_printf("split done\n");
	return (parts);
}
