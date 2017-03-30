/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:25:40 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/30 19:52:36 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	dispatch(char *str, t_ptr ptr)
{
	ptr.param = str;
	if (ft_strcmp(str, "Mandelbrot") == 0 || ft_strcmp(str, "1") == 0)
	{
		ptr.select = 1;
		ptr.burn = 0;
		ptr.horn = 1;
		draw(ptr);
	}
	else if (ft_strcmp(str, "Julia") == 0 || ft_strcmp(str, "2") == 0)
	{
		ptr.select = 2;
		ptr.judelbrotia = 0;
		ptr.spike = 2;
		draw(ptr);
	}
	dispatch2(str, ptr);
	dispatch3(str, ptr);
	if (ptr.sound == 1)
		system("killall afplay");
	ft_error("usage : <Fractal Name>\n1 >> Mandelbrot\n2 >> Julia\n\
3 >> Trihorn\n4 >> BurningShips\n5 >> Judelbrotia\n6 >> Spike\n7 >> Rose\n\
8 >> Rorschach\n");
}

void	dispatch2(char *str, t_ptr ptr)
{
	if (ft_strcmp(str, "Trihorn") == 0 || ft_strcmp(str, "3") == 0)
	{
		ptr.select = 3;
		ptr.burn = 0;
		ptr.horn = -1;
		draw(ptr);
	}
	else if (ft_strcmp(str, "BurningShips") == 0 || ft_strcmp(str, "4") == 0)
	{
		ptr.select = 4;
		ptr.burn = 1;
		ptr.horn = 1;
		draw(ptr);
	}
	else if (ft_strcmp(str, "Judelbrotia") == 0 || ft_strcmp(str, "5") == 0)
	{
		ptr.select = 5;
		ptr.judelbrotia = 1;
		ptr.spike = 2;
		draw(ptr);
	}
}

void	dispatch3(char *str, t_ptr ptr)
{
	if (ft_strcmp(str, "Spike") == 0 || ft_strcmp(str, "6") == 0)
	{
		ptr.select = 6;
		ptr.judelbrotia = 0;
		ptr.spike = 5;
		draw(ptr);
	}
	if (ft_strcmp(str, "Rose") == 0 || ft_strcmp(str, "7") == 0)
	{
		ptr.select = 7;
		draw(ptr);
	}
	if (ft_strcmp(str, "Rorschach") == 0 || ft_strcmp(str, "8") == 0)
	{
		ptr.select = 8;
		draw(ptr);
	}
}
