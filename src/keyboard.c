/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 19:17:43 by thvocans          #+#    #+#             */
/*   Updated: 2017/11/22 20:17:51 by thvocans         ###   ########.fr       */
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
	return (0);
}

int					press(int key, t_mlx *w)
{
	w->key.oct = key / 8;
	w->key.bit = key % 8;
	w->key.mask = (char)(1 << w->key.bit);
	w->key.down[w->key.oct] = w->key.down[w->key.oct] | w->key.mask;
//	ft_key(w);
	return (0);
}

int					release(int key, t_mlx *w)
{
	w->key.oct = key / 8;
	w->key.bit = key % 8;
	w->key.mask = (char)(1 << w->key.bit);
	w->key.down[w->key.oct] = w->key.down[w->key.oct] ^ w->key.mask;
//	ft_key(w);
	return (0);
}

void				ft_init_key(t_key *key)
{
	unsigned char i;

	key->pt = (unsigned int*)key->down;
	i = 0;
	while (i < 10)
		key->pt[i++] = 0;
}
