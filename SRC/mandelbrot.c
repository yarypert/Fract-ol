/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:38:31 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/23 17:57:28 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandelbrot_calculate(t_ptr *ptr, int x, int y, int horn)
{
	t_cmp	cmp;

	cmp.pr = ptr->zoom * (float)x / SIZE_Y - (ptr->zoom / 2);
	cmp.pi = -ptr->zoom * (float)y / SIZE_X + (ptr->zoom / 2);
	cmp.newre = 0;
	cmp.newim = 0;
	cmp.i = 0;
	while (++cmp.i < ptr->iter)
	{
		cmp.oldre = cmp.newre;
		cmp.oldim = horn * cmp.newim;
		cmp.newre = cmp.oldre * cmp.oldre - cmp.oldim * cmp.oldim + cmp.pr;
		if (ptr->burn == 1)
			cmp.newim = fabs(2 * cmp.oldre * cmp.oldim) - cmp.pi;
		else
			cmp.newim = 2 * cmp.oldre * cmp.oldim + cmp.pi;
		if ((cmp.newre * cmp.newre + cmp.newim * cmp.newim) > 16)
			return(cmp.i);
	}
	return (cmp.i);
}

void	mandelbrot(t_ptr *ptr,int horn)
{
	int	color;
	int	y;
	int	x;
	int	i;

	x = 0;
	while (++x < SIZE_X)
	{
		y = 0;
		while (++y < SIZE_Y)
		{
			if (horn == -1)
				i = mandelbrot_calculate(ptr, x, y, -1);
			else if (horn == 1)
				i = mandelbrot_calculate(ptr, x, y, 1);
			color = (0 + i * 255) / ptr->iter << ptr->color_shift;
			color += (0 + i * 255) / ptr->iter;
			mlx_pix_img(ptr, x , y, color);
		}
	}
}
