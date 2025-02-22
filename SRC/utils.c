/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 14:14:39 by cter-maa      #+#    #+#                 */
/*   Updated: 2025/02/22 18:40:31 by chavertterm   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	update_fractal(t_fractol *generate)
{
	if (generate->fractal_type == MANDELBROT)
		mandelbrot(generate);
	else if (generate->fractal_type == JULIA)
		julia(generate);
	else if (generate->fractal_type == BURNINGSHIP)
		burningship(generate);
}

void	put_inscription_mandelbrot_burningship(t_fractol *generate)
{
	mlx_put_string(generate->mlx, "arrow keys for navigate", 10, 10);
	mlx_put_string(generate->mlx, "'w' or scroll = zoom in", 10, 30);
	mlx_put_string(generate->mlx, "'s' or scroll = zoom out", 10, 50);
	mlx_put_string(generate->mlx, "'r' = reset fractal", 10, 70);
	mlx_put_string(generate->mlx, "'q' = shift colors", 10, 90);
}

void	put_inscription_julia(t_fractol *generate)
{
	mlx_put_string(generate->mlx, "scroll to change julia", 10, 10);
	mlx_put_string(generate->mlx, "'r' = reset fractal", 10, 30);
	mlx_put_string(generate->mlx, "'q' = shift colors", 10, 50);
}

void	put_inscription(t_fractol *generate)
{
	if (generate->fractal_type == MANDELBROT
		|| generate->fractal_type == BURNINGSHIP)
		put_inscription_mandelbrot_burningship(generate);
	else
		put_inscription_julia(generate);
}

void	error_message(void)
{
	ft_printf("---------------------------------------------------------\n");
	ft_printf("| AVAILABLE PARAMETERS FRACT-OL	                        |\n");
	ft_printf("| There are 3 inputs:                                   |\n");
	ft_printf("| 1) Executable: './fractol'                            |\n");
	ft_printf("| 2) Fractal type: 'mandelbrot' 'julia' 'burningship'   |\n");
	ft_printf("| 3) Color type: 'normal' 'rainbow' 'trippy'            |\n");
	ft_printf("---------------------------------------------------------\n");
}
