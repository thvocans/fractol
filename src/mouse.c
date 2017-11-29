/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 21:15:18 by thvocans          #+#    #+#             */
/*   Updated: 2017/11/28 23:26:29 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	man_mouse(int button, int x, int y, t_mlx *w)
{
	if (button == 4 && x >= 0 && y >= 0)
		ft_man_zoom(w, x, y, 1.25);
	if (button == 5 && x >= 0 && y >= 0)
		ft_man_zoom(w, x, y, 0.8);
	return (0);
}

int jul_mouse(int button, int x, int y, t_mlx *w)
{
	if (button == 1 && x >= 0 && y >= 0)
		ft_jul_zoom(w, x, y, 1.25);
	if (button == 2 && x >= 0 && y >= 0)
		ft_jul_zoom(w, x, y, 0.8);
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
	w->jul.cRe += (float)(x - ox) / 1000;
	w->jul.cIm += (float)(y - oy) / 1000;

//	printf("%f, %f\n", w->jul.cRe, w->jul.cIm);
	clear_img(&w->pic2);
	ft_julia(w);
	ox = x;
	oy = y;
	return (0);
}
