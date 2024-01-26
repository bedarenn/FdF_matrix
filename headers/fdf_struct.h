/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:11:52 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/25 13:03:14 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H

# include <stddef.h>
# include <libwati.h>

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*img;
}	t_mlx;

typedef struct s_trigo
{
	long double	x;
	long double	y;
	long double	z;
}	t_trigo;

typedef struct s_coord
{
	int	x;
	int	y;
	int	z;
}	t_coord;

typedef struct s_color
{
	unsigned char	t;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned int	h;
}	t_color;

typedef struct s_pixel
{
	t_coord	coord;
	t_list	*color;
}	t_pixel;

typedef struct s_point
{
	t_trigo	coord;
	t_list	*color;
	t_pixel	pixel;
}	t_point;

typedef struct s_zoom
{
	double	len;
	int		push_h;
	int		push_v;
	double	zoom;
	double	high;
}	t_zoom;

typedef struct s_theta
{
	long double	xy;
	long double	yz;
	long double	zx;
}	t_theta;

typedef struct s_matrix
{
	long double	xy[3][3];
	long double	yz[3][3];
	long double	zx[3][3];
}	t_matrix;

typedef struct s_var
{
	t_mlx	mlx;
	t_point	**map;
	t_coord	size;
	t_zoom	zoom;
	t_theta	t;
}	t_var;

#endif
