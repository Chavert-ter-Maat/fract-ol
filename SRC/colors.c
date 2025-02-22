/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/04 16:47:23 by cter-maa      #+#    #+#                 */
/*   Updated: 2025/02/22 18:40:31 by chavertterm   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color_set(t_fractol *generate, int iter)
{
	int	layer;
	int	layer_range;

	layer_range = MAX_ITTER / NUM_LAYERS;
	layer = iter / layer_range;
	if (iter == MAX_ITTER)
		return (generate->colors.black);
	if (layer == 0)
		return (generate->colors.color_set1);
	if (layer == 1)
	{
		if (generate->colors.color_type == TRIPPY)
			return (generate->colors.color_set2 = ft_randomize(generate));
		else
			return (generate->colors.color_set2);
	}
	if (layer == 2)
		return (generate->colors.color_set3);
	if (layer == 3)
		return (generate->colors.color_set4);
	if (layer == 4)
		return (generate->colors.color_set5);
	if (layer == 5)
		return (generate->colors.color_set6);
	return (generate->colors.black);
}

void	get_color(t_fractol *generate, int x, int y, int iter)
{
	int	color;

	color = get_color_set(generate, iter);
	mlx_put_pixel(generate->image, x, y, color);
}

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int32_t	ft_pixel_burning(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 25 | b << 24 | a);
}

uint32_t	ft_randomize(t_fractol *generate)
{
	uint32_t	color;

	if (generate->fractal_type == BURNINGSHIP)
	{
		color = ft_pixel_burning(
				rand() % 0xFF,
				rand() % 0xFF,
				rand() % 0xFF,
				rand() % 0xFF);
	}
	else
	{
		color = ft_pixel(
				rand() % 0xFF,
				rand() % 0xFF,
				rand() % 0xFF,
				rand() % 0xFF);
	}
	return (color);
}
