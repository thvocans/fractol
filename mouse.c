/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 21:15:18 by thvocans          #+#    #+#             */
/*   Updated: 2017/10/20 21:17:26 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	pressmouse(int button, int x, int y,  void *p)
{
	t_mlx	*w;
	w = (t_mlx *)p;

	long double	m_xy[2]; //XY dans referentiel 'window'
	static long double	size_a[2]; // Referentiel 'a' (pre zoom)
	long double size_b[2]; // Referentiel 'b' (post zoom)
	static long double m_ra[2]; //XY dans referentiel 'a'
	long double m_rb[2]; //XY dans ref post zoom
	long double	ra_rb[2]; //Ra XY minus Rb ref
	static int flag = 0;
	//cast input values
	m_xy[0] = (long double)x;
	m_xy[1] = (long double)y;
	printf("%d, %d\n",x, y);

	if (flag == 0)
	{
		size_a[0] = fabsl(w->man.CxMin) + fabsl(w->man.CxMax); // longueur ligne
		size_a[1] = fabsl(w->man.CyMin) + fabsl(w->man.CyMax); // hauteur colonne
		m_ra[0] = 0; //origin point 500,500
		m_ra[1] = 0;
		flag = 1;
	}
	size_b[0] = size_a[0] / 1.25; //x axis zoom step
	size_b[1] = size_a[1] / 1.25; //y axis zoom step
	if (button == 1)
	{
		clear_img(&w->pic);
		// x ref a = 'x input' rapporte a echelle 'ref a' en fct de cxmin
		m_ra[0] = (m_xy[0] / LARG * size_a[0]) + w->man.CxMin;
		m_ra[1] = (m_xy[1] / HAUT * size_a[1]) + w->man.CyMin;
		// x ref 'b' = 'x input' in 'ref b'
		m_rb[0] = (m_xy[0] / LARG * size_b[0]) - (size_b[0] / 2);
		m_rb[1] = (m_xy[1] / HAUT * size_b[1]) - (size_b[1] / 2);
		ra_rb[0] = m_ra[0] - m_rb[0];
		ra_rb[1] = m_ra[1] - m_rb[1];
		w->man.CxMin = (-size_b[0] / 2) + ra_rb[0];
		w->man.CxMax = (size_b[0] / 2) + ra_rb[0];
		w->man.CyMin = (-size_b[1] / 2) + ra_rb[1];
		w->man.CyMax = (size_b[1] / 2) + ra_rb[1];
	//printf("%Lf, %Lf, %Lf, %Lf\n",w->man.CxMin, w->man.CxMax, w->man.CyMin, w->man.CyMax);
		w->man.PixelWidth = (w->man.CxMax - w->man.CxMin) / w->man.iXmax;
		w->man.PixelHeight = (w->man.CyMax - w->man.CyMin) / w->man.iYmax;
		ft_mandelbrot(w);
		size_a[0] = size_b[0];
		size_a[1] = size_b[1];
	}
	if (button == 2)
	{
		clear_img(&w->pic);
		ft_init(&w->man);
		flag = 0;
		ft_mandelbrot(w);
	}
	if (button == 3)
	{
	}
	return (0);
}
