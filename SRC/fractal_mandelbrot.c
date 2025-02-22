/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractal_mandelbrot.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/16 13:05:51 by cter-maa      #+#    #+#                 */
/*   Updated: 2025/02/22 18:40:31 by chavertterm   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	iterations(int iter, double real, double imag)
{
	double	z_real;
	double	z_imag;
	double	nxt_real;
	double	next_z_imag;

	z_real = 0.0;
	z_imag = 0.0;
	iter = 0;
	while (iter < MAX_ITTER && (z_real * z_real + z_imag * z_imag) <= 4.0)
	{
		nxt_real = z_real * z_real - z_imag * z_imag + real;
		next_z_imag = 2 * z_real * z_imag + imag;
		z_real = nxt_real;
		z_imag = next_z_imag;
		iter++;
	}
	return (iter);
}

static void	put_pixel_x(int y, t_fractol *gen)
{
	double	c_real;
	double	c_imag;
	int		x;
	int		iter;

	x = 0;
	while (x < WIDTH)
	{
		c_real = gen->screen.min_x + x * gen->nav.x_offset + gen->nav.x_nav;
		c_imag = gen->screen.min_y + y * gen->nav.y_offset + gen->nav.y_nav;
		iter = iterations(iter, c_real, c_imag);
		get_color(gen, x, y, iter);
		x++;
	}
}

void	mandelbrot(t_fractol *generate)
{
	t_screen	screen;
	int			y;

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
