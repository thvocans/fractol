/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:28:48 by thvocans          #+#    #+#             */
/*   Updated: 2017/11/23 17:30:58 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

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
