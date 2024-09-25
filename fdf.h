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
# define TRANSLATE 5

// Error messages

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
	mlx_image_t	*img;
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
void	parse_line(char *line, t_map *map, int line_n);
void	map_fill(char *file, t_map *map);
int		valid_filename(char *file);
void	map_load(char *file, t_map *map);

// colors
int			interpolate(int a, int b, float factor);
uint32_t	interpolate_color(t_point p0, t_point p1, t_bresenham br);
uint32_t	hex_to_rgba(unsigned int hex);
uint32_t	get_color(char *line);

// camera
void	init_cam(t_fdf *fdf);
void	reset_cam(t_fdf *fdf);

// drawing
void	init_bresenham(t_point p0, t_point p1, t_bresenham *br);
void	bresenham(t_point p0, t_point p1, mlx_image_t *img);
void	background(mlx_image_t *img);
void	draw_map(t_fdf *fdf);

// graphics
int	pixel_limits(t_point *point);
t_point	project_pt(t_point pt, t_fdf *fdf);

// hooks
void	attach_hooks(t_fdf *fdf);
void	exit_esc(void *param);
void	translate(void *param);
void	zoom_hook(void *param);

// helpers
void	map_free(t_map *map);
void	ft_free_array(char **array);
void	ft_exit(char *str);

#endif
