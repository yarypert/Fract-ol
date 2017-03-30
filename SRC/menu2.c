/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 20:11:46 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/30 20:17:21 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	menu3_border(t_ptr *ptr)
{
	int i;
	int color;

	i = 0;
	color = 0x000000;
	while (i < (SIZE_Y / 50) * 2)
	{
		ptr->xy[0] = 0;
		ptr->xy[1] = SIZE_Y - i;
		ptr->xy2[0] = SIZE_X / 3.5;
		ptr->xy2[1] = SIZE_Y - i;
		line_menu(ptr, color);
		i++;
	}
}

void	menu_strings(t_ptr *ptr)
{
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 50, ((SIZE_Y / 50) * 1),
	0xFFFFFF, "1      >>   Mandelbrot");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 50, ((SIZE_Y / 50) * 2),
	0xFFFFFF, "2      >>   Julia");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 50, ((SIZE_Y / 50) * 3),
	0xFFFFFF, "3      >>   Trihorn");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 50, ((SIZE_Y / 50) * 4),
	0xFFFFFF, "4      >>   BurningShips");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 50, ((SIZE_Y / 50) * 5),
	0xFFFFFF, "5      >>   Judelbrotia");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 50, ((SIZE_Y / 50) * 6),
	0xFFFFFF, "6      >>   Spike");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 50, ((SIZE_Y / 50) * 7),
	0xFFFFFF, "7      >>   Rose");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 50, ((SIZE_Y / 50) * 8),
	0xFFFFFF, "8      >>   Rorschach");
	menu_strings2(ptr);
}

void	menu_strings3(t_ptr *ptr)
{
	char *iter;

	iter = ft_itoa(ptr->iter);
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X - SIZE_X / 4,
((SIZE_Y / 50) * 3), 0xFF0000, "Arrows >>");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X - SIZE_X / 4,
((SIZE_Y / 50) * 4), 0xFF0000, "Tab    >>");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X - SIZE_X / 4,
((SIZE_Y / 50) * 5), 0xFF0000, "Mouse1 >>");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X - SIZE_X / 4,
((SIZE_Y / 50) * 6), 0xFF0000, "Mouse2 >>");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X - SIZE_X / 4,
((SIZE_Y / 50) * 7), 0xFF0000, "Mouse3 >>");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X - SIZE_X / 4,
((SIZE_Y / 50) * 8), 0xFF0000, "-      >>");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X - SIZE_X / 4,
((SIZE_Y / 50) * 9), 0xFF0000, "+      >>");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 50,
SIZE_Y - ((SIZE_Y / 50) * 1.5), 0xFF0000,
ft_strjoin("Iterations  >>      ", iter));
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 50,
SIZE_Y - ((SIZE_Y / 50) * 1.5), 0xFF0000, "Iterations  >>");
	menu_strings4(ptr);
}

void	menu_strings2(t_ptr *ptr)
{
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X - SIZE_X / 4,
((SIZE_Y / 50) * 1), 0xFFFFFF, "S      >>   Lock Fractal");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X - SIZE_X / 4,
((SIZE_Y / 50) * 2), 0xFFFFFF, "D      >>   Drug Mode");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X - SIZE_X / 4,
((SIZE_Y / 50) * 3), 0xFFFFFF, "Arrows >>   Move");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X - SIZE_X / 4,
((SIZE_Y / 50) * 4), 0xFFFFFF, "Tab    >>   Menu ON/OFF");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X - SIZE_X / 4,
((SIZE_Y / 50) * 5), 0xFFFFFF, "Mouse1 >>   Zoom IN");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X - SIZE_X / 4,
((SIZE_Y / 50) * 6), 0xFFFFFF, "Mouse2 >>   Zoom OUT");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X - SIZE_X / 4,
((SIZE_Y / 50) * 7), 0xFFFFFF, "Mouse3 >>   Zoom IN/OUT");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X - SIZE_X / 4,
((SIZE_Y / 50) * 8), 0xFFFFFF, "-      >>   Iterations -");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X - SIZE_X / 4,
((SIZE_Y / 50) * 9), 0xFFFFFF, "+      >>   Iterations +");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X - SIZE_X / 4,
((SIZE_Y / 50) * 1), 0xFF0000, "S      >>");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X - SIZE_X / 4,
((SIZE_Y / 50) * 2), 0xFF0000, "D      >>");
	menu_strings3(ptr);
}

void	menu_strings4(t_ptr *ptr)
{
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 50, ((SIZE_Y / 50) * 1),
0xFF0000, "1      >>");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 50, ((SIZE_Y / 50) * 2),
0xFF0000, "2      >>");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 50, ((SIZE_Y / 50) * 3),
0xFF0000, "3      >>");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 50, ((SIZE_Y / 50) * 4),
0xFF0000, "4      >>");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 50, ((SIZE_Y / 50) * 5),
0xFF0000, "5      >>");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 50, ((SIZE_Y / 50) * 6),
0xFF0000, "6      >>");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 50, ((SIZE_Y / 50) * 7),
0xFF0000, "7      >>");
	mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 50, ((SIZE_Y / 50) * 8),
0xFF0000, "8      >>");
}
