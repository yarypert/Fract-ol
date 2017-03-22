/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 08:07:51 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/22 09:58:01 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		 main(int argc, char **argv)
{
	t_ptr ptr;

	ptr.init = 0;

	if (argc == 2)
		dispatch(argv[1], ptr);
	else
		ft_error("usage : <Fractal Name>\n>>  Mandelbrot\n>> Julia");
	return (0);
}
