/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:33:48 by thvocans          #+#    #+#             */
/*   Updated: 2017/11/25 04:53:12 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

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
**	pick some values for the constant c, this determines the shape of the Julia Set
*/

void	ft_jul_init(t_jul *j)
{
	j->wl = LARG;
	j->h = HAUT;
	j->zoom = 1;
	j->moveX = 0;
	j->moveY = 0;
	j->maxit = 200;
	j->cRe = -0.7;
	j->cIm = 0.27015;
}

void	ft_julia(t_mlx *w)
{
	t_jul	*j;
	int		x;
	int		y;
	int		i;

	y = -1;
	j = &(w->jul);
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
				//if the point is outside the circle with radius 2: stop
				if ((j->newRe * j->newRe + j->newIm * j->newIm) > 4)
					break;
			}
			//draw the pixel
			if (i < j->maxit)
				w->pic2[(y * LARG) + x] = ft_color(i);
		}
	}
		mlx_put_image_to_window(w->mlx, w->win2, w->img2.pt, 0, 0);
}
