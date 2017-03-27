/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:38:45 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/27 17:38:45 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_ptr *ptr)
{
	t_cmp cmp;

	cmp.x = 0;
	while (++cmp.x < SIZE_Y)
	{
		cmp.y = 0;
		while (++cmp.y < SIZE_X)
		{
			cmp.re = ptr->offsetX + cmp.x * ptr->zoom / SIZE_X;
			cmp.im = ptr->offsetY + cmp.y * ptr->zoom / SIZE_Y;
			cmp.i = 0;
			while (++cmp.i < ptr->iter)
			{
				cmp.tmp = cmp.re;
				cmp.re = cmp.re * cmp.re - cmp.im * cmp.im  + ptr->jucst;
				cmp.im = 2 * cmp.tmp * cmp.im + ptr->jucst2;
				if (cmp.re * cmp.re + cmp.im * cmp.im > 16)
					break;
			}
			cmp.color = colors_sel(cmp.i, ptr);
			mlx_pix_img(ptr,cmp.x, cmp.y, cmp.color);
		}
	}
}
