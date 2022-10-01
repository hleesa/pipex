/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_manda_func_one.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:02:12 by salee2            #+#    #+#             */
/*   Updated: 2022/08/06 11:06:10 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	c_func(va_list ap)
{
	char	c;
	ssize_t	ret;

	c = va_arg(ap, int);
	ret = write(1, &c, 1);
	return (ret);
}

ssize_t	s_func(va_list ap)
{
	ssize_t		ret;
	const char	*str = va_arg(ap, const char *);

	if (str == NULL)
		ret = write(1, "(null)", 6);
	else
		ret = write(1, str, ft_strlen(str));
	return (ret);
}

ssize_t	d_func(va_list ap)
{
	int		d;
	ssize_t	ret;
	char	*d_str;

	d = va_arg(ap, int);
	d_str = ft_itoa(d);
	if (d_str == 0)
		return (-1);
	ret = write(1, d_str, ft_strlen(d_str));
	free(d_str);
	return (ret);
}

ssize_t	i_func(va_list ap)
{
	return (d_func(ap));
}

ssize_t	u_func(va_list ap)
{
	unsigned int	u;
	ssize_t			ret;
	char			*u_str;

	u = va_arg(ap, unsigned int);
	u_str = ft_utoa(u);
	if (u_str == 0)
		return (-1);
	ret = write(1, u_str, ft_strlen(u_str));
	free(u_str);
	return (ret);
}
