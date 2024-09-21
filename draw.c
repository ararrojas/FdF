/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arojas-a <arojas-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:49:40 by arojas-a          #+#    #+#             */
/*   Updated: 2024/09/10 15:38:13 by arojas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	init_bresenham(t_point p0, t_point p1, t_bresenham *br)
{
	if (p0.x < p1.x)
		br->sx = 1;
	else
		br->sx = -1;
	if (p0.y < p1.y)
		br->sy = 1;
	else
		br->sy = -1;
	br->dx = abs(p1.x - p0.x);
	br->dy = -abs(p1.y - p0.y);
	br->error = br->dx - br->dy;
	br->init_x = p0.x;
	br->init_y = p0.y;
}

void	bresenham(t_point p0, t_point p1, mlx_image_t *img)
{
	t_bresenham	br;

	init_bresenham(p0, p1, &br);
	while (1)
	{
		if (p0.x == p1.x && p0.y == p1.y)
			return ;
		if (pixel_limits(&p0))
			mlx_put_pixel(img, p0.x, p0.y, interpolate_color(p0, p1, br));
		if (2 * br.error >= br.dy)
		{
			if (p0.x == p1.x)
				return ;
			br.error += br.dy;
			p0.x += br.sx;
		}
		if (2 * br.error <= br.dx)
		{
			if (p0.y == p1.y)
				return ;
			br.error += br.dx;
			p0.y += br.sy;
		}
	}
}

void	clear_background(mlx_image_t *img)
{
	img->pixels = ft_memset(img->pixels, 100, img->height * img->width * 4);
}

void	draw_map(t_fdf *fdf)
{
	unsigned int	i;
	unsigned int	width;
	t_point			pt;
	t_point			*pts;

	clear_background(fdf->img);
	i = -1;
	pts = fdf->map->point;
	width = fdf->map->width;
	while(++i < fdf->map->len)
	{
		pt = project_pt(fdf->map->point[i], fdf);
		if (i % width != fdf->map->width - 1)
			bresenham(pt, project_pt(pts[i + 1], fdf), fdf->img);
		if (i + width < fdf->map->len)
			bresenham(pt, project_pt(pts[i + width], fdf), fdf->img);
	}
	mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
}
