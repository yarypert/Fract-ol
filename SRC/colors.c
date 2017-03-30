/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:48:58 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/30 16:26:39 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		colors_sel(int i, t_ptr *ptr)
{
	int color;

	i += ptr->drugs;
	if (i % 25 <= 12)
		color = colors1_12(i, ptr);
	else
		color = colors13_25(i, ptr);
	return (color);
}

int		colors1_12(int i, t_ptr *ptr)
{
	ptr->colors[1] = 0xFF0000;
	ptr->colors[2] = 0xFF4000;
	ptr->colors[3] = 0xFF8000;
	ptr->colors[4] = 0xFFBF00;
	ptr->colors[5] = 0xFFFF00;
	ptr->colors[6] = 0xBFFF00;
	ptr->colors[7] = 0x80FF00;
	ptr->colors[8] = 0x40FF00;
	ptr->colors[9] = 0x00FF00;
	ptr->colors[10] = 0x00FF40;
	ptr->colors[11] = 0x00FF80;
	ptr->colors[12] = 0x00FFBF;
	return (ptr->colors[i % 25 + 1]);
}

int		colors13_25(int i, t_ptr *ptr)
{
	ptr->colors[13] = 0x00FFFF;
	ptr->colors[14] = 0x00BFFF;
	ptr->colors[15] = 0x0080FF;
	ptr->colors[16] = 0x0040FF;
	ptr->colors[17] = 0x0000FF;
	ptr->colors[18] = 0x4000FF;
	ptr->colors[19] = 0x8000FF;
	ptr->colors[20] = 0xBF00FF;
	ptr->colors[21] = 0xFF00FF;
	ptr->colors[22] = 0xFF00BF;
	ptr->colors[23] = 0xFF0080;
	ptr->colors[24] = 0xFF0040;
	ptr->colors[25] = 0xFF0000;
	return (ptr->colors[i % 25 + 1]);
}
