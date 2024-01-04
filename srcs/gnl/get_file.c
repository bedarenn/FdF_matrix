/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:43:38 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/04 19:54:41 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgnl.h>
#include <libft.h>
#include <stdlib.h>
#include <ft_printf.h>

void	print_file(int fd)
{
	char	*str;

	str = get_next_line(fd);
	while (str)
	{
		ft_putchar_fd('/', 1);
		ft_putstr_fd(str, 1);
		free(str);
		str = get_next_line(fd);
	}
}

static t_list	*get_line_list(int fd)
{
	char	*str;
	t_list	*list;

	str = get_next_line(fd);
	if (!str)
		return (NULL);
	list = ft_lstnew(str);
	if (!list)
		free(str);
	return (list);
}

static t_list	*get_file_list(int fd)
{
	char	*str;
	t_list	*list0;
	t_list	*list;

	list0 = get_line_list(fd);
	if (!list0)
		return (NULL);
	str = get_next_line(fd);
	list = list0;
	while (str)
	{
		list->next = ft_lstnew(str);
		if (!list->next)
		{
			ft_lstclear(&list0, free);
			return (NULL);
		}
		str = get_next_line(fd);
		list = list->next;
	}
	return (list0);
}

char	**get_file(int fd)
{
	char	**strs;
	t_list	*list;

	list = get_file_list(fd);
	if (!list)
		return (NULL);
	strs = ft_lstsplit(list);
	ft_lstclean(&list);
	return (strs);
}
