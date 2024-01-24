/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:49:41 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/24 14:20:47 by bedarenn         ###   ########.fr       */
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
t_theta	init_theta(void);

/*    struct_assessor    */
t_coord	set_coord(int x, int y, int z);
t_trigo	set_trigo(double x, double y, double z);
t_color	set_color(unsigned char t, unsigned char r,
			unsigned char g, unsigned char b);
t_color	set_color_hex(unsigned int h);
t_list	*lstnew_color(t_color new);

/*    get_parts    */
t_list	*get_parts(char *file_name);
	/*    Tools    */
size_t	file_size(char **file);
t_coord	parts_size(t_list *parts);
void	free_parts(char ***parts);

/*    get_map    */
t_point	**get_map(t_list *parts, t_coord size, t_zoom zoom);
t_point	*get_line(char **part, t_coord i, t_coord size, t_zoom zoom);
t_point	get_point(char *str, t_coord i, t_coord size, t_zoom zoom);
	/*    Tools    */
void	free_map(t_point **map0, t_coord size);
void	print_point(t_point point);

/*   get_color    */
t_color	get_color(char *str);
void	change_color(t_point **map, t_coord size);

/*    custom_color    */
char	*skip_nb(char *str);
t_color	set_color_height(int height);

/*    get_matrix    */
void	matrix_xy(long double matrix[3][3], long double t);
void	matrix_yz(long double matrix[3][3], long double t);
void	matrix_zx(long double matrix[3][3], long double t);
void	matrix_iso(long double matrix[3][3]);

/*    multiply_matrix    */
void	mutiply_map(t_point **map, t_coord size, t_theta t, t_zoom zoom);
t_trigo	multiply_matrix(t_trigo m, long double matrix[3][3]);
t_point	apply_zoom(t_point p, t_trigo m, t_zoom zoom);

/*    print_line    */
void	put_pxl(t_data *data, int x, int y, int color);
void	print_line(t_point p1, t_point p2, t_data *data);

/*    print_map    */
void	print_map(t_point **map, t_coord size, t_data *data);
void	clear_data(t_data *data);

/*    key_hook    */
int		key_hook(int keycode, t_var *var);
int		key_arrow(int keycode, t_var *var);
int		key_wasd(int keycode, t_var *var);
int		win_close(t_var *var);
void	print_data(t_var var);

#endif