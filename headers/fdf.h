/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:49:41 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/09 12:15:11 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fdf_struct.h>
# include <fdf_const.h>

/*    init_var    */
t_var	init_map(char *file_name);
t_mlx	init_mlx(char *title);
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
t_color	get_average_color(t_color *color1, t_color *color2, float percent);

/*    custom_color    */
char	*skip_nb(char *str);
t_color	set_color_height(int height);

/*    get_matrix    */
void	matrix_xy(long double matrix[3][3], long double t);
void	matrix_yz(long double matrix[3][3], long double t);
void	matrix_zx(long double matrix[3][3], long double t);
void	matrix_iso(long double matrix[3][3]);

/*    matrix_apply    */
void	apply_to_map(t_point **map, t_coord size, t_theta t, t_zoom zoom);
t_coord	apply_zoom(t_trigo m, t_zoom zoom);
int		in_window(int x, int y);

/*    matrix_multiply    */
t_trigo	vector_multiply(t_trigo m, long double matrix[3][3]);
void	matrix_multiply(long double matrix[3][3],
			long double m1[3][3], long double m2[3][3]);
void	matrix_dup(long double dst[3][3], long double src[3][3]);

/*    print_line    */
void	print_line(t_point p1, t_point p2, t_mlx mlx);
void	put_pixel(t_mlx mlx, int x, int y, t_color color);
void	draw_line_bresenham(t_pixel p1, t_pixel p2, t_mlx mlx);
void	put_pixel_p(t_mlx mlx, int x, int y, t_color *color);

/*    print_map    */
void	print_data(t_var *var);
void	print_map(t_point **map, t_coord size, t_mlx mlx);
void	clear_data(t_mlx mlx);

/*    key_hook    */
int		key_hook(int keycode, void *var);
int		key_letter(int keycode, t_var *var);
int		key_arrow(int keycode, t_var *var);
int		key_other(int keycode, t_var *var);
int		win_close(t_var *var);

#endif