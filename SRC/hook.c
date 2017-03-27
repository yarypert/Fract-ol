/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 08:23:10 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/27 18:59:38 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int keycode, t_ptr *ptr)
{
	if (keycode == 53 || keycode == 65307)
		exit(0);
	if (keycode == 123)
		ptr->offsetX -= 0.1;
	if (keycode == 124)
		ptr->offsetX += 0.1;
	if (keycode == 125)
		ptr->offsetY -= 0.1;
	if (keycode == 126)
		ptr->offsetY += 0.1;
	if (keycode == 2)
		ptr->drugs++;
	if (keycode == 1)
	{
		if(ptr->toggle == 1)
			ptr->toggle = 0;
		else if (ptr->toggle == 0)
			ptr->toggle = 1;
	}
	key_hook2(keycode, ptr);
	refresh(ptr);
	return (0);
}

int		key_hook2(int keycode, t_ptr *ptr)
{
	if (keycode == 83)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		dispatch("1", *ptr);
	}
	if (keycode == 84)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		dispatch("2", *ptr);
	}
	if (keycode == 85)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		dispatch("3", *ptr);
	}
	if (keycode == 86)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		dispatch("4", *ptr);
	}
	return(0);
}





int		mouse(int	keycode, int x, int y, t_ptr *ptr)
{
	if (keycode == 4 || keycode == 2)
	{
		ptr->offsetX -= x * ptr->zoom / SIZE_X;
		ptr->offsetY -= y * ptr->zoom / SIZE_Y;
		ptr->zoom *= 2;
	}
	if (keycode == 5 || keycode == 1)
	{
		ptr->offsetX += x * ptr->zoom / 2 / SIZE_X;
		ptr->offsetY += y * ptr->zoom / 2 / SIZE_Y;
		ptr->zoom /= 2;
	}
	refresh(ptr);
	return(0);
}


int		frc_mouse_manager(int x, int y, t_ptr *ptr)
{
	if (ptr->toggle == 0)
	{
	ptr->coordX = x;
	ptr->coordY = y;
	ptr->jucst = ((1.0 / (SIZE_X / 2)) * ptr->coordX) - 1.0;
	ptr->jucst2 = ((1.0 / (SIZE_Y / 2)) * ptr->coordY) - 1.0;
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

int		exit_cross(void)
{
	exit(0);
	return (0);
}

int		refresh(t_ptr *ptr)
{
	mlx_destroy_image(ptr->mlx, ptr->img);
	ptr->img = mlx_new_image(ptr->mlx , SIZE_X, SIZE_Y);
	ptr->bts = mlx_get_data_addr(ptr->img, &(ptr->bpp), &(ptr->size_line),
			&(ptr->endian));
	if (ptr->select == 1)
		mandelbrot(ptr, 1);
	else if (ptr->select == 2)
		julia(ptr);
	else if(ptr->select == 3)
		mandelbrot(ptr, -1);
	else if(ptr->select == 4)
		mandelbrot(ptr, -1);
	menu_border(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img,0 ,0);
	menu_strings(ptr);
	return(0);
}
