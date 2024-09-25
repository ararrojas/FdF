/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arojas-a <arojas-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:50:09 by arojas-a          #+#    #+#             */
/*   Updated: 2024/09/13 12:39:34 by arojas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	map_free(t_map *map)
{
	free(map->point);
	free(map);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_exit(char *str)
{
	if (errno == 0)
	{
		ft_putstr_fd("\n", 2);
		ft_putendl_fd(str, 2);
	}
	else
		perror(str);
	exit(1);
}
