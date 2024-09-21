/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arojas-a <arojas-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:13:01 by arojas-a          #+#    #+#             */
/*   Updated: 2024/09/13 16:35:47 by arojas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int32_t	main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac != 2)
		return (1);
	fdf.map = map_init();
	map_load(av[1], fdf.map);
	fdf.mlx = mlx_init(WIDTH, HEIGHT, "FdF - arojas-a", true);
	if (!fdf.mlx)
		exit(EXIT_FAILURE);
	fdf.img = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);
	if (!fdf.img)
		exit(EXIT_FAILURE);
	init_cam(&fdf);
	//menu
	draw_map(&fdf);
	attach_hooks(&fdf);
	mlx_loop(fdf.mlx);
	mlx_terminate(fdf.mlx);
	free(fdf.cam);
	map_free(fdf.map);
	return (0);
}
