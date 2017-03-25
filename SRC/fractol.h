/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 07:57:52 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/23 13:49:41 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../MLX_FILES/mlx/mlx.h"
# include "./Libft/libft.h"
# include <math.h>

# define SIZE_X 1000
# define SIZE_Y 1000
# define T ft_putchar('a')

typedef	struct	s_ptr
{
	int		size_line;
	int		bpp;
	char	*bts;
	int		endian;
	void	*mlx;
	void	*win;
	void	*img;
	int		*xy;
	int		*xy2;
	int		iter;
	int		color_shift;
	float	zoom;
	int		burn;


	int		init;
}				t_ptr;

typedef struct	s_cmp
{
	float	oldre;
	float	oldim;
	float	newre;
	float	newim;
	float	pi;
	float	tmp;
	float	pr;
	float	re;
	float	im;
	float	cst;
	float	cst2;
	int		i;
	int		x;
	int		y;
	int		color;
}				t_cmp;


typedef	struct	s_init
{
	int		dx;
	int		sx;
	int		dy;
	int		sy;
	int		err;
	int		e2;
}				t_init;

int		key_hook(int keycode, t_ptr *ptr);
int		exit_cross(void);
int		mandelbrot_calculate(t_ptr *ptr, int x,int y, int horn);

void	menu_strings(t_ptr *ptr);
void	dispatch(char *str, t_ptr ptr);
void	draw(char *str, t_ptr ptr,int select);
void	menu(t_ptr *ptr);
void	line_init(t_init *i, t_ptr ptr);
void	mlx_pix_img(t_ptr *ptr,int x , int y, int color);
void	line_menu(t_ptr *ptr, int color);
void	menu_border(t_ptr *ptr);
void	border_heart(t_ptr *ptr);
void	border_heart2(t_ptr *ptr);
void	border_halo(t_ptr *ptr);
void	mandelbrot(t_ptr *ptr, int horn);
void	julia(t_ptr *ptr);

#endif
