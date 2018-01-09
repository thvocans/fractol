/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 18:55:21 by thvocans          #+#    #+#             */
/*   Updated: 2018/01/09 19:54:14 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_jul_zoom(t_mlx *w, long double x, long double y , float zoom)
{
	t_jul *j;

	j = &w->jul;
	double za[2];
	double zb[2];
	za[0] = 1.5 * (x - w->mid[0]) / (j->zoom * w->mid[0]) + j->moveX;
	za[1] = (y - w->mid[1]) / (0.5 * j->zoom * HAUT) + j->moveY;
	j->zoom *= zoom;
	zb[0] = 1.5 * (x - w->mid[0]) / (j->zoom * w->mid[0]) + j->moveX;
	zb[1] = (y - w->mid[1]) / (0.5 * j->zoom * HAUT) + j->moveY;
	j->moveX += za[0] - zb[0];
	j->moveY += za[1] - zb[1];
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
	w->man.CxMin = (-size_b[0] / 2) + (m_ra[0] - m_rb[0]);
	w->man.CxMax = (size_b[0] / 2) + (m_ra[0] - m_rb[0]);
	w->man.CyMin = (-size_b[1] / 2) + (m_ra[1] - m_rb[1]);
	w->man.CyMax = (size_b[1] / 2) + (m_ra[1] - m_rb[1]);
	w->man.PixelWidth = (w->man.CxMax - w->man.CxMin) / w->man.iXmax;
	w->man.PixelHeight = (w->man.CyMax - w->man.CyMin) / w->man.iYmax;
	clear_img(&w->pic1);
	ft_mandelbrot(w);
	size_a[0] = size_b[0];
	size_a[1] = size_b[1];
}

void	ft_cool_zoom(t_mlx *w, long double x, long double y, float zoom)
{
	static long double	size_a[2]; // Referentiel 'a' (pre zoom)
	static long double	m_ra[2]; //XY dans referentiel 'a'
	static int			flag = 0;
	long double			size_b[2]; // Referentiel 'b' (post zoom)
	long double			m_rb[2]; //XY dans ref post zoom

	printf("%d, %d\n",(int)x, (int)y);

	if (flag == 0)
	{
		size_a[0] = fabsl(w->col.CxMin) + fabsl(w->col.CxMax); // longueur ligne
		size_a[1] = fabsl(w->col.CyMin) + fabsl(w->col.CyMax); // hauteur colonne
		m_ra[0] = 0; //origin point 500,500
		m_ra[1] = 0;
		flag = 1;
	}
	size_b[0] = size_a[0] / zoom; //x axis zoom step
	size_b[1] = size_a[1] / zoom; //y axis zoom step
// x ref a = 'x input' rapporte a echelle 'ref a' en fct de cxmin
	m_ra[0] = (x / LARG * size_a[0]) + w->col.CxMin;
	m_ra[1] = (y / HAUT * size_a[1]) + w->col.CyMin;
// x ref 'b' = 'x input' in 'ref b'
	m_rb[0] = (x / LARG * size_b[0]) - (size_b[0] / 2);
	m_rb[1] = (y / HAUT * size_b[1]) - (size_b[1] / 2);
	w->col.CxMin = (-size_b[0] / 2) + (m_ra[0] - m_rb[0]);
	w->col.CxMax = (size_b[0] / 2) + (m_ra[0] - m_rb[0]);
	w->col.CyMin = (-size_b[1] / 2) + (m_ra[1] - m_rb[1]);
	w->col.CyMax = (size_b[1] / 2) + (m_ra[1] - m_rb[1]);
	w->col.PixelWidth = (w->col.CxMax - w->col.CxMin) / w->col.iXmax;
	w->col.PixelHeight = (w->col.CyMax - w->col.CyMin) / w->col.iYmax;
	clear_img(&w->pic3);
	ft_coolbrot(w);
	size_a[0] = size_b[0];
	size_a[1] = size_b[1];
}
