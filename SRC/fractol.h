/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 07:57:52 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/22 11:14:44 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../MLX_FILES/mlx/mlx.h"
# include "./Libft/libft.h"

# define SIZE_X 1000
# define SIZE_Y 1000
# define T ft_putchar('a')

typedef	struct	s_ptr
{
	int init;

	int		size_line;
	int		bpp;
	char	*bts;
	int		endian;
	void	*mlx;
	void	*win;
	void	*img;
	int		*xy;
	int		*xy2;
}				t_ptr;

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
void	dispatch(char *str, t_ptr ptr);
void	draw(char *str, t_ptr ptr);
void	menu(t_ptr *ptr);
void	line_init(t_init *i, t_ptr ptr);
void	mlx_pix_img(t_ptr *ptr,int x , int y, int color);
void	line_menu(t_ptr *ptr, int color);
void	menu_border(t_ptr *ptr);
void	border_heart(t_ptr *ptr);
void	border_heart2(t_ptr *ptr);
void	border_halo(t_ptr *ptr);
void	Mandelbrot(void);
void	Julia(void);

#endif
