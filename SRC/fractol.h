/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 07:57:52 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/30 20:09:48 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../MLX_FILES/mlx/mlx.h"
# include "./Libft/libft.h"
# include <math.h>
# include <stdio.h>

# define SIZE_X 1200
# define SIZE_Y 1200
# define T ft_putchar('a')

typedef struct	s_ptr
{
	int			menu_toggle;
	int			drugs;
	int			toggle;
	int			judelbrotia;
	int			horn;
	int			spike;
	int			sound;
	int			size_line;
	int			bpp;
	int			endian;
	int			colors[26];
	int			*xy;
	int			*xy2;
	int			burn;
	int			iter;
	int			coord_y;
	int			coord_x;
	int			select;
	float		zoom;
	float		offset_x;
	float		offset_y;
	double		jucst;
	double		jucst2;
	char		*bts;
	char		*param;
	void		*mlx;
	void		*win;
	void		*img;
}				t_ptr;

typedef struct	s_cmp
{
	float		oldre;
	float		oldim;
	float		newre;
	float		newim;
	float		pi;
	float		tmp;
	float		pr;
	float		re;
	float		im;
	int			i;
	int			x;
	int			y;
	int			color;
}				t_cmp;

typedef struct	s_init
{
	int			dx;
	int			sx;
	int			dy;
	int			sy;
	int			err;
	int			e2;
}				t_init;

int				key_hook(int keycode, t_ptr *ptr);
int				key_hook2(int keycode, t_ptr *ptr);
int				key_hook3(int keycode, t_ptr *ptr);
int				key_hook4(int keycode, t_ptr *ptr);
int				exit_cross(void);
int				mandelbrot_calculate(t_ptr *ptr, int x, int y);
int				frc_mouse_manager(int x, int y, t_ptr *ptr);
int				refresh(t_ptr *ptr);
int				refresh2(t_ptr *ptr);
int				mouse(int keycode, int x, int y, t_ptr *ptr);
int				colors_sel(int iter, t_ptr *ptr);
int				colors1_12(int iter, t_ptr *ptr);
int				colors13_25(int iter, t_ptr *ptr);

void			init(t_ptr *ptr);

void			select_draw(t_ptr ptr);
void			menu_strings(t_ptr *ptr);
void			menu_strings2(t_ptr *ptr);
void			menu_strings3(t_ptr *ptr);
void			menu_strings4(t_ptr *ptr);
void			dispatch(char *str, t_ptr ptr);
void			dispatch2(char *str, t_ptr ptr);
void			dispatch3(char *str, t_ptr ptr);
void			draw(t_ptr ptr);
void			menu(t_ptr *ptr);
void			line_init(t_init *i, t_ptr ptr);
void			mlx_pix_img(t_ptr *ptr, int x, int y, int color);
void			line_menu(t_ptr *ptr, int color);
void			menu_border(t_ptr *ptr);
void			menu2_border(t_ptr *ptr);
void			menu3_border(t_ptr *ptr);
void			mandelbrot(t_ptr *ptr);
void			rorschach(t_ptr *ptr);
void			rose(t_ptr *ptr);
void			julia(t_ptr *ptr);
void			julia2(t_ptr *ptr, t_cmp *cmp);
void			judelbrotia(t_ptr *ptr, t_cmp *cmp);

#endif
