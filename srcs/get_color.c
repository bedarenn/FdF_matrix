/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:52:21 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/05 18:55:06 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <ft_printf.h>

char	*skip_nb(char *str)
{
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		str++;
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
		str++;
	return (str);
}

t_color	get_color(char *str)
{
	t_color	color;

	if (!ft_strncmp(str, ",0x", 3))
		color = set_color_hex(ft_atoi_base(ft_strlower(str + 3),
					"0123456789abcdef", 16));
	else
		color = set_color_hex(0x00808080);
	return (color);
}
