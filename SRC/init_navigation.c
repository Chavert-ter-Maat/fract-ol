/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_navigation.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/14 11:43:17 by cter-maa      #+#    #+#                 */
/*   Updated: 2025/02/22 18:40:31 by chavertterm   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_navigation_mandelbrot(t_fractol *generate)
{
	ft_bzero(&generate->nav, sizeof(&generate->nav));
	generate->nav.zoom_factor = 0.9;
	generate->nav.zoom = 1.0;
	generate->nav.nav_step = 0.1;
	generate->nav.x_nav = 0.0;
	generate->nav.y_nav = 0.0;
}

void	init_navigation_julia(t_fractol *generate)
{
	ft_bzero(&generate->nav, sizeof(&generate->nav));
	generate->nav.zoom_factor = 0.9;
	// generate->nav.zoom_in = 1.0;
	// generate->nav.zoom_out = 1.0;
	generate->nav.zoom = 1.0;
	generate->nav.nav_step = 0.1;
	generate->nav.x_nav = 0.0;
	generate->nav.y_nav = 0.0;
	generate->nav.c_real = -0.8;
	generate->nav.c_imag = 0.156;
}

void	init_navigation_burningship(t_fractol *generate)
{
	ft_bzero(&generate->nav, sizeof(&generate->nav));
	generate->nav.zoom_factor = 0.9;
	generate->nav.zoom = 1.0;
	generate->nav.nav_step = 0.1;
	generate->nav.x_nav = 0.0;
	generate->nav.y_nav = 0.0;
}
