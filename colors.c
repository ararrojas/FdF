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
			color = ft_atoi_base(arr[1], "0123456789abcdef");
		else
			color = 0;
		color = (color << 8) | 0xff;
		color = hex_to_rgba(color);
		ft_free_array(arr);
	}
	else
		color = hex_to_rgba(0x000000FF);
	return (color);
}
