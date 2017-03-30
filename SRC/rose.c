/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rose.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:01:55 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/30 19:57:07 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	rose(t_ptr *ptr)
{
	t_cmp cmp;

	cmp.x = 0;
	while (++cmp.x < SIZE_Y)
	{
		cmp.y = 0;
		while (++cmp.y < SIZE_X)
		{
			cmp.re = ptr->offset_x + cmp.x * ptr->zoom / SIZE_X;
			cmp.im = ptr->offset_y + cmp.y * ptr->zoom / SIZE_Y;
			cmp.i = 0;
			while (++cmp.i < ptr->iter)
			{
				cmp.tmp = cmp.re;
				cmp.re = log(cmp.re * cmp.re - cmp.im * cmp.im);
				cmp.im = 2 * cmp.tmp * cmp.im;
				if (cmp.re * cmp.re + cmp.im * cmp.im > 16)
					break ;
			}
			cmp.color = colors_sel(cmp.i, ptr);
			mlx_pix_img(ptr, cmp.x, cmp.y, cmp.color);
		}
	}
}
