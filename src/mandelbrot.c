/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 21:08:11 by thvocans          #+#    #+#             */
/*   Updated: 2017/11/29 18:11:12 by thvocans         ###   ########.fr       */
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

void	ft_mandel_init(t_mlx *w)
{
	w->mid[0] = LARG / 2;
	w->mid[1] = HAUT / 2;
	w->man.iXmax = LARG;
	w->man.iYmax = HAUT;
	w->man.CxMin = -2.5;
	w->man.CxMax = 1.5;
	w->man.CyMin = -2.0;
	w->man.CyMax = 2.0;
	w->man.PixelWidth = (w->man.CxMax - w->man.CxMin) / w->man.iXmax;
	w->man.PixelHeight = (w->man.CyMax - w->man.CyMin) / w->man.iYmax;
	w->man.IterationMax = 200;
	w->man.EscapeRadius = 2;
	w->man.ER2 = w->man.EscapeRadius * w->man.EscapeRadius;
}

int	ft_color(int iter)
{
	int out;
	unsigned char *pt;

	out = 0;
	pt = (unsigned char *)&out;
	if (iter % 2 == 0)
		out = (iter + (iter * 3 << 8) + (iter * 5 << 8)) & 0xFFFFFF;
	else
		out = (iter * 4 + (iter * 2 << 7) + (iter * 3 << 7)) & 0xFFFFFF;
	return (out);
}

void	ft_mandelbrot(t_mlx *w)
{
	t_man	*m;
	m = &w->man;
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
			m->Zx = 0.0;
			m->Zy = 0.0;
			m->Zx2 = m->Zx * m->Zx;
			m->Zy2 = m->Zy * m->Zy;
			m->Iteration = 0;
			while (m->Iteration < m->IterationMax && ((m->Zx2 + m->Zy2) < m->ER2))
			{
				m->Zy	= 2 * m->Zx * m->Zy + m->Cy;
				m->Zx	= m->Zx2 - m->Zy2 + m->Cx;
				m->Zx2	= m->Zx * m->Zx;
				m->Zy2	= m->Zy * m->Zy;
				m->Iteration++;
			}
			if (m->Iteration != m->IterationMax)
					w->pic1[(m->iY * (LARG)) + m->iX] = ft_color(m->Iteration);
			m->actuel++;
		}
	}
	mlx_put_image_to_window(w->mlx, w->win1, w->img1.pt, 0, 0);
}
