/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arojas-a <arojas-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:36:45 by arojas-a          #+#    #+#             */
/*   Updated: 2024/09/13 14:58:26 by arojas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	count_cols(char *line, char space)
{
	int	i;
	int	cols;

	i = 0;
	cols = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == space)
		{
			while (line[i] && (line[i] == space || line[i] == '\n'))
				i++;
		}
		else
		{
			while (line[i] && line[i] != space)
				i++;
			cols++;
		}
	}
	ft_printf(".");
	return (cols);
}

t_map	*map_init(void)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	map->width = 0;
	map->height = 0;
	map->len = 0;
	map->min_z = INT_MAX;
	map->max_z = INT_MIN;
	map->points = NULL;
	return (map);
}

