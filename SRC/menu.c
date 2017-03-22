/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 08:40:25 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/22 10:15:23 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	menu(t_ptr *ptr)
{
	int color;
	color = 0x0088FF;
	ptr->xy = (int *)malloc(sizeof(int) * 2);
	ptr->xy2 = (int *)malloc(sizeof(int) * 2);
	ptr->xy[0] = 0;
	ptr->xy[1] = 0;
	ptr->xy2[0] = 150;
	ptr->xy2[1] = 150;
	line_menu(ptr, color);
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
