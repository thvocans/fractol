/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:07:21 by thvocans          #+#    #+#             */
/*   Updated: 2018/01/12 22:18:44 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/keyboard.h"

int		ft_key(t_mlx *w, void *win, int *pic)
{
	if (K_ESC)
		exit(0);
	if (K_LEFT)
		mlx_put_image_to_window(w->mlx, win, pic, 0, 0);
	if (K_RIGHT)
		mlx_put_image_to_window(w->mlx, win, pic, 0, 0);
	if (K_DOWN)
		mlx_put_image_to_window(w->mlx, win, pic, 0, 0);
	if (K_UP)
		mlx_put_image_to_window(w->mlx, win, pic, 0, 0);
	if (K_M)
		w->jul.mouseon = w->jul.mouseon ? 0 : 1;
	return (0);
}
