/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 21:15:18 by thvocans          #+#    #+#             */
/*   Updated: 2018/01/16 17:25:48 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	man_mouse(int button, int x, int y, t_mlx *w)
{
	if ((button == 4 || button == 1) && x >= 0 && y >= 0)
		ft_man_zoom(w, x, y, 1.25);
	if ((button == 5 || button == 2) && x >= 0 && y >= 0)
		ft_man_zoom(w, x, y, 0.8);
	return (0);
}

int	jul_mouse(int button, int x, int y, t_mlx *w)
{
	if ((button == 4 || button == 1) && x >= 0 && y >= 0)
		ft_jul_zoom(&w->jul, x, y, 1.25);
	if ((button == 5 || button == 2) && x >= 0 && y >= 0)
		ft_jul_zoom(&w->jul, x, y, 0.8);
	clear_img(&w->pic2);
	ft_julia(w);
	return (0);
}

int	newton_mouse(int button, int x, int y, t_mlx *w)
{
	static int i = 0;

	if ((button == 4 || button == 1) && x >= 0 && y >= 0)
		ft_jul_zoom(&w->cos, x, y, 1.25);
	if ((button == 5 || button == 2) && x >= 0 && y >= 0)
		ft_jul_zoom(&w->cos, x, y, 0.8);
	if (i != 0 && i % 10 == 0)
		w->cos.maxit += 10;
	i++;
	clear_img(&w->pic3);
	ft_newton(w);
	return (0);
}

int	ft_move_mouse(int x, int y, t_mlx *w)
{
	static int ox = 0;
	static int oy = 0;
	static int flag = 0;

	if (flag == 0)
	{
		flag = 1;
		ox = x;
		oy = y;
	}
	if (w->jul.mouseon)
	{
		w->jul.cre += (float)(x - ox) / 1000;
		w->jul.cim += (float)(y - oy) / 1000;
		clear_img(&w->pic2);
		ft_julia(w);
		ox = x;
		oy = y;
	}
	return (0);
}
