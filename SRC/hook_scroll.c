/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_scroll.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 12:47:00 by cter-maa      #+#    #+#                 */
/*   Updated: 2025/02/22 18:40:31 by chavertterm   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_fractol *generate)
{
	generate->nav.zoom *= ((generate->nav.zoom_factor));
	generate->screen.min_x *= generate->nav.zoom;
	generate->screen.max_x *= generate->nav.zoom;
	generate->screen.min_y *= generate->nav.zoom;
	generate->screen.max_y *= generate->nav.zoom;
}

void	zoom_out(t_fractol *generate)
{
	generate->screen.min_x /= generate->nav.zoom;
	generate->screen.max_x /= generate->nav.zoom;
	generate->screen.min_y /= generate->nav.zoom;
	generate->screen.max_y /= generate->nav.zoom;
	generate->nav.zoom /= (generate->nav.zoom_factor);
}

void	zoom_fractal(t_fractol *generate, double y_offset)
{
	if (y_offset > 0)
	{
		generate->nav.nav_step *= generate->nav.zoom;
		zoom_in(generate);
	}
	else if (y_offset < 0)
	{
		zoom_out(generate);
		generate->nav.nav_step /= generate->nav.zoom;
	}
}

static void	scroll_julia(t_fractol *generate, double y_offset)
{
	if (y_offset > 0)
		generate->nav.nav_step += 0.01;
	else if (y_offset < 0)
		generate->nav.nav_step -= 0.01;
}

void	hook_scroll(double x_offset, double y_offset, void *param)
{
	t_fractol	*generate;

	generate = param;
	(void) x_offset;
	if (generate->fractal_type == MANDELBROT
		|| generate->fractal_type == BURNINGSHIP)
		zoom_fractal(generate, y_offset);
	else if (generate->fractal_type == JULIA)
		scroll_julia(generate, y_offset);
}
