/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 19:17:43 by thvocans          #+#    #+#             */
/*   Updated: 2018/01/16 17:25:45 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/keyboard.h"

static inline void	ft_key_mask(t_mlx *w, int key)
{
	w->key.oct = key / 8;
	w->key.bit = key % 8;
	w->key.mask = (char)(1 << w->key.bit);
}

/*
** generic press and release functions
*/

int					press_win(int key, t_mlx *w)
{
	ft_key_mask(w, key);
	w->key.down[w->key.oct] = w->key.down[w->key.oct] | w->key.mask;
	ft_key(w, w->cur_win, w->cur_pic);
	return (0);
}

int					release_win(int key, t_mlx *w)
{
	ft_key_mask(w, key);
	w->key.down[w->key.oct] = w->key.down[w->key.oct] ^ w->key.mask;
	ft_key(w, w->cur_win, w->cur_pic);
	return (0);
}

/*
** window 1 press and release functions
*/

int					press_win1(int key, t_mlx *w)
{
	ft_key_mask(w, key);
	w->key.down[w->key.oct] = w->key.down[w->key.oct] | w->key.mask;
	ft_key(w, w->win1, w->pic1);
	return (0);
}

int					release_win1(int key, t_mlx *w)
{
	ft_key_mask(w, key);
	w->key.down[w->key.oct] = w->key.down[w->key.oct] ^ w->key.mask;
	ft_key(w, w->win1, w->pic1);
	return (0);
}
