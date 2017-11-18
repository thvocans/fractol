/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:33:48 by thvocans          #+#    #+#             */
/*   Updated: 2017/11/18 19:58:39 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**		The Julia set
**	Each point is equal to the previous point coordinates squared
**	plus c:
**	n + 1 = n2 + c 
**	Given the use of imaginary numbers we will need the use of a matrix
**	given z = a + bi:
**	Matrix form bi:	(a	-b) carre :	(aa + -bb	a-b + -ba) 
**					(b	 a)			(ba + ab	b-b + aa)
**	Matrix form bi:	(a	b) carre :	(aa + bc	ab + bd) 
**					(c	d)			(ca + dc	cb + dd)
**
*/

void	ft_jul_init(t_jul *j)
{
	j->wl = LARG;
	j->h = HAUT;
	j->zoom = 1;
	j->moveX = 0;
	j->moveY = 0;
	j->maxit = 200;
	//pick some values for the constant c, this determines the shape of the Julia Set
	j->cRe = -0.7;
	j->cIm = 0.27015;
}

void	ft_julia(t_mlx *w)
{
	t_jul	*j;

	j = &(w->jul);
	//loop through every pixel
	for(int y = 0; y < j->h; y++)
		for(int x = 0; x < j->wl; x++)
		{
			//calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
			j->newRe = 1.5 * (x - j->wl / 2) / (0.5 * j->zoom * j->wl) + j->moveX;
			j->newIm = (y - j->h / 2) / (0.5 * j->zoom * j->h) + j->moveY;
			//i will represent the number of iterations
			int i;
			//start the iteration process
			for(i = 0; i < j->maxit; i++)
			{
				//remember value of previous iteration
				j->oldRe = j->newRe;
				j->oldIm = j->newIm;
				//the actual iteration, the real and imaginary part are calculated
				j->newRe = j->oldRe * j->oldRe - j->oldIm * j->oldIm + j->cRe;
				j->newIm = 2 * j->oldRe * j->oldIm + j->cIm;
				//if the point is outside the circle with radius 2: stop
				if((j->newRe * j->newRe + j->newIm * j->newIm) > 4) break;
			}
			//draw the pixel
			if (i < j->maxit)
				w->pic[(y * LARG) + x] = ft_color(i);
		}
	mlx_put_image_to_window(w->mlx, w->win, w->img.pt, 0, 0);
}
