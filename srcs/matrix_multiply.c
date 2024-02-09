/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:44:56 by bedarenn          #+#    #+#             */
/*   Updated: 2024/02/09 12:12:54 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_trigo	vector_multiply(t_trigo m, long double matrix[3][3])
{
	m = set_trigo(m.x * matrix[0][0] + m.y * matrix[0][1] + m.z * matrix[0][2],
			m.x * matrix[1][0] + m.y * matrix[1][1] + m.z * matrix[1][2], m.x
			* matrix[2][0] + m.y * matrix[2][1] + m.z * matrix[2][2]);
	return (m);
}

void	matrix_multiply(long double matrix[3][3],
		long double m1[3][3], long double m2[3][3])
{
	matrix[0][0] = m1[0][0] * m2[0][0]
		+ m1[0][1] * m2[1][0] + m1[0][2] * m2[2][0];
	matrix[0][1] = m1[0][0] * m2[0][1]
		+ m1[0][1] * m2[1][1] + m1[0][2] * m2[2][1];
	matrix[0][2] = m1[0][0] * m2[0][2]
		+ m1[0][1] * m2[1][2] + m1[0][2] * m2[2][2];
	matrix[1][0] = m1[1][0] * m2[0][0]
		+ m1[1][1] * m2[1][0] + m1[1][2] * m2[2][0];
	matrix[1][1] = m1[1][0] * m2[0][1]
		+ m1[1][1] * m2[1][1] + m1[1][2] * m2[2][1];
	matrix[1][2] = m1[1][0] * m2[0][2]
		+ m1[1][1] * m2[1][2] + m1[1][2] * m2[2][2];
	matrix[2][0] = m1[2][0] * m2[0][0]
		+ m1[2][1] * m2[1][0] + m1[2][2] * m2[2][0];
	matrix[2][1] = m1[2][0] * m2[0][1]
		+ m1[2][1] * m2[1][1] + m1[2][2] * m2[2][1];
	matrix[2][2] = m1[2][0] * m2[0][2]
		+ m1[2][1] * m2[1][2] + m1[2][2] * m2[2][2];
}

void	matrix_dup(long double dst[3][3], long double src[3][3])
{
	dst[0][0] = src[0][0];
	dst[0][1] = src[0][1];
	dst[0][2] = src[0][2];
	dst[1][0] = src[1][0];
	dst[1][1] = src[1][1];
	dst[1][2] = src[1][2];
	dst[2][0] = src[2][0];
	dst[2][1] = src[2][1];
	dst[2][2] = src[2][2];
}
