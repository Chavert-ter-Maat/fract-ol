/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractal_burning_ship.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/14 13:16:24 by cter-maa      #+#    #+#                 */
/*   Updated: 2025/02/22 18:40:31 by chavertterm   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	iterations(int iter, double real, double imag)
{
	double	z_real;
	double	z_imag;
	double	next_z_real;
	double	next_z_imag;

	z_real = real;
	z_imag = imag;
	iter = 0;
	while (iter < MAX_ITTER && (z_real * z_real + z_imag * z_imag) <= 4.0)
	{
		next_z_imag = fabs(2 * z_real * z_imag) + imag;
		next_z_real = z_real * z_real - z_imag * z_imag + real;
		z_real = next_z_real;
		z_imag = next_z_imag;
		iter++;
	}
	return (iter);
}

static void	put_pixel_x(int y, t_fractol *gen)
{
	double	c_real;
	double	c_imag;
	int		iter;
	int		x;

	x = 0;
	iter = 0;
	while (x < WIDTH)
	{
		c_real = gen->screen.min_x + x * gen->nav.x_offset + gen->nav.x_nav;
		c_imag = gen->screen.min_y + y * gen->nav.y_offset + gen->nav.y_nav;
		iter = iterations(iter, c_real, c_imag);
		get_color(gen, x, y, iter);
		x++;
	}
}

void	burningship(t_fractol *generate)
{
	int			y;	
	t_screen	screen;

	y = 0;
	screen = generate->screen;
	generate->nav.x_offset = (screen.max_x - screen.min_x) / WIDTH;
	generate->nav.y_offset = (screen.max_y - screen.min_y) / HEIGHT;
	while (y < HEIGHT)
	{
		put_pixel_x(y, generate);
		y++;
	}
}
