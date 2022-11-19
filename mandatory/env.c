/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:42:42 by salee2            #+#    #+#             */
/*   Updated: 2022/11/19 20:42:44 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_env(const char *name, char **env)
{
	while (*env)
	{
		if (ft_strncmp(name, *env, ft_strlen(name)) == 0)
			return (*(env) + ft_strlen(name) + 1);
		++env;
	}
	return (NULL);
}

char	**get_env_list(const char *name, char **env)
{
	return (ft_split(ft_get_env(name, env), ':'));
}

char	**get_file_list(const char *name, char **env, char *file_name)
{
	int		i;
	char	**file_list;

	file_list = get_env_list(name, env);
	i = -1;
	while (file_list[++i])
	{
		file_list[i] = ft_strjoin(file_list[i], "/");
		file_list[i] = ft_strjoin(file_list[i], file_name);
	}
	return (file_list);
}
