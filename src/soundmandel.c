/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 21:08:11 by thvocans          #+#    #+#             */
/*   Updated: 2018/01/12 04:14:25 by thvocans         ###   ########.fr       */
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
**
*/

void	ft_cool_init(t_mlx *w)
{
	w->mid[0] = LARG / 2;
	w->mid[1] = HAUT / 2;
	w->col.iXmax = LARG;
	w->col.iYmax = HAUT;
	w->col.CxMin = -4.5;
	w->col.CxMax = 0.9;
	w->col.CyMin = -4.5;
	w->col.CyMax = 0.3;
	w->col.PixelWidth = (w->col.CxMax - w->col.CxMin) / w->col.iXmax;
	w->col.PixelHeight = (w->col.CyMax - w->col.CyMin) / w->col.iYmax;
	w->col.IterationMax = 200;
	w->col.EscapeRadius = 2;
	w->col.ER2 = w->col.EscapeRadius * w->col.EscapeRadius;
}

static int	ft_coolor(int iter)
{
	int out;
	unsigned char *pt;

	out = 0;
	pt = (unsigned char *)&out;
	if (iter % 2 == 0)
		out = (255 - iter + ((255 - iter * 10) << 7) + (iter * 3 << 16)) & 0xFFFFFF;
	else
		out = (iter * 4 + ((iter + 100) << 8) + ((170 - iter * 2) << 16)) & 0xFFFFFF;
	return (out);
}

void	ft_coolbrot(t_mlx *w)
{
	t_man	*m;
	m = &w->col;
	m->actuel = 0;
	for (m->iY = 0;m->iY < m->iYmax; m->iY++)
	{
		m->Cy = m->CyMin + m->iY * m->PixelHeight;
		if (fabsl(m->Cy) < m->PixelHeight / 2)
			m->Cy = 0.0; /* Main antenna */
		for (m->iX = 0; m->iX < m->iXmax; m->iX++)
		{
			m->Cx = m->CxMin + m->iX * m->PixelWidth;
			/* initial value of orbit = critical point Z= 0 */
			m->Zx = 1.5;
			m->Zy = 0.7;
			m->Zx2 = m->Zx * m->Zx;
			m->Zy2 = m->Zy * m->Zy;
			m->Iteration = 0;
			while (m->Iteration < m->IterationMax && ((m->Zx2 + m->Zy2) < m->ER2))
			{
				m->Zy	= 2 * m->Zx * m->Zy + m->Cy;
				m->Zx	= m->Zx2 - m->Zy2 + m->Cx;
				m->Zx2	= m->Zx * m->Zx * tan(m->Zx);
				m->Zy2	= m->Zy * m->Zy;
				m->Iteration++;
			}
			if (m->Iteration != m->IterationMax)
					w->pic3[(m->iY * (LARG)) + m->iX] = ft_coolor(m->Iteration);
			m->actuel++;
		}
	}
	mlx_put_image_to_window(w->mlx, w->win3, w->img3.pt, 0, 0);
}
