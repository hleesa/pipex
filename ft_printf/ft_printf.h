/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 20:01:24 by salee2            #+#    #+#             */
/*   Updated: 2022/08/06 11:05:42 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# define FD STDERR_FILENO
# define HEX_LEN 19

ssize_t	c_func(va_list ap);
ssize_t	s_func(va_list ap);
ssize_t	p_func(va_list ap);
ssize_t	d_func(va_list ap);
ssize_t	i_func(va_list ap);
ssize_t	u_func(va_list ap);
ssize_t	xl_func(va_list ap);
ssize_t	xu_func(va_list ap);
ssize_t	percent_func(va_list ap);
void	set_func_num(int *to_func_num);
void	set_num_to_func(ssize_t	(*num_to_func[9])());
int		is_error(const char *format, int *to_func_num);
int		print_format(const char *format, va_list ap, \
		int *to_func_num, ssize_t (*num_to_func[9])(va_list));
char	*ft_utoa(unsigned int n);
char	*itoh(unsigned long long num, const char *to_hex, int is_addr);
int		ft_printf(const char *format, ...);

#endif //FT_PRINTF_H
