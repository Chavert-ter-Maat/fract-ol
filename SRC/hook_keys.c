/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_keys.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 11:32:08 by cter-maa      #+#    #+#                 */
/*   Updated: 2025/02/22 18:40:31 by chavertterm   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hook_keys(void *param)
{
	t_fractol	*generate;

	generate = param;
	hook_navigation(generate);
	hook_zoom(generate);
	hook_colors(generate);
}

void	hook_navigation(t_fractol *generate)
{
	if (mlx_is_key_down(generate->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(generate->mlx);
	if (mlx_is_key_down(generate->mlx, MLX_KEY_UP))
		generate->nav.y_nav -= generate->nav.nav_step;
	if (mlx_is_key_down(generate->mlx, MLX_KEY_DOWN))
		generate->nav.y_nav += generate->nav.nav_step;
	if (mlx_is_key_down(generate->mlx, MLX_KEY_LEFT))
		generate->nav.x_nav -= generate->nav.nav_step;
	if (mlx_is_key_down(generate->mlx, MLX_KEY_RIGHT))
		generate->nav.x_nav += generate->nav.nav_step;
	update_fractal(generate);
}

void	hook_zoom(t_fractol *generate)
{
	if (mlx_is_key_down(generate->mlx, MLX_KEY_W))
		zoom_fractal(generate, 1);
	if (mlx_is_key_down(generate->mlx, MLX_KEY_S))
		zoom_fractal(generate, -1);
	if (mlx_is_key_down(generate->mlx, MLX_KEY_A))
		generate->nav.nav_step *= 3;
	if (mlx_is_key_down(generate->mlx, MLX_KEY_D))
		generate->nav.nav_step /= 3;
	if (mlx_is_key_down(generate->mlx, MLX_KEY_R))
	{
		reset_fractol_settings(generate);
	}
	update_fractal(generate);
}

void	hook_colors(t_fractol *generate)
{
	if (mlx_is_key_down(generate->mlx, MLX_KEY_Q))
	{
		generate->colors.color_set1 += 0x7FB3DEFF;
		generate->colors.color_set2 += 0x7FB3DEFF;
		generate->colors.color_set3 += 0x7FB3DEFF;
		generate->colors.color_set4 += 0x7FB3DEFF;
		generate->colors.color_set5 += 0x7FB3DEFF;
		generate->colors.color_set6 += 0x7FB3DEFF;
	}
	update_fractal(generate);
}
