/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:37:43 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/24 14:21:11 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

void	matrix_xy(long double matrix[3][3], long double t)
{
	matrix[0][0] = cos(t);
	matrix[0][1] = -sin(t);
	matrix[0][2] = 0;
	matrix[1][0] = sin (t);
	matrix[1][1] = cos(t);
	matrix[1][2] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
}

void	matrix_yz(long double matrix[3][3], long double t)
{
	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = cos(t);
	matrix[1][2] = -sin(t);
	matrix[2][0] = 0;
	matrix[2][1] = sin(t);
	matrix[2][2] = cos(t);
}

void	matrix_zx(long double matrix[3][3], long double t)
{
	matrix[0][0] = cos(t);
	matrix[0][1] = 0;
	matrix[0][2] = sin(t);
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[2][0] = -sin(t);
	matrix[2][1] = 0;
	matrix[2][2] = cos(t);
}
