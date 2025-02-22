/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_fractal.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/22 10:31:19 by cter-maa      #+#    #+#                 */
/*   Updated: 2025/02/22 18:40:31 by chavertterm   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal_settings(t_fractol *generate, char **argv)
{
	ft_bzero(generate, sizeof(*generate));
	init_fractal_type(generate, argv[1]);
	init_color_type(&generate->colors, argv[2]);
	if (generate->fractal_type == MANDELBROT)
	{
		init_navigation_mandelbrot(generate);
		init_screen_settings_mandelbrot(&generate->screen);
	}
	else if (generate->fractal_type == JULIA)
	{
		init_navigation_julia(generate);
		init_screen_settings_julia(&generate->screen);
	}	
	else if (generate->fractal_type == BURNINGSHIP)
	{
		init_navigation_burningship(generate);
		init_screen_settings_burningship(&generate->screen);
	}
}

void	reset_fractol_settings(t_fractol *generate)
{
	if (generate->fractal_type == MANDELBROT)
	{
		init_navigation_mandelbrot(generate);
		init_screen_settings_mandelbrot(&generate->screen);
	}
	else if (generate->fractal_type == JULIA)
	{
		init_navigation_julia(generate);
		init_screen_settings_julia(&generate->screen);
	}	
	else if (generate->fractal_type == BURNINGSHIP)
	{
		init_navigation_burningship(generate);
		init_screen_settings_burningship(&generate->screen);
	}
}

void	init_fractal_type(t_fractol *generate, char *argv)
{
	if (ft_strncmp(argv, "mandelbrot", 11) == CORRECT)
		generate->fractal_type = MANDELBROT;
	else if (ft_strncmp(argv, "julia", 6) == CORRECT)
		generate->fractal_type = JULIA;
	else if (ft_strncmp(argv, "burningship", 12) == CORRECT)
		generate->fractal_type = BURNINGSHIP;
	else
	{
		error_message();
		exit (EXIT_FAILURE);
	}
}
