/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cosh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 21:12:11 by thvocans          #+#    #+#             */
/*   Updated: 2018/01/12 22:11:28 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*
**		Hyperbolic cosinus newton fractal
**	Each point is equal to :
**	n + 1 = (n * sinh(n) - cosh(n) + 1) / sinh(n)
*/

void	ft_newton_init(t_mlx *w)
{
	w->mid[0] = LARG / 2;
	w->mid[1] = HAUT / 2;
	w->cos.wl = LARG;
	w->cos.h = HAUT;
	w->cos.zoom = 1;
	w->cos.moveX = 0;
	w->cos.moveY = 0;
	w->cos.maxit = 50;
	w->cos.cRe = -1;
	w->cos.cIm = -1;
}

void	ft_newton(t_mlx *w)
{
	t_jul	*j;
	int		x;
	int		y;
	int		i;
	double	xx;
	double	yy;
	double	d;
	double	two_3rd;

	y = -1;
	j = &(w->cos);
	two_3rd = (2.0 / 3.0);	
	while (++y < HAUT)
	{
		x = -1;
		while (++x < LARG)
		{
			j->newRe = 1.5 * (x - LARG / 2) / (j->zoom * LARG / 2) + j->moveX;
			j->newIm = (y - HAUT / 2) / (0.5 * j->zoom * HAUT) + j->moveY;
			i = -1;
			while (++i < j->maxit)
			{
				j->oldRe = j->newRe;
				xx = j->oldRe * j->oldRe;
				yy = j->newIm * j->newIm;
				d = 3.0 * ((xx - yy) * (xx - yy) + 4.0 * xx * yy);
				if (d == 0.0)
					d = 0.000001;
				j->newRe = two_3rd * j->oldRe + (xx - yy) / d;
				j->newIm = two_3rd * j->newIm - 2.0 * j->oldRe * j->newIm / d;
			}
			if (j->newRe > 0.0)
				w->pic3[(y * LARG) + x] = 0xff0000;
			else
			{
				if ((j->newRe < -0.3) && (j->newIm > 0.0))
					w->pic3[(y * LARG) + x] = 0x00ff00;
				else
					w->pic3[(y * LARG) + x] = 0x0000ff;
			}
		}
	}
		mlx_put_image_to_window(w->mlx, w->win3, w->img3.pt, 0, 0);
}
