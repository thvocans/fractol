/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:29:19 by thvocans          #+#    #+#             */
/*   Updated: 2018/01/09 21:01:44 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define LARG 600
# define HAUT 500

# include "../sierra/mlx.h"
# include <stdio.h>
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
	long double Cx;
	long double Cy;
	long double CxMin;
	long double CxMax;
	long double CyMin;
	long double CyMax;
	long double PixelWidth;
	long double PixelHeight;
	long double Zx;
	long double Zy;
	long double Zx2;
	long double Zy2;
	long double EscapeRadius;
	unsigned char *color;
	int iY;
	int iX;
	int iXmax;
	int iYmax;
	int Iteration;
	int IterationMax;
	int actuel;
long double ER2;
};

struct	s_jul
{
	int		wl;
	int		h;
	double	cRe;
	double	cIm;
	double	newRe;
	double	newIm;
	double	oldRe;
	double	oldIm;
	double	zoom;
	double	moveX;
	double	moveY;
	int		maxit;
	int		mouseon;
};

struct	s_mlx
{
	void	*mlx;
	int		cur_win;

//window1
	void	*win1;
	t_img	img1;
	int		*pic1;
//window2
	void	*win2;
	t_img	img2;
	int		*pic2;
//window3
	void	*win3;
	t_img	img3;
	int		*pic3;
	
//window4
	void	*win4;
	t_img	img4;
	int		*pic4;

	t_man	man;
	t_man	col;
	t_jul	jul;
	t_jul	cos;

	t_key	key;
	int		key_down[300];
	int		mid[2];
};

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
void	ft_jul_zoom(t_mlx *w, long double x, long double y, float zoom);

int		press_win3(int key, t_mlx *w);
int		release_win3(int key, t_mlx *w);
void	ft_cool_init(t_mlx *w);
void	ft_coolbrot(t_mlx *w);
int		cool_mouse(int button, int x, int y, t_mlx *w);
void	ft_cool_zoom(t_mlx *w, long double x, long double y, float zoom);

int		press_win4(int key, t_mlx *w);
int		release_win4(int key, t_mlx *w);
void	ft_cosh_init(t_mlx *w);
void	ft_cosh(t_mlx *w);
int		cosh_mouse(int button, int x, int y, t_mlx *w);
void	ft_cosh_zoom(t_mlx *w, long double x, long double y, float zoom);

void	ft_init_key(t_key *key);
int		ft_key(t_mlx *w, void *win, int *pic);
int		ft_color(int iter);
int		pressmouse(int button, int x, int y, t_mlx *w);
void	clear_img(int **pic);
int		*ft_args_check(int ac, char **av);

#endif
