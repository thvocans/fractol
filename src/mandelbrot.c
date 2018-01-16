/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 21:08:11 by thvocans          #+#    #+#             */
/*   Updated: 2018/01/16 18:19:19 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

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
*/

void		ft_mandel_init(t_mlx *w)
{
	w->mid[0] = LARG / 2;
	w->mid[1] = HAUT / 2;
	w->man.ixmax = LARG;
	w->man.iymax = HAUT;
	w->man.xmin = -2.5;
	w->man.xmax = 1.5;
	w->man.ymin = -2.0;
	w->man.ymax = 2.0;
	w->man.pi_w = (w->man.xmax - w->man.xmin) / w->man.ixmax;
	w->man.pi_h = (w->man.ymax - w->man.ymin) / w->man.iymax;
	w->man.itermax = 200;
	w->man.escape = 2;
	w->man.esc2 = w->man.escape * w->man.escape;
}

static void	ft_man2(t_mlx *w)
{
	t_man	*m;

	m = &w->man;
	while (m->ix < m->ixmax)
	{
		m->cx = m->xmin + m->ix * m->pi_w;
		m->zx = 0.0;
		m->zy = 0.0;
		m->zx2 = m->zx * m->zx;
		m->zy2 = m->zy * m->zy;
		m->iter = 0;
		while (m->iter < m->itermax && ((m->zx2 + m->zy2) < m->esc2))
		{
			m->zy = 2 * m->zx * m->zy + m->cy;
			m->zx = m->zx2 - m->zy2 + m->cx;
			m->zx2 = m->zx * m->zx;
			m->zy2 = m->zy * m->zy;
			m->iter++;
		}
		if (m->iter != m->itermax)
			w->pic1[(m->iy * (LARG)) + m->ix] = ft_color(m->iter);
		m->cur++;
		m->ix++;
	}
}

void		ft_mandelbrot(t_mlx *w)
{
	t_man	*m;

	m = &w->man;
	m->cur = 0;
	m->iy = 0;
	while (m->iy < m->iymax)
	{
		m->cy = m->ymin + m->iy * m->pi_h;
		if (fabsl(m->cy) < m->pi_h / 2)
			m->cy = 0.0;
		m->ix = 0;
		ft_man2(w);
		m->iy++;
	}
	mlx_put_image_to_window(w->mlx, w->win1, w->img1.pt, 0, 0);
}
