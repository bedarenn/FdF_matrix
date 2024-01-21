/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:57:36 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 17:09:40 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGNL_H
# define LIBGNL_H

# include <libwati.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct s_buffer
{
	int				fd;
	char			*buffer;
	int				cursor;
	int				r;
	struct s_buffer	*next;
}	t_buffer;

char		*get_next_line(int fd);
char		*read_file(t_buffer *b);
t_buffer	*new_buffer(int fd);

t_buffer	*get_buffer(int fd);
void		delete_buffer(int fd);

void		print_file(int fd);
t_list		*get_file_list(int fd);
char		**get_file(int fd);

#endif