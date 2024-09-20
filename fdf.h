/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arojas-a <arojas-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:27:20 by arojas-a          #+#    #+#             */
/*   Updated: 2024/09/13 16:53:03 by arojas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include "lib/MLX42/include/MLX42/MLX42.h"
# include "lib/libft/libft.h"

# define WIDTH 1200
# define HEIGHT 1000

/* Error messages */

# define ERR_FILEEXT		"ERROR: file extension must be .fdf"
# define ERR_FILEOPEN		"ERROR: file could not be open"
# define ERR_MAPWIDTH		"ERROR: map width must be equal on all lines"
# define ERR_MAPNOTVALID	"ERROR: map could not be parsed"
# define ERR_MAPEMPTY		"ERROR: map is empty"

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
	uint32_t	color;
}	t_point;

typedef struct	s_map
{
	unsigned int	width;
	unsigned int	height;
	unsigned int	len;
	int		min_z;
	int		max_z;
	t_point		*point;
}	t_map;

typedef struct	s_cam
{
	int	projection;
	float	zoom;
	double	z_scale;
	int	offset_x;
	int	offset_y;
}	t_cam;

typedef struct s_fdf
{
	t_map		*map;
	t_cam		*cam;
	mlx_t		*mlx;
	mlx_image_t	*image;
	mlx_image_t	*help;
	int		help_on;
}	t_fdf;

typedef struct	s_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	error;
	int	steps;
	int	init_x;
	int	init_y;
}	t_bresenham;

enum	e_projections
{
	ISOMETRIC,
};

// map
int		count_cols(char *line, char space);
t_map	*map_init(void);

// parse
void	map_fill(char *file, t_map *map);
int		valid_filename(char *file);
void	map_load(char *file, t_map *map);

// error
void	ft_exit(char *str);

#endif
