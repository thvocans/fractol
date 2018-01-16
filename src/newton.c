/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cosh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 21:12:11 by thvocans          #+#    #+#             */
/*   Updated: 2018/01/16 17:53:29 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*
**		Hyperbolic cosinus newton fractal
**	Each point is equal to :
**	n + 1 = (n * sinh(n) - cosh(n) + 1) / sinh(n)
*/

void		ft_newton_init(t_mlx *w)
{
	w->cos.mid[0] = LARG / 2;
	w->cos.mid[1] = HAUT / 2;
	w->cos.wl = LARG;
	w->cos.h = HAUT;
	w->cos.zoom = 1;
	w->cos.movex = 0;
	w->cos.movey = 0;
	w->cos.maxit = 20;
	w->cos.cre = -1;
	w->cos.cim = -1;
}

static void	ft_xloop2(t_jul *j)
{
	int		i;
	double	xx;
	double	yy;
	double	d;
	double	two_3rd;

	two_3rd = (2.0 / 3.0);
	i = -1;
	while (++i < j->maxit)
	{
		j->oldre = j->newre;
		xx = j->oldre * j->oldre;
		yy = j->newim * j->newim;
		d = 3.0 * ((xx - yy) * (xx - yy) + 4.0 * xx * yy);
		if (d == 0.0)
			d = 0.000001;
		j->newre = two_3rd * j->oldre + (xx - yy) / d;
		j->newim = two_3rd * j->newim - 2.0 * j->oldre * j->newim / d;
	}
}

static void	ft_xloop(t_mlx *w, int x, int y)
{
	t_jul	*j;

	j = &(w->cos);
	while (++x < LARG)
	{
		j->newre = 1.5 * (x - LARG / 2) / (j->zoom * LARG / 2) + j->movex;
		j->newim = (y - HAUT / 2) / (0.5 * j->zoom * HAUT) + j->movey;
		ft_xloop2(j);
		if (j->newre > 0.0)
			w->pic3[(y * LARG) + x] = 0xff0000;
		else
		{
			if ((j->newre < -0.3) && (j->newim > 0.0))
				w->pic3[(y * LARG) + x] = 0x00ff00;
			else
				w->pic3[(y * LARG) + x] = 0x0000ff;
		}
	}
}

void		ft_newton(t_mlx *w)
{
	int		x;
	int		y;

	y = -1;
	while (++y < HAUT)
	{
		x = -1;
		ft_xloop(w, x, y);
	}
	mlx_put_image_to_window(w->mlx, w->win3, w->img3.pt, 0, 0);
}
