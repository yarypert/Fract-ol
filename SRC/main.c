/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 08:07:51 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/23 17:46:58 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		 main(int argc, char **argv)
{
	t_ptr ptr;

	ptr.iter = 512;
	ptr.color_shift = 75;
	ptr.zoom = 4;
	if (argc == 2)
		dispatch(argv[1], ptr);
	else
		ft_error("usage : <Fractal Name>\n1 >> Mandelbrot\n2 >> Julia\n\
			3 >> Trihorn\n4 >> BurningShips\n");
	return (0);
}
