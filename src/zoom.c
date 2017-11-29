/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 18:55:21 by thvocans          #+#    #+#             */
/*   Updated: 2017/11/29 18:18:05 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_jul_zoom(t_mlx *w, long double x, long double y , float zoom)
{
	t_jul *j;

	j = &w->jul;
	double za[2];
	double zb[2];
	double zba[2];
	za[0] = 1.5 * (x - w->mid[0]) / (j->zoom * w->mid[0]) + j->moveX;
	za[1] = (y - HAUT / 2) / (0.5 * j->zoom * HAUT) + j->moveY;
	j->zoom *= zoom;
	zb[0] = 1.5 * (x - w->mid[0]) / (j->zoom * w->mid[0]) + j->moveX;
	zb[1] = (y - HAUT / 2) / (0.5 * j->zoom * HAUT) + j->moveY;
	zba[0] = za[0] - zb[0];
	zba[1] = za[1] - zb[1];
	j->moveX += zba[0];
	j->moveY += zba[1];
	clear_img(&w->pic2);
	ft_julia(w);
}

void	ft_man_zoom(t_mlx *w, long double x, long double y, float zoom)
{
	static long double	size_a[2]; // Referentiel 'a' (pre zoom)
	static long double	m_ra[2]; //XY dans referentiel 'a'
	static int			flag = 0;
	long double			size_b[2]; // Referentiel 'b' (post zoom)
	long double			m_rb[2]; //XY dans ref post zoom
	long double			ra_rb[2]; //Ra XY minus Rb ref

	printf("%d, %d\n",(int)x, (int)y);

	if (flag == 0)
	{
		size_a[0] = fabsl(w->man.CxMin) + fabsl(w->man.CxMax); // longueur ligne
		size_a[1] = fabsl(w->man.CyMin) + fabsl(w->man.CyMax); // hauteur colonne
		m_ra[0] = 0; //origin point 500,500
		m_ra[1] = 0;
		flag = 1;
	}
	size_b[0] = size_a[0] / zoom; //x axis zoom step
	size_b[1] = size_a[1] / zoom; //y axis zoom step
// x ref a = 'x input' rapporte a echelle 'ref a' en fct de cxmin
	m_ra[0] = (x / LARG * size_a[0]) + w->man.CxMin;
	m_ra[1] = (y / HAUT * size_a[1]) + w->man.CyMin;
// x ref 'b' = 'x input' in 'ref b'
	m_rb[0] = (x / LARG * size_b[0]) - (size_b[0] / 2);
	m_rb[1] = (y / HAUT * size_b[1]) - (size_b[1] / 2);
	ra_rb[0] = m_ra[0] - m_rb[0];
	ra_rb[1] = m_ra[1] - m_rb[1];
	w->man.CxMin = (-size_b[0] / 2) + ra_rb[0];
	w->man.CxMax = (size_b[0] / 2) + ra_rb[0];
	w->man.CyMin = (-size_b[1] / 2) + ra_rb[1];
	w->man.CyMax = (size_b[1] / 2) + ra_rb[1];
	w->man.PixelWidth = (w->man.CxMax - w->man.CxMin) / w->man.iXmax;
	w->man.PixelHeight = (w->man.CyMax - w->man.CyMin) / w->man.iYmax;
	clear_img(&w->pic1);
	ft_mandelbrot(w);
	size_a[0] = size_b[0];
	size_a[1] = size_b[1];
}
