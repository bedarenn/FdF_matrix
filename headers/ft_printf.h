/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:51:35 by bedarenn          #+#    #+#             */
/*   Updated: 2023/11/20 22:41:52 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_fprintf(int fd, const char *format, ...);
int	ft_vprintf(const char *format, va_list arg);
int	ft_vfprintf(int fd, const char *format, va_list arg);

int	ft_printf_arg(int fd, char format, va_list arg);

int	ft_printf_char_fd(char c, int fd);
int	ft_printf_str_fd(char *s, int fd);

int	ft_printf_unbr_base_fd(unsigned int n, char *base, size_t size, int fd);
int	ft_printf_snbr_base_fd(int n, char *base, size_t size, int fd);
int	ft_printf_ptr_fd(void *ptr, int fd);

#endif