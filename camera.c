/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arojas-a <arojas-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:49:40 by arojas-a          #+#    #+#             */
/*   Updated: 2024/09/10 15:38:13 by arojas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	init_cam(t_fdf *fdf)
{
	fdf->cam = ft_calloc(1, sizeof(t_cam));
	fdf->cam->projection = ISOMETRIC;
	fdf->cam->zoom = fminf((WIDTH / fdf->map->width), (HEIGHT / fdf->map->height)) / 2;
	fdf->cam->z_scale = 1;
	fdf->cam->offset_x = 0;
	fdf->cam->offset_y = 0;
}

void	reset_cam(t_fdf *fdf)
{
	fdf->cam->zoom = fminf((WIDTH / fdf->map->width), (HEIGHT / fdf->map->height)) / 2;
	fdf->cam->z_scale = 1;
	fdf->cam->offset_x = 0;
	fdf->cam->offset_y = 0;
}
