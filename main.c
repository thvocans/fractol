/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:59:32 by thvocans          #+#    #+#             */
/*   Updated: 2017/10/11 21:56:53 by thvocans         ###   ########.fr       */
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
	m->iXmax = 640;
	m->iYmax = 480;
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
				m->color = (unsigned char *)&w->pic[(m->iY * (LARG)) + m->iX];
				m->color[0] = 0;	//B
				m->color[1] = 0;	//G
				m->color[2] = 255;	//R
				m->color[3] = 128;	//A
			}
			m->actuel++;
		}
	}
	mlx_put_image_to_window(w->mlx, w->win, w->img.pt, 0, 0);
}

int	pressmouse(int button, void *p)
{
	t_mlx	*w;
	w = (t_mlx *)p;
	if (w)
		printf("%p\n", p);
	if (button == 1)
	{
	}
	return (0);
}

void	ft_test(t_man *m)
{
	printf("%Lf\n", m->CxMin);
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
	printf("%Lf\n", w.man.CxMin);
	ft_init(&w.man);
	ft_mandelbrot(&w);
	ft_test(&w.man);
	printf("main:%p\n", p);
	mlx_do_key_autorepeatoff(&w);
	mlx_hook(w.win, 2, (1L << 0), &press, &w);
	mlx_hook(w.win, 3, (1L << 1), &release, &w);
	mlx_hook(w.win, 4, (1L << 2), &press, &w);
//	mlx_hook(w.win, 5, (1L << 3), &releasemouse, &w);
//	mlx_loop_hook(w.mlx, &ft_latent, &w);
	mlx_loop(w.mlx);
}
