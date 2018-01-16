/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 18:55:21 by thvocans          #+#    #+#             */
/*   Updated: 2018/01/16 18:14:58 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_jul_zoom(t_jul *j, long double x, long double y, float zoom)
{
	double za[2];
	double zb[2];

	za[0] = 1.5 * (x - j->mid[0]) / (j->zoom * j->mid[0]) + j->movex;
	za[1] = (y - j->mid[1]) / (0.5 * j->zoom * HAUT) + j->movey;
	j->zoom *= zoom;
	zb[0] = 1.5 * (x - j->mid[0]) / (j->zoom * j->mid[0]) + j->movex;
	zb[1] = (y - j->mid[1]) / (0.5 * j->zoom * HAUT) + j->movey;
	j->movex += za[0] - zb[0];
	j->movey += za[1] - zb[1];
}

void	ft_mz2(t_mlx *w, long double *size_b, long double *m_ra)
{
	long double			m_rb[2];

	m_rb[0] = (size_b[4] / LARG * size_b[0]) - size_b[2];
	m_rb[1] = (size_b[5] / HAUT * size_b[1]) - size_b[3];
	w->man.xmin = (m_ra[0] - m_rb[0]) - size_b[2];
	w->man.xmax = (m_ra[0] - m_rb[0]) + size_b[2];
	w->man.ymin = (m_ra[1] - m_rb[1]) - size_b[3];
	w->man.ymax = (m_ra[1] - m_rb[1]) + size_b[3];
	w->man.pi_w = (w->man.xmax - w->man.xmin) / w->man.ixmax;
	w->man.pi_h = (w->man.ymax - w->man.ymin) / w->man.iymax;
	clear_img(&w->pic1);
	ft_mandelbrot(w);
}

void	ft_man_zoom(t_mlx *w, long double x, long double y, float zoom)
{
	static long double	size_a[2];
	static long double	m_ra[2];
	static int			flag = 0;
	long double			size_b[6];

	if (flag == 0)
	{
		size_a[0] = fabsl(w->man.xmin) + fabsl(w->man.xmax);
		size_a[1] = fabsl(w->man.ymin) + fabsl(w->man.ymax);
		m_ra[0] = 0;
		m_ra[1] = 0;
		flag = 1;
	}
	size_b[0] = size_a[0] / zoom;
	size_b[1] = size_a[1] / zoom;
	m_ra[0] = (x / LARG * size_a[0]) + w->man.xmin;
	m_ra[1] = (y / HAUT * size_a[1]) + w->man.ymin;
	size_a[0] = size_b[0];
	size_a[1] = size_b[1];
	size_b[2] = size_b[0] / 2;
	size_b[3] = size_b[1] / 2;
	size_b[4] = x;
	size_b[5] = y;
	ft_mz2(w, size_b, m_ra);
}
