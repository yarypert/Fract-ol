/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rorschach.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:47:59 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/30 19:53:18 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	rorschach(t_ptr *ptr)
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
				cmp.re = cmp.re * cmp.re - cmp.im * cmp.im + ptr->jucst;
				cmp.im = fabs(2 * cmp.tmp * cmp.im) + ptr->jucst2;
				if (cmp.re * cmp.re + cmp.im * cmp.im > 16)
					break ;
			}
			cmp.color = colors_sel(cmp.i, ptr);
			mlx_pix_img(ptr, cmp.x, cmp.y, cmp.color);
		}
	}
}
