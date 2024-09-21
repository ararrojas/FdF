/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arojas-a <arojas-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:38:36 by arojas-a          #+#    #+#             */
/*   Updated: 2024/09/10 16:21:06 by arojas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	attach_hooks(t_fdf *fdf)
{
	mlx_loop_hook(fdf->mlx, &exit_esc, fdf);
	mlx_loop_hook(fdf->mlx, &translate, fdf);
	mlx_loop_hook(fdf->mlx, &zoom_hook, fdf);
}

void	exit_esc(void *param)
{
	t_fdf	*fdf;
	fdf = param;
	
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
}

void	translate(void *param)
{
	t_fdf	*fdf;

	fdf = param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W))
		fdf->cam->offset_y -= TRANSLATE;
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
		fdf->cam->offset_y += TRANSLATE;
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_A))
		fdf->cam->offset_x -= TRANSLATE;
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_D))
		fdf->cam->offset_x += TRANSLATE;
	else
		return ;
	draw_map(fdf);
}

void	zoom_hook(void *param)
{
	t_fdf	*fdf;

	fdf = param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_1) || \
		mlx_is_key_down(fdf->mlx, MLX_KEY_2))
		reset_cam(fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_ADD))
		fdf->cam->zoom *= 1.1;
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_SUBTRACT))
		fdf->cam->zoom /= 1.1;
	else if (fdf->cam->zoom < 0.01)
		fdf->cam->zoom = 0.01;
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_U))
		fdf->cam->z_scale *= 1.1;
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_I))
		fdf->cam->z_scale /= 1.1;
	else if (fdf->cam->z_scale < 0.01)
		fdf->cam->z_scale = 0.01;
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_1))
		fdf->cam->projection = ISOMETRIC;
	else
		return ;
	draw_map(fdf);
}
