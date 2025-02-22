/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_colors.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/14 11:34:23 by cter-maa      #+#    #+#                 */
/*   Updated: 2025/02/22 18:40:31 by chavertterm   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_normal(t_colors *colors)
{
	colors->color_set1 = 0xF5DEB3FF;
	colors->color_set2 = 0xE6E6FAFF;
	colors->color_set3 = 0xD2B48CFF;
	colors->color_set4 = 0xFAEBD7FF;
	colors->color_set5 = 0xCDCDCDFF;
	colors->color_set6 = 0xFFF8DCFF;
}

void	init_rainbow(t_colors *colors)
{
	colors->color_set1 = 0xFFC300FF;
	colors->color_set2 = 0xFF5733FF;
	colors->color_set3 = 0xFFC300FF;
	colors->color_set4 = 0xC70039FF;
	colors->color_set5 = 0x900C3FFF;
	colors->color_set6 = 0x00A8C6FF;
}

void	init_trippy(t_colors *colors)
{
	colors->color_set1 = colors->black;
	colors->color_set2 = colors->black;
	colors->color_set3 = colors->black;
	colors->color_set4 = colors->black;
	colors->color_set5 = colors->black;
	colors->color_set6 = colors->black;
}

void	init_color_type(t_colors *colors, char *argv)
{
	ft_bzero(colors, sizeof(colors));
	colors->black = 0x00000FF;
	if (ft_strncmp(argv, "normal", 7) == CORRECT)
	{
		colors->color_type = NORMAL;
		init_normal(colors);
	}
	else if (ft_strncmp(argv, "rainbow", 8) == CORRECT)
	{
		colors->color_type = RAINBOW;
		init_rainbow(colors);
	}
	else if (ft_strncmp(argv, "trippy", 7) == CORRECT)
	{
		colors->color_type = TRIPPY;
		init_trippy(colors);
	}
	else
	{
		error_message();
		exit (EXIT_FAILURE);
	}
}
