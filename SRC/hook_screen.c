/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_screen.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 11:31:11 by cter-maa      #+#    #+#                 */
/*   Updated: 2025/02/22 18:40:31 by chavertterm   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_fractol *generate)
{
	open_screen(generate);
	new_image(generate);
	image_to_window(generate);
	hooks(generate);
}

void	open_screen(t_fractol *generate)
{
	generate->mlx = mlx_init(WIDTH, HEIGHT, "FRACT-OL", true);
	if (generate->mlx == NULL)
	{
		puts(mlx_strerror(mlx_errno));
		exit (EXIT_FAILURE);
	}
}

void	new_image(t_fractol *generate)
{
	generate->image = mlx_new_image(generate->mlx, WIDTH, HEIGHT);
	if (generate->image == NULL)
	{
		mlx_close_window(generate->mlx);
		puts(mlx_strerror(mlx_errno));
		exit (EXIT_FAILURE);
	}
}

void	image_to_window(t_fractol *generate)
{
	if (mlx_image_to_window(generate->mlx, generate->image, 0, 0) == FAILURE)
	{
		mlx_delete_image(generate->mlx, generate->image);
		mlx_close_window(generate->mlx);
		puts(mlx_strerror(mlx_errno));
		exit (EXIT_FAILURE);
	}
}

void	hooks(t_fractol *generate)
{
	put_inscription(generate);
	mlx_scroll_hook(generate->mlx, &hook_scroll, generate);
	if (mlx_loop_hook(generate->mlx, hook_keys, generate) == false)
	{
		puts(mlx_strerror(mlx_errno));
		exit (EXIT_FAILURE);
	}
	mlx_loop(generate->mlx);
	mlx_terminate(generate->mlx);
}
