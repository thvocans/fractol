/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:29:19 by thvocans          #+#    #+#             */
/*   Updated: 2018/01/16 18:24:32 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define LARG 1200
# define HAUT 1000

# include "../sierra/mlx.h"
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_img	t_img;
typedef struct s_key	t_key;
typedef struct s_man	t_man;
typedef struct s_jul	t_jul;
typedef struct s_mlx	t_mlx;

struct	s_img
{
	void	*pt;

	int		ln;
	int		bpp;
	int		end;
};

struct	s_key
{
	unsigned char	down[40];
	short			oct;
	short			bit;
	short			mask;
	unsigned int	*pt;
};

struct	s_man
{
	long double		cx;
	long double		cy;
	long double		xmin;
	long double		xmax;
	long double		ymin;
	long double		ymax;
	long double		pi_w;
	long double		pi_h;
	long double		zx;
	long double		zy;
	long double		zx2;
	long double		zy2;
	long double		escape;
	long double		esc2;
	unsigned char	*color;
	int				iy;
	int				ix;
	int				ixmax;
	int				iymax;
	int				iter;
	int				itermax;
	int				cur;
};

struct	s_jul
{
	int		wl;
	int		h;
	double	cre;
	double	cim;
	double	newre;
	double	newim;
	double	oldre;
	double	oldim;
	double	zoom;
	double	movex;
	double	movey;
	int		maxit;
	int		mouseon;
	int		mid[2];
};

struct	s_mlx
{
	void	*mlx;

	void	*win1;
	t_img	img1;
	int		*pic1;

	void	*win2;
	t_img	img2;
	int		*pic2;

	void	*win3;
	t_img	img3;
	int		*pic3;

	void	*win4;
	t_img	img4;
	int		*pic4;

	t_man	man;
	t_man	col;
	t_jul	jul;
	t_jul	cos;

	int		mid[2];
	void	*cur_win;
	int		*cur_pic;
	t_key	key;
	int		key_down[300];
};

int		press_win(int key, t_mlx *w);
int		release_win(int key, t_mlx *w);

void	man_loop(t_mlx *w);
void	jul_loop(t_mlx *w);
void	newton_loop(t_mlx *w);

int		press_win1(int key, t_mlx *w);
int		release_win1(int key, t_mlx *w);
void	ft_mandel_init(t_mlx *w);
void	ft_mandelbrot(t_mlx *w);
int		man_mouse(int button, int x, int y, t_mlx *w);
void	ft_man_zoom(t_mlx *w, long double x, long double y, float zoom);

int		press_win2(int key, t_mlx *w);
int		release_win2(int key, t_mlx *w);
void	ft_jul_init(t_mlx *w);
void	ft_julia(t_mlx *w);
int		jul_mouse(int button, int x, int y, t_mlx *w);
int		ft_move_mouse(int x, int y, t_mlx *w);
void	ft_jul_zoom(t_jul *j, long double x, long double y, float zoom);

int		press_win3(int key, t_mlx *w);
int		release_win3(int key, t_mlx *w);
void	ft_cool_init(t_mlx *w);
void	ft_coolbrot(t_mlx *w);
int		cool_mouse(int button, int x, int y, t_mlx *w);
void	ft_cool_zoom(t_man *c, long double x, long double y, float zoom);

int		press_win4(int key, t_mlx *w);
int		release_win4(int key, t_mlx *w);
void	ft_newton_init(t_mlx *w);
void	ft_newton(t_mlx *w);
int		newton_mouse(int button, int x, int y, t_mlx *w);
void	ft_newton_zoom(t_mlx *w, long double x, long double y, float zoom);

void	ft_init_key(t_key *key);
int		ft_key(t_mlx *w, void *win, int *pic);
int		ft_color(int iter);
int		pressmouse(int button, int x, int y, t_mlx *w);
void	clear_img(int **pic);
int		*ft_args_check(int ac, char **av);

#endif
