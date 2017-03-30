/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:38:45 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/30 17:09:59 by yarypert         ###   ########.fr       */
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
			cmp.re = ptr->offset_x + cmp.x * ptr->zoom / SIZE_X;
			cmp.im = ptr->offset_y + cmp.y * ptr->zoom / SIZE_Y;
			cmp.i = 0;
			while (++cmp.i < ptr->iter)
			{
				cmp.tmp = cmp.re;
				if (ptr->judelbrotia == 1)
					judelbrotia(ptr, &cmp);
				else
					julia2(ptr, &cmp);
				if (cmp.re * cmp.re + cmp.im * cmp.im > 16)
					break ;
			}
			cmp.color = colors_sel(cmp.i, ptr);
			mlx_pix_img(ptr, cmp.x, cmp.y, cmp.color);
		}
	}
}

void	judelbrotia(t_ptr *ptr, t_cmp *cmp)
{
	cmp->re = fabs(cmp->re * cmp->re - cmp->im * cmp->im) + ptr->jucst;
	cmp->im = ptr->spike * cmp->tmp * cmp->im + ptr->jucst2;
}

void	julia2(t_ptr *ptr, t_cmp *cmp)
{
	cmp->re = cmp->re * cmp->re - cmp->im * cmp->im + ptr->jucst;
	cmp->im = ptr->spike * cmp->tmp * cmp->im + ptr->jucst2;
}
