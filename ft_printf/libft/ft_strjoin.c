/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2n@student.42seoul.k>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:13:59 by salee2            #+#    #+#             */
/*   Updated: 2022/07/11 18:02:39 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	s1len;
	size_t	s2len;

	if (s1 == 0 && s2 == 0)
		return (0);
	s1len = 0;
	s2len = 0;
	if (s1 != 0)
		s1len = ft_strlen(s1);
	if (s2 != 0)
		s2len = ft_strlen(s2);
	ret = (char *) malloc(s1len + s2len + 1);
	if (ret == 0)
		return (0);
	ft_memmove(ret, s1, s1len);
	ft_memmove(ret + s1len, s2, s2len);
	ret[s1len + s2len] = '\0';
	return (ret);
}
