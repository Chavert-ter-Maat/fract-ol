/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/06 11:23:20 by cter-maa      #+#    #+#                 */
/*   Updated: 2025/02/22 18:02:07 by chavertterm   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// header
#ifndef FRACTOL_H
# define FRACTOL_H

// includes
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include "libft.h"
# include "ft_printf.h"
# include "MLX42.h"

// defines
# define WIDTH 		500
# define HEIGHT		500
# define CORRECT	0

typedef enum e_choice
{
	MANDELBROT,
	JULIA,
	BURNINGSHIP,
}	t_choice;

// structures

typedef struct s_mods
{
	int		width;
	int		height;
	int		max_iter;
	double	zoom;
	double	x_offset;
	double	y_offset;
}	t_mods;

typedef struct s_screen
{
	double		min_x;
	double		max_x;
	double		min_y;
	double		max_y;
}	t_screen;

typedef struct 	s_fractol
{		
	mlx_image_t			*image;
	mlx_t				*mlx;
	t_screen			screen;
	t_mods				mods;
	int					choice;
	char				**argv;
} 	t_fractol;

// coloring

// hooks
void	ft_hook(void* param);

// fractals
void	init_mandelbrot(t_fractol *generate);
void	init_burningship(t_fractol *generate);

// initialize mlx
void	init_mlx(t_fractol *generate);
void	open_screen(t_fractol *generate);
void	new_image(t_fractol *generate);
void 	init_fractal(t_fractol	*generate);
void	image_to_window(t_fractol *generate);
void	hooks(t_fractol *generate);

// initialize parameters
void	init_param(t_fractol *generate, char *argv);
void	init_type(t_fractol *generate, char *argv);
void	init_screen_settings(t_screen *screen);
void	init_mods(t_mods *mods);

// main
void	put_pixel(void* param);

#endif
