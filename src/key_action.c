/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:07:21 by thvocans          #+#    #+#             */
/*   Updated: 2018/01/13 18:13:43 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/keyboard.h"
static inline int	ft_key2(t_mlx *w, void *win)
{
	if (K_LEFT && win == w->win3)
		w->cos.moveX -= 0.1 / w->cos.zoom;
	if (K_RIGHT && win == w->win3)
		w->cos.moveX += 0.1 / w->cos.zoom;
	if (K_UP && win == w->win3)
		w->cos.moveY -= 0.1 / w->cos.zoom;
	if (K_DOWN && win == w->win3)
		w->cos.moveY += 0.1 / w->cos.zoom;
	if (win == w->win3)
		ft_newton(w);
	return (0);
}
int					ft_key(t_mlx *w, void *win, int *pic)
{
	pic = 0;
	if (K_ESC)
		exit(0);
	if (K_LEFT && win == w->win2)
		w->jul.moveX -= 0.1 / w->jul.zoom;
	if (K_RIGHT && win == w->win2)
		w->jul.moveX += 0.1 / w->jul.zoom;
	if (K_UP && win == w->win2)
		w->jul.moveY -= 0.1 / w->jul.zoom;
	if (K_DOWN && win == w->win2)
		w->jul.moveY += 0.1 / w->jul.zoom;
	if (K_M && win == w->win2)
		w->jul.mouseon = w->jul.mouseon ? 0 : 1;
	if (win == w->win2)
		ft_julia(w);
	return (ft_key2(w, win));
}
