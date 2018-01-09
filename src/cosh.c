/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cosh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 21:12:11 by thvocans          #+#    #+#             */
/*   Updated: 2018/01/09 22:57:37 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*
**		Hyperbolic cosinus newton fractal
**	Each point is equal to :
**	n + 1 = (n * sinh(n) - cosh(n) + 1) / sinh(n)
*/

void	ft_cosh_init(t_mlx *w)
{
	w->mid[0] = LARG / 2;
	w->mid[1] = HAUT / 2;
	w->cos.wl = LARG;
	w->cos.h = HAUT;
	w->cos.zoom = 0.002;
	w->cos.moveX = 0;
	w->cos.moveY = 0;
	w->cos.maxit = 200;
	w->cos.cRe = 1;
	w->cos.cIm = 1;
}

int		ft_color2(int i)
{
	int out;
	out = (255 - i * 3) + ((255 - i * i) << 8) + ((i * 6 )<< 16);
	return (out);
}

void	ft_cosh(t_mlx *w)
{
	t_jul	*j;
	int		x;
	int		y;
	int		i;

	y = -1;
	j = &(w->cos);
	//loop through every pixel
	while (++y < HAUT)
	{
		x = -1;
		while (++x < LARG)
		{
			// x : -1.5 ; 1.5 ||| y -1 ; 1 ||||
			j->newRe = 1.5 * (x - LARG / 2) / (j->zoom * LARG / 2) + j->moveX;
			j->newIm = (y - HAUT / 2) / (0.5 * j->zoom * HAUT) + j->moveY;
			//i will represent the number of iterations
			//start the iteration process
			i = -1;
			while (++i < j->maxit)
			{
				//remember value of previous iteration
				j->oldRe = j->newRe;
				j->oldIm = j->newIm;
				//the actual iteration, the real and imaginary part are calculated
				j->newRe = j->oldRe * j->oldRe - j->oldIm * j->oldIm + j->cRe;
				j->newIm = 2 * j->oldRe * j->oldIm + j->cIm;
//				j->newRe = (j->oldRe * sinh(j->oldRe) - cosh(j->oldIm) + j->cRe)\
//						   / sinh(j->oldRe);
//				j->newIm = (j->oldIm * sinh(j->oldIm) - cosh(j->oldIm) + j->cIm)\
//						   / sinh(j->oldIm);
				//if the point is outside the circle with radius 2: stop
				if (fabs (j->newRe - j->oldRe) < 0.00001 ||
					fabs (j->newIm - j->oldIm) < 0.00001)
					break;
			}
			//draw the pixel
			if (i < j->maxit)
				w->pic4[(y * LARG) + x] = ft_color2(i);
		}
	}
		mlx_put_image_to_window(w->mlx, w->win4, w->img4.pt, 0, 0);
}