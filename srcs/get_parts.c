/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:09:54 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/05 19:01:06 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

#include <fcntl.h>
#include <libgnl.h>
#include <unistd.h>

#include <libft.h>
#include <ft_printf.h>

#include <stdlib.h>

static char	***split_file(char **file)
{
	char	***parts;
	size_t	size;
	size_t	i;

	size = file_size(file);
	parts = calloc(sizeof(char **), size + 1);
	if (!parts)
		return (NULL);
	i = 0;
	while (i < size)
	{
		parts[i] = ft_split(file[i], ' ');
		if (!parts[i])
		{
			free_parts(parts);
			return (0);
		}
		i++;
	}
	return (parts);
}

char	***get_parts(char *file_name)
{
	int		fd;
	char	**file;
	char	***parts;

	fd = open(file_name, O_RDONLY);
	if (!fd)
		return (NULL);
	file = get_file(fd);
	ft_printf("read done\n");
	close(fd);
	if (!file)
		return (NULL);
	parts = split_file(file);
	ft_printf("split done\n");
	ft_free_tab(file);
	return (parts);
}
