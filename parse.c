/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arojas-a <arojas-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:33:54 by arojas-a          #+#    #+#             */
/*   Updated: 2024/09/13 16:55:58 by arojas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	parse_line(char *line, t_map *map, int	line_n)
{
	char	**cols;
	int		i;
	int		start;

	i = 0;
	start = line_n * map->width;
	cols = ft_split(line, ' ');
	ft_printf("#");
	while (cols[i] && cols[i][0] != '\n')
	{
		map->point[start + 1].x = i;
	}
}

void	map_fill(char *file, t_map *map)
{
	unsigned int	i;
	int				fd;
	char			*line;

	i = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	ft_printf("\nFilling map points ->\n");
	while (line)
	{
		parse_line(line, map, i);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	ft_printf("\n");
	free(line);
	close(fd);
}

int	valid_filename(char *file)
{
	int	fd;

	if (!ft_strnstr(file, ".fdf"), ft_strlen(file))
		ft_exit(ERR_FILEEXT);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_exit(ERR_FILEOPEN);
	ft_printf("\nCalculating map size...\n");
	return (fd);	
}

void	map_load(char *file, t_map *map)
{
	unsigned int	width;
	char			*line;
	int				fd;

	fd = valid_filename(file);
	line = get_next_line(fd);
	ft_printf("\nLoading map -> \n");
	while (line)
	{
		width = count_cols(line, ' ');
		free(line);
		if (map->height == 0)
			map->width = width;
		if (map->width != width)
			ft_error(ERR_MAPWIDTH);
		map->height++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	map->len = map->height * map-width;
	if (map->len == 0)
		ft_exit(ERR_MAPEMPTY);
	map->point = ft_calloc(map->len, sizeof(t_point));
	map_fill(file, map);
}
