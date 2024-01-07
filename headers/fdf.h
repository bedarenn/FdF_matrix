/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:49:41 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/07 19:28:08 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fdf_struct.h>
# include <fdf_const.h>

/*    init_var    */
t_var	init_map(char *file_name);
t_mlx	init_mlx(char *title);
t_data	init_img(t_mlx mlx, int width, int height);
t_zoom	init_zoom(t_coord size);

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
int		key_hook(int keycode, t_var *var);
int		win_close(t_var *var);

/*    print_line    */
void	put_pxl(t_data *data, int x, int y, int color);
void	print_line(t_point p1, t_point p2, t_data *data, t_zoom zoom);

/*    print_map    */
void	print_map(t_point **map, t_coord size, t_zoom zoom, t_data *data);

#endif