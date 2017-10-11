/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 19:17:43 by thvocans          #+#    #+#             */
/*   Updated: 2017/10/07 20:33:54 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keyboard.h"

int		ft_key(t_mlx *w)
{
	static int x = 0;
	static int y = 0;
	static int pc = 0xFFFFFF;

	if (K_ESC)
		exit(0);
	if (K_LEFT && (w->pic[LARG * y + --x] = pc) == pc)
		mlx_put_image_to_window(w->mlx, w->win, w->img.pt, 0,0);
	if (K_RIGHT && (w->pic[LARG * y + ++x] = pc) == pc)
		mlx_put_image_to_window(w->mlx, w->win, w->img.pt, 0,0);
	if (K_DOWN && (w->pic[LARG * ++y + x] = pc) == pc)
		mlx_put_image_to_window(w->mlx, w->win, w->img.pt, 0,0);
	if (K_UP && (w->pic[LARG * --y + x] = pc) == pc)
		mlx_put_image_to_window(w->mlx, w->win, w->img.pt, 0,0);
	return (0);
}

int					press(int key, void *p)
{
	t_mlx *w;

	w = (t_mlx*)p;
	w->key.oct = key / 8;
	w->key.bit = key % 8;
	w->key.mask = (char)(1 << w->key.bit);
	w->key.down[w->key.oct] = w->key.down[w->key.oct] | w->key.mask;
	ft_key(w);
	return (0);
}

int					release(int key, void *p)
{
	t_mlx *w;

	w = (t_mlx*)p;
	w->key.oct = key / 8;
	w->key.bit = key % 8;
	w->key.mask = (char)(1 << w->key.bit);
	w->key.down[w->key.oct] = w->key.down[w->key.oct] ^ w->key.mask;
	ft_key(w);
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