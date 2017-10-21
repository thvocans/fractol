/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 21:08:11 by thvocans          #+#    #+#             */
/*   Updated: 2017/10/20 21:13:00 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void	ft_init(t_man *m)
{
	m->iXmax = LARG;
	m->iYmax = HAUT;
	m->CxMin = -2.5;
	m->CxMax = 1.5;
	m->CyMin = -2.0;
	m->CyMax = 2.0;
	m->PixelWidth = (m->CxMax - m->CxMin) / m->iXmax;
	m->PixelHeight = (m->CyMax - m->CyMin) / m->iYmax;
	m->IterationMax = 200;
	m->EscapeRadius = 2;
	m->ER2 = m->EscapeRadius * m->EscapeRadius;
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
			{
				if (m->Iteration >= 150)
					w->pic[(m->iY * (LARG)) + m->iX] = 0xFFFFFF;
				else if (m->Iteration >= 100)
					w->pic[(m->iY * (LARG)) + m->iX] = 0xCCCCCC;
				else if (m->Iteration >= 50)
					w->pic[(m->iY * (LARG)) + m->iX] = 0x1D5E94;
				else if (m->Iteration >= 0)
					w->pic[(m->iY * (LARG)) + m->iX] = 0xff99ff;
			}
			m->actuel++;
		}
	}
	mlx_put_image_to_window(w->mlx, w->win, w->img.pt, 0, 0);
}

