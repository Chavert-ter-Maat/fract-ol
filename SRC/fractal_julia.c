/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractal_julia.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/10 12:17:29 by cter-maa      #+#    #+#                 */
/*   Updated: 2025/02/22 18:40:31 by chavertterm   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	iterations(t_nav *nav, double z_real, double z_imag)
{
	int		iter;
	double	nxt_real;
	double	next_z_imag;

	iter = 0;
	while (iter < MAX_ITTER && (z_real * z_real + z_imag * z_imag) <= 4.0)
	{
		nxt_real = z_real * z_real - z_imag * z_imag
			+ nav->c_real + nav->nav_step;
		next_z_imag = 2 * z_real * z_imag + nav->c_imag + nav->nav_step;
		z_real = nxt_real;
		z_imag = next_z_imag;
		iter++;
	}
	return (iter);
}

static void	put_pixel_x(int y, t_fractol *generate)
{
	double	z_real;
	double	z_imag;
	int		x;
	int		iter;

	x = 0;
	while (x < WIDTH)
	{
		z_real = generate->screen.min_x + x * generate->nav.x_offset;
		z_imag = generate->screen.min_y + y * generate->nav.y_offset;
		iter = iterations(&generate->nav, z_real, z_imag);
		get_color(generate, x, y, iter);
		x++;
	}
}

void	julia(t_fractol *generate)
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
