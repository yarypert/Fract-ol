/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 16:56:01 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/30 19:58:29 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		exit_cross(void)
{
	system("killall afplay");
	exit(0);
	return (0);
}

int		refresh(t_ptr *ptr)
{
	mlx_destroy_image(ptr->mlx, ptr->img);
	ptr->img = mlx_new_image(ptr->mlx, SIZE_X, SIZE_Y);
	ptr->bts = mlx_get_data_addr(ptr->img, &(ptr->bpp), &(ptr->size_line),
			&(ptr->endian));
	if (ptr->select == 1)
		mandelbrot(ptr);
	else if (ptr->select == 2)
		julia(ptr);
	else if (ptr->select == 3)
		mandelbrot(ptr);
	else if (ptr->select == 4)
		mandelbrot(ptr);
	refresh2(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	if (ptr->menu_toggle == 1)
		menu_strings(ptr);
	return (0);
}

int		refresh2(t_ptr *ptr)
{
	if (ptr->select == 5)
		julia(ptr);
	else if (ptr->select == 6)
		julia(ptr);
	else if (ptr->select == 7)
		rose(ptr);
	else if (ptr->select == 8)
		rorschach(ptr);
	if (ptr->menu_toggle == 1)
		menu(ptr);
	return (0);
}

int		frc_mouse_manager(int x, int y, t_ptr *ptr)
{
	if (ptr->toggle == 0)
	{
		ptr->coord_x = x;
		ptr->coord_y = y;
		ptr->jucst = ((1.0 / (SIZE_X / 2)) * ptr->coord_x) - 1.0;
		ptr->jucst2 = ((1.0 / (SIZE_Y / 2)) * ptr->coord_y) - 1.0;
		if (x > SIZE_X)
			ptr->jucst = 1;
		if (x < 0)
			ptr->jucst = -1;
		if (y < 0)
			ptr->jucst2 = -1;
		if (y > SIZE_Y)
			ptr->jucst2 = 1;
	}
	refresh(ptr);
	return (0);
}
