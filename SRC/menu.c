/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 08:40:25 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/23 13:39:02 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	menu(t_ptr *ptr)
{
	if(!(ptr->xy = (int *)malloc(sizeof(int) * 2)) ||
			!(ptr->xy2 = (int *)malloc(sizeof(int) * 2)))
		return ;
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
	int i;
	int color;

	i = -5;
	color = 0xFF99000;
	while (i <= 5)
	{
		ptr->xy[0] = 0;
		ptr->xy[1] = SIZE_Y / 4 + i;
		ptr->xy2[0] = SIZE_X / 4 + i;
		ptr->xy2[1] = SIZE_Y / 4 + i;
		line_menu(ptr, color);
		ptr->xy[0] = SIZE_X / 4 + i;
		ptr->xy[1] = 0;
		ptr->xy2[0] = SIZE_X / 4 + i;
		ptr->xy2[1] = SIZE_Y / 4 + i;
		line_menu(ptr, color);
		color -=  0x003300;
		i += 5;
	}
}

void	menu_strings(t_ptr *ptr)
{
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 50, ((SIZE_Y / 50) * 1),
	0xFFFFFF, "1   >>   Mandelbrot");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 50, ((SIZE_Y / 50) * 2),
	0xFFFFFF, "2   >>   Julia");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 50, ((SIZE_Y / 50) * 3),
	0xFFFFFF, "3   >>   Trihorn");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 50, ((SIZE_Y / 50) * 4),
	0xFFFFFF, "4   >>   BurningShips");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 50, ((SIZE_Y / 50) * 1),
	0xFF2500, "1   >>");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 50, ((SIZE_Y / 50) * 2),
	0xFF2500, "2   >>");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 50, ((SIZE_Y / 50) * 3),
	0xFF2500, "3   >>");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 50, ((SIZE_Y / 50) * 4),
	0xFF2500, "1   >>");
}
