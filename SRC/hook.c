/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 08:23:10 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/30 20:01:50 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int keycode, t_ptr *ptr)
{
	if (keycode == 53 || keycode == 65307)
	{
		system("killall afplay");
		exit(0);
	}
	if (keycode == 78)
	{
		ptr->iter = ptr->iter - 3;
		if (ptr->iter < 0)
			ptr->iter = 0;
	}
	if (keycode == 69)
		ptr->iter = ptr->iter + 3;
	if (keycode == 48)
	{
		if (ptr->menu_toggle == 1)
			ptr->menu_toggle = 0;
		else if (ptr->menu_toggle == 0)
			ptr->menu_toggle = 1;
	}
	key_hook2(keycode, ptr);
	key_hook3(keycode, ptr);
	key_hook4(keycode, ptr);
	refresh(ptr);
	return (0);
}

int		key_hook2(int keycode, t_ptr *ptr)
{
	if (keycode == 1)
	{
		if (ptr->toggle == 1)
			ptr->toggle = 0;
		else if (ptr->toggle == 0)
			ptr->toggle = 1;
	}
	if (keycode == 18)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		dispatch("Mandelbrot", *ptr);
	}
	if (keycode == 19)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		dispatch("Julia", *ptr);
	}
	if (keycode == 20)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		dispatch("Trihorn", *ptr);
	}
	return (0);
}

int		key_hook3(int keycode, t_ptr *ptr)
{
	if (keycode == 21)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		dispatch("BurningShips", *ptr);
	}
	if (keycode == 23)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		dispatch("Judelbrotia", *ptr);
	}
	if (keycode == 22)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		dispatch("Spike", *ptr);
	}
	if (keycode == 26)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		dispatch("Rose", *ptr);
	}
	return (0);
}

int		key_hook4(int keycode, t_ptr *ptr)
{
	if (keycode == 123)
		ptr->offset_x += 0.1;
	if (keycode == 124)
		ptr->offset_x -= 0.1;
	if (keycode == 125)
		ptr->offset_y -= 0.1;
	if (keycode == 126)
		ptr->offset_y += 0.1;
	if (keycode == 2)
		ptr->drugs++;
	if (keycode == 28)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		dispatch("Rorschach", *ptr);
	}
	return (0);
}

int		mouse(int keycode, int x, int y, t_ptr *ptr)
{
	if (keycode == 4 || keycode == 2)
	{
		ptr->offset_x -= x * ptr->zoom / SIZE_X;
		ptr->offset_y -= y * ptr->zoom / SIZE_Y;
		ptr->zoom *= 2;
	}
	if (keycode == 5 || keycode == 1)
	{
		ptr->offset_x += x * ptr->zoom / 2 / SIZE_X;
		ptr->offset_y += y * ptr->zoom / 2 / SIZE_Y;
		ptr->zoom /= 2;
	}
	refresh(ptr);
	return (0);
}
