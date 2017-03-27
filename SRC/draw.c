/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 08:14:33 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/27 18:59:13 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_ptr ptr)
{
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, SIZE_X, SIZE_Y, ptr.param);
	mlx_hook(ptr.win, 17, (1L << 17), exit_cross, &ptr);
	mlx_hook(ptr.win, 2, (1L << 0), key_hook, &ptr);
	mlx_hook(ptr.win, 6, (1L << 6), frc_mouse_manager, &ptr);
	mlx_mouse_hook(ptr.win, mouse, &ptr);
	ptr.img = mlx_new_image(ptr.mlx, SIZE_X, SIZE_Y);
	ptr.bts = mlx_get_data_addr(ptr.img, &(ptr.bpp), &(ptr.size_line),
			&(ptr.endian));
	if (ptr.select == 1)
		mandelbrot(&ptr, 1);
	else if (ptr.select == 2)
		julia(&ptr);
	else if (ptr.select == 3)
		mandelbrot(&ptr, -1);
	else if (ptr.select == 4)
		mandelbrot(&ptr, -1);
	menu(&ptr);
	mlx_put_image_to_window(ptr.mlx, ptr.win, ptr.img, 0, 0);
	menu_strings(&ptr);
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
	ptr.param = str;
	if (ft_strcmp(str, "Mandelbrot") == 0 || ft_strcmp(str, "1") == 0)
	{
		ptr.select = 1;
		draw(ptr);
	}
	else if (ft_strcmp(str, "Julia") == 0 || ft_strcmp(str, "2") == 0)
	{
		ptr.select = 2;
		draw(ptr);
	}
	else if (ft_strcmp(str, "Trihorn") == 0 || ft_strcmp(str, "3") == 0)
	{
		ptr.select = 3;
		draw(ptr);
	}
	else if (ft_strcmp(str, "BurningShips") == 0 || ft_strcmp(str, "4") == 0)
		{
		ptr.select = 1;
		ptr.burn = 1;
		draw(ptr);
		}
	else
		ft_error("usage : <Fractal Name>\n1 >> Mandelbrot\n2 >> Julia\n\
			3 >> Trihorn\n4 >> BurningShips\n");
}
