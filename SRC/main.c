/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 08:07:51 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/30 19:52:48 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_ptr ptr;

	init(&ptr);
	if (argc == 2)
	{
		ptr.sound = 1;
		system("afplay sound.mp3 &");
		dispatch(argv[1], ptr);
	}
	else
	{
		if (ptr.sound == 1)
			system("killall afplay");
		ft_error("usage : <Fractal Name>\n1 >> Mandelbrot\n2 >> Julia\n\
3 >> Trihorn\n4 >> BurningShips\n5 >> Judelbrotia\n6 >> Spike\n7 >> Rose\n\
8 >> Rorschach\n");
	}
	return (0);
}

void	init(t_ptr *ptr)
{
	ptr->menu_toggle = 1;
	ptr->toggle = 0;
	ptr->drugs = 0;
	ptr->jucst = -0.726667;
	ptr->jucst2 = -0.206667;
	ptr->iter = 32;
}
