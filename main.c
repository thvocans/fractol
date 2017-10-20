/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:59:32 by thvocans          #+#    #+#             */
/*   Updated: 2017/10/20 17:56:14 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_latent(/*int key,*/ t_mlx *w)
{
	ft_key(w);
	return (0);
}

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

void    clear_img(int **pic)
{
	int i;

	i = 0;
	while (i < (LARG * HAUT))
		pic[0][i++] = 0;
}

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

int		main(int ac, char **av)
{
	t_mlx	w;
	void	*p;

	p = &w;
	if (ac < 1)
		ft_error(NO_ARGS);
	ft_init_key(&w.key);
	w.mlx = mlx_init();
	w.win = mlx_new_window(w.mlx, LARG, HAUT, "You Shall Not Segfault");
	w.img.pt = mlx_new_image(w.mlx, LARG, HAUT);
	w.pic = (int*)mlx_get_data_addr(w.img.pt, &(w.img.bpp), &(w.img.ln),\
			&(w.img.end));
	av[0] = "";
	ft_init(&w.man);
	ft_mandelbrot(&w);
	mlx_do_key_autorepeatoff(&w);
	mlx_hook(w.win, 2, (1L << 0), &press, &w);
	mlx_hook(w.win, 3, (1L << 1), &release, &w);
	mlx_hook(w.win, 4, (1L << 2), &pressmouse, &w);
	//	mlx_hook(w.win, 5, (1L << 3), &releasemouse, &w);
	mlx_loop_hook(w.mlx, &ft_latent, &w);
	mlx_loop(w.mlx);
}
