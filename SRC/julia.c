/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:38:45 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/23 13:50:11 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_ptr *ptr)
{
	t_cmp cmp;

	cmp.cst = -1;
	cmp.cst2 = +1;
	cmp.x = 0;
	while (++cmp.x < SIZE_Y)
	{
		cmp.y = 0;
		while (++cmp.y < SIZE_X)
		{
			cmp.re = ptr->zoom * cmp.x / SIZE_Y - (ptr->zoom / 2) /*+ ptr->mouse_x*/;
			cmp.im = -ptr->zoom * cmp.y / SIZE_X + (ptr->zoom / 2) /*+ ptr->mouse_y*/;
			cmp.i = 0;
			while (++cmp.i < ptr->iter)
			{
				cmp.tmp = cmp.re;
				cmp.re = cmp.re * cmp.re - cmp.im * cmp.im  + cmp.cst;
				cmp.im = 2 * cmp.tmp * cmp.im + cmp.cst2;
				if (cmp.re * cmp.re + cmp.im * cmp.im > 2048)
					break;
			}
			cmp.color = (0 + cmp.i * 255) / ptr->iter << ptr->color_shift;
			cmp.color += (0 + cmp.i * 255) / ptr->iter;
			mlx_pix_img(ptr,cmp.x, cmp.y, cmp.color);
		}
	}
}
