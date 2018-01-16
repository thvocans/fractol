/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:39:27 by thvocans          #+#    #+#             */
/*   Updated: 2018/01/16 18:21:44 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	man_loop(t_mlx *w)
{
	w->cur_win = w->win1;
	w->cur_pic = w->pic1;
	mlx_hook(w->win1, 2, (1L << 0), &press_win1, w);
	mlx_hook(w->win1, 3, (1L << 1), &release_win1, w);
	mlx_hook(w->win1, 4, (1L << 2), &man_mouse, w);
	mlx_hook(w->win1, 17, (1L << 17), &ft_error, (void *)5);
}

void	jul_loop(t_mlx *w)
{
	w->cur_win = w->win2;
	w->cur_pic = w->pic2;
	mlx_hook(w->win2, 2, (1L << 0), &press_win2, w);
	mlx_hook(w->win2, 3, (1L << 1), &release_win2, w);
	mlx_hook(w->win2, 4, (1L << 2), &jul_mouse, w);
	mlx_hook(w->win2, 6, (1L << 7), &ft_move_mouse, w);
	mlx_hook(w->win2, 17, (1L << 17), &ft_error, (void *)5);
}

void	newton_loop(t_mlx *w)
{
	w->cur_win = w->win3;
	w->cur_pic = w->pic3;
	mlx_hook(w->win3, 2, (1L << 0), &press_win3, w);
	mlx_hook(w->win3, 3, (1L << 1), &release_win3, w);
	mlx_hook(w->win3, 4, (1L << 2), &newton_mouse, w);
	mlx_hook(w->win3, 17, (1L << 17), &ft_error, (void *)5);
}
