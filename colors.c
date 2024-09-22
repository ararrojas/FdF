/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arojas-a <arojas-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:04:29 by arojas-a          #+#    #+#             */
/*   Updated: 2024/09/13 12:39:11 by arojas-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	interpolate(int a, int b, float factor)
{
	return (a * (1 - factor) + (b * factor));
}

uint32_t	interpolate_color(t_point p0, t_point p1, t_bresenham br)
{
	int		r;
	int		g;
	int		b;
	int		a;
	float	step;

	if (p0.color == p1.color)
		return (p0.color);
	step = (float)(p0.x - br.init_x) / (float)(p1.x - br.init_x);
	r = interpolate((p0.color >> 24) & 0xFF, (p1.color >> 24) & 0xFF, step);
	g = interpolate((p0.color >> 16) & 0xFF, (p1.color >> 16) & 0xFF, step);
	b = interpolate((p0.color >> 8) & 0xFF, (p1.color >> 8) & 0xFF, step);
	a = interpolate(p0.color & 0xFF, p1.color & 0xFF, step);
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

uint32_t	hex_to_rgba(unsigned int hex)
{
	int	r;
	int	g;
	int	b;
	int	a;

	r = (hex >> 24) & 0xFF;
	g = (hex >> 16) & 0xFF;
	b = (hex >> 8) & 0xFF;
	a = hex & 0xFF;

	return ((r << 24) | (g << 16) | (b << 8) | a);
}

uint32_t	get_color(char *line)
{
	char		**arr;
	uint32_t	color;

	if (ft_strchr(line, ',') != NULL)
	{
		arr = ft_split(line, ',');
		if (arr && arr[1])
		{
			color = ft_atoi_base(arr[1], "0123456789abcdef");
			color = (color << 8) | 0xff;
		}
		else
			color = 0;
		color = hex_to_rgba(color);
		ft_free_array(arr);
	}
	else
		color = hex_to_rgba(0xb530d9ff);
	return (color);
}
