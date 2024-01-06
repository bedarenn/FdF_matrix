/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:49:41 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/06 12:53:54 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fdf_struct.h>
# include <fdf_const.h>

/*    struct_assessor    */
t_coord	set_coord(int x, int y, int z);
t_trigo	set_trigo(double x, double y, double z);
t_color	set_color(unsigned char t, unsigned char r,
			unsigned char g, unsigned char b);
t_color	set_color_hex(unsigned int h);
t_list	*lstnew_color(t_color new);

/*    get_parts    */
char	***get_parts(char *file_name);
	/*    Tools    */
size_t	file_size(char **file);
t_coord	parts_size(char ***parts);
void	free_parts(char ***parts);

/*    get_map    */
t_point	**get_map(char ***parts, t_coord size);
t_point	*get_line(char **part, t_coord i, t_coord size);
t_point	get_point(char *str, t_coord i, t_coord size);
	/*    Tools    */
void	free_map(t_point **map0, t_coord size);
void	print_point(t_point point);

/*   get_color    */
char	*skip_nb(char *str);
t_color	get_color(char *str);

/*    key_hook    */
int		key_hook(int keycode, t_hook_var *var);
int		win_close(t_hook_var *var);

/*    print_line    */
void	put_pxl(t_data *data, int x, int y, int color);
void	print_line(t_point p1, t_point p2, t_data *data, t_zoom zoom);

#endif