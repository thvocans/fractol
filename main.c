/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:59:32 by thvocans          #+#    #+#             */
/*   Updated: 2017/10/10 16:04:41 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_latent(/*int key,*/ t_mlx *w)
{
	ft_key(w);
	return (0);
}

/*
**		The Mandelbrot set
**	Each point is equal to the previous point coordinates squared
**	plus the current point:
**	n + 1 = n2 + n.x 
**	Given the use of imaginary numbers we will need the use of a matrix
**	given z = a + bi:
**	Matrix form bi:	(a	-b) carre :	(aa + -bb	a-b + -ba) 
**					(b	 a)			(ba + ab	b-b + aa)
**	Matrix form bi:	(a	b) carre :	(aa + bc	ab + bd) 
**					(c	d)			(ca + dc	cb + dd)
**
*/

void	ft_mandelbrot(t_mlx *w)
{
	int iY;
	int iX;
	int iYmax = 640;
	int iXmax = 560;
	long double Cx;
	long double Cy;
	long double CxMin = -3;
	long double CxMax = 1;
	long double CyMin = -2.0;
	long double CyMax = 2.0;
	long double PixelWidth = (CxMax - CxMin) / iXmax;
	long double PixelHeight = (CyMax - CyMin) / iYmax;
	int Iteration;
	int IterationMax = 200;
	long double Zx;
	long double Zy;
	long double Zx2;
	long double Zy2;
	long double EscapeRadius = 2;
	long double ER2 = EscapeRadius * EscapeRadius;
	int actuel = 0;

	for (iY = 0;iY < iYmax; iY++)
	{
		Cy = CyMin + iY * PixelHeight;
		if (fabsl(Cy) < PixelHeight / 2)
			Cy = 0.0; /* Main antenna */
		for (iX = 0; iX < iXmax; iX++)
		{
			Cx = CxMin + iX * PixelWidth;
			/* initial value of orbit = critical point Z= 0 */
			Zx = 0.0;
			Zy = 0.0;
			Zx2 = Zx * Zx;
			Zy2 = Zy * Zy;
			Iteration = 0;
			while (Iteration < IterationMax && ((Zx2 + Zy2) < ER2))
			{
				Zy	= 2 * Zx * Zy + Cy;
				Zx	= Zx2 - Zy2 + Cx;
				Zx2	= Zx * Zx;
				Zy2	= Zy * Zy;
				Iteration++;
			}
			printf("iY:%d iX:%d\n",iY, iX);
			if (Iteration != IterationMax)
			{
				w->pic[(iY * (LARG)) + iX] = 0xFFFFFF;
			}
			actuel++;
		}
	}
mlx_put_image_to_window(w->mlx, w->win, w->img.pt, 0, 0);
}

	/*	long double	px;
		long double	py;
		long double	cx;
		long double	cy;
		float		pi;
		float		pj;
		int			iter;
		int			pixL = 0;
		int			pixH = 0;

		pj = py = cy = -2.5;
		while (pixH < HAUT)
		{
		pi = cx = -3; //carre 2 * 2 centre a -0.5, 0.
		pixL = 0;
		while (pi < 2.5)
		{
		px = 0;
		py = 0;
		iter = 0;
		cx = pi;
		cy = pj;
		while (((cx * cx) + (cy * cy)) < 4 && iter < 511)
		{
		cx = (px * px) - (py * py) + cx;
		cy = 2 * px * py + cy;
		iter++;
		}
		if (iter < 255)
		w->pic[pixL + (pixH * LARG)] = 0xFFFFFF;
		pixL++;
		pi += 0.008;
		}
		pixH++;
		pj += 0.008;
		}
		*/

int		main(int ac, char **av)
{
	t_mlx w;

	if (ac < 1)
		ft_error(NO_ARGS);
	ft_init_key(&w.key);
	w.mlx = mlx_init();
	w.win = mlx_new_window(w.mlx, LARG, HAUT, "You Shall Not Segfault");
	w.img.pt = mlx_new_image(w.mlx, LARG, HAUT);
	w.pic = (int*)mlx_get_data_addr(w.img.pt, &(w.img.bpp), &(w.img.ln),\
			&(w.img.end));
	av[0] = "";
	ft_mandelbrot(&w);
	mlx_do_key_autorepeatoff(&w);
	mlx_hook(w.win, 2, (1L << 0), &press, &w);
	mlx_hook(w.win, 3, (1L << 1), &release, &w);
	mlx_loop_hook(w.mlx, &ft_latent, &w);
	mlx_loop(w.mlx);
}
