/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 08:07:51 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/27 18:17:13 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		 main(int argc, char **argv)
{
	t_ptr ptr;

	ptr.toggle = 0;
	ptr.drugs = 0;
	ptr.jucst = -0.726667;
	ptr.jucst2 = -0.206667;
	ptr.iter = 64;
	ptr.zoom = 4.0;
	ptr.offsetX = -2.0;
	ptr.offsetY = -2.0;
	ptr.old_coordX = SIZE_X / 2;
	ptr.old_coordY = SIZE_Y / 2;
	if (argc == 2)
		dispatch(argv[1], ptr);
	else
		ft_error("usage : <Fractal Name>\n1 >> Mandelbrot\n2 >> Julia\n\
			3 >> Trihorn\n4 >> BurningShips\n");
	return (0);
}
