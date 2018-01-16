/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:33:48 by thvocans          #+#    #+#             */
/*   Updated: 2018/01/16 17:25:40 by thvocans         ###   ########.fr       */
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
**	c determines the shape of the Julia Set
*/

void		ft_jul_init(t_mlx *w)
{
	w->jul.mid[0] = LARG / 2;
	w->jul.mid[1] = HAUT / 2;
	w->jul.wl = LARG;
	w->jul.h = HAUT;
	w->jul.zoom = 1;
	w->jul.movex = 0;
	w->jul.movey = 0;
	w->jul.maxit = 150;
	w->jul.cre = -0.7;
	w->jul.cim = 0.27015;
}

static void	ft_jul_xloop(t_mlx *w, int x, int y, int i)
{
	t_jul	*j;

	j = &(w->jul);
	while (++x < LARG)
	{
		j->newre = 1.5 * (x - LARG / 2) / (j->zoom * LARG / 2) + j->movex;
		j->newim = (y - HAUT / 2) / (0.5 * j->zoom * HAUT) + j->movey;
		i = -1;
		while (++i < j->maxit)
		{
			j->oldre = j->newre;
			j->oldim = j->newim;
			j->newre = j->oldre * j->oldre - j->oldim * j->oldim + j->cre;
			j->newim = 2 * j->oldre * j->oldim + j->cim;
			if ((j->newre * j->newre + j->newim * j->newim) > 4)
				break ;
		}
		if (i < j->maxit)
			w->pic2[(y * LARG) + x] = ft_color(i);
		else
			w->pic2[(y * LARG) + x] = 0x000000;
	}
}

void		ft_julia(t_mlx *w)
{
	t_jul	*j;
	int		x;
	int		y;
	int		i;

	y = -1;
	j = &(w->jul);
	while (++y < HAUT)
	{
		x = -1;
		i = -1;
		ft_jul_xloop(w, x, y, i);
	}
	mlx_put_image_to_window(w->mlx, w->win2, w->img2.pt, 0, 0);
}
