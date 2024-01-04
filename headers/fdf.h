/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:49:41 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/04 21:16:47 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fdf_struct.h>
# include <fdf_const.h>

/*    struct_assessor    */
t_coord	set_coord(int x, int y, int z);
t_color	set_color(unsigned char t, unsigned char r,
			unsigned char g, unsigned char b);
t_color	set_color_hex(unsigned int h);
void	add_point_color(t_point *point, t_color new);

/*    get_parts    */
char	***get_parts(char *file_name);
	/*    Tools    */
size_t	file_size(char **file);
t_coord	parts_size(char ***parts);
void	free_parts(char ***parts);

#endif