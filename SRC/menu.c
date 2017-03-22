/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 08:40:25 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/22 11:54:20 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	menu(t_ptr *ptr)
{
	ptr->xy = (int *)malloc(sizeof(int) * 2);
	ptr->xy2 = (int *)malloc(sizeof(int) * 2);
	menu_border(ptr);
}

void	line_menu(t_ptr *ptr,int color)
{
	t_init i;

	line_init(&i, *ptr);
	while (1)
	{
		mlx_pix_img(ptr, ptr->xy[0], ptr->xy[1],color);
		if (ptr->xy[0] == ptr->xy2[0] && ptr->xy[1] == ptr->xy2[1])
			return ;
		i.e2 = i.err;
		if (i.e2 > -i.dx)
		{
			i.err -= i.dy;
			ptr->xy[0] += i.sx;
		}
		if (i.e2 < i.dy)
		{
			i.err += i.dx;
			ptr->xy[1] += i.sy;
		}
	}
}

void	line_init(t_init *i, t_ptr ptr)
{
	i->dx = abs(ptr.xy2[0] - ptr.xy[0]);
	i->sx = ptr.xy[0] < ptr.xy2[0] ? 1 : -1;
	i->dy = abs(ptr.xy2[1] - ptr.xy[1]);
	i->sy = ptr.xy[1] < ptr.xy2[1] ? 1 : -1;
	i->err = (i->dx > i->dy ? i->dx : -i->dy) / 2;
}

void	menu_border(t_ptr *ptr)
{
/*	int i;
	int color;

	i = -5;
	color = 0x00FF;
	while (i <= 5)
	{
		ptr->xy[0] = 0;
		ptr->xy[1] = SIZE_Y / 4 + i;
		ptr->xy2[0] = SIZE_X;
		ptr->xy2[1] = SIZE_Y / 4 + i;
		line_menu(ptr, color);
		if (i < 0)
			color -= 0x001000;
		if(i > 0)
			color += 0x001000;
		i++;

	}*/
	border_halo(ptr);
	border_heart2(ptr);
	border_heart(ptr);
}

void	border_halo(t_ptr *ptr)
{
	int i;
	int color;

	i = -20;
	color = 0x000000;
	while (i <= 20)
	{
		ptr->xy[0] = 0;
		ptr->xy[1] = SIZE_Y / 4 + i;
		ptr->xy2[0] = SIZE_X;
		ptr->xy2[1] = SIZE_Y / 4 + i;
		if (i < 0)
			color += 0x100000;
		if(i > 0)
			color -= 0x100000;
		line_menu(ptr, color);
		i++;
	}
}

void	border_heart2(t_ptr *ptr)
{
	int i;
	int color;

	i = -5;
	color = 0xFF8800;
	while (i <= 5)
	{
		ptr->xy[0] = 0;
		ptr->xy[1] = SIZE_Y / 4 + i;
		ptr->xy2[0] = SIZE_X;
		ptr->xy2[1] = SIZE_Y / 4 + i;
		if (i < 0)
			color -= 0x002500;
		if(i > 0)
			color += 0x002500;
		line_menu(ptr, color);
		i++;
	}
}

void	border_heart(t_ptr *ptr)
{
	int i;
	int color;

	i = -3;
	color = 0xFFFFFF;
	while (i <= 3)
	{
		ptr->xy[0] = 0;
		ptr->xy[1] = SIZE_Y / 4 + i;
		ptr->xy2[0] = SIZE_X;
		ptr->xy2[1] = SIZE_Y / 4 + i;
		line_menu(ptr, color);
		i++;
	}
}
