/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 08:14:33 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/30 19:40:01 by yarypert         ###   ########.fr       */
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
	ptr.offset_x = -2.0;
	ptr.offset_y = -2.0;
	ptr.zoom = 4.0;
	select_draw(ptr);
	if (ptr.menu_toggle == 1)
		menu(&ptr);
	mlx_put_image_to_window(ptr.mlx, ptr.win, ptr.img, 0, 0);
	if (ptr.menu_toggle == 1)
		menu_strings(&ptr);
	mlx_loop(ptr.mlx);
}

void	select_draw(t_ptr ptr)
{
	if (ptr.select == 1)
		mandelbrot(&ptr);
	else if (ptr.select == 2)
		julia(&ptr);
	else if (ptr.select == 3)
		mandelbrot(&ptr);
	else if (ptr.select == 4)
		mandelbrot(&ptr);
	else if (ptr.select == 5)
		julia(&ptr);
	else if (ptr.select == 6)
		julia(&ptr);
	else if (ptr.select == 7)
		rose(&ptr);
	else if (ptr.select == 8)
		rorschach(&ptr);
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
