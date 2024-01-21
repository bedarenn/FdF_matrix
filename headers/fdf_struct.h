/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:11:52 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 17:09:40 by bedarenn         ###   ########.fr       */
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
}	t_mlx;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_trigo
{
	double	x;
	double	y;
	double	z;
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

typedef struct s_point
{
	t_coord	coord;
	t_list	*color0;
	t_list	*color;
}	t_point;

typedef struct s_zoom
{
	double	len;
	int		push_h;
	int		push_v;
}	t_zoom;

typedef struct s_var
{
	t_mlx	mlx;
	t_data	data;
	t_point	**map;
	t_coord	size;
	t_zoom	zoom;
}	t_var;

#endif
