/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 08:14:33 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/22 10:16:44 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(char *str, t_ptr ptr)
{
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, SIZE_X, SIZE_Y, str);
	mlx_hook(ptr.win, 17, (1L << 17), exit_cross, &ptr);
	mlx_hook(ptr.win, 2, (1L << 0), key_hook, &ptr);
	ptr.img = mlx_new_image(ptr.mlx, SIZE_X, SIZE_Y);
	ptr.bts = mlx_get_data_addr(ptr.img, &(ptr.bpp), &(ptr.size_line),
			&(ptr.endian));
	menu(&ptr);
	mlx_put_image_to_window(ptr.mlx, ptr.win, ptr.img, 0, 0);
	mlx_loop(ptr.mlx);
}

void	mlx_pix_img(t_ptr *ptr, int x, int y, int color)
{
	int r;
	int g;
	int b;

	r = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	b = (color & 0xFF);
	if (y >= 0 && x >= 0 && y < SIZE_Y && x < SIZE_X)
	{
		ptr->bts[(y * ptr->size_line) + ((ptr->bpp / 8) * x) + 2] = r;
		ptr->bts[(y * ptr->size_line) + ((ptr->bpp / 8) * x) + 1] = g;
		ptr->bts[(y * ptr->size_line) + ((ptr->bpp / 8) * x)] = b;
	}
}

void	dispatch(char *str, t_ptr ptr)
{
	ptr.init = 0;
	/*if (ft_strcmp(str, "Mandelbrot") == 0)
		Mandelbrot();
	else if (ft_strcmp(str, "Julia") == 0)
		Julia();*/
	draw(str, ptr);
}
