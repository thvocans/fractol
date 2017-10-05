/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 19:17:43 by thvocans          #+#    #+#             */
/*   Updated: 2017/10/05 15:49:57 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_key(t_mlx *w)
{
//	t_mlx *w;
	static int x = 0;
	static int y = 0;
	static int pc = 0xFFFFFF;

//	w = (t_mlx*)p;
	if (w->key_down[53])
		exit(0);
	if ((w->key_down[123]) && (w->pic[LARG * y + --x] = pc) == pc) //left 123
	{
		mlx_put_image_to_window(w->mlx, w->win, w->img.pt, 0,0);
	}
	if ((w->key_down[124]) && (w->pic[LARG * y + ++x] = pc) == pc) // right 124
		mlx_put_image_to_window(w->mlx, w->win, w->img.pt, 0,0);
	if ((w->key_down[125]) && (w->pic[LARG * ++y + x] = pc) == pc) // down
		mlx_put_image_to_window(w->mlx, w->win, w->img.pt, 0,0);
	if ((w->key_down[126]) && (w->pic[LARG * --y + x] = pc) == pc) // up
		mlx_put_image_to_window(w->mlx, w->win, w->img.pt, 0,0);
	return (0);
}

int		press(int key, void *p)
{
	t_mlx *w;

	w = (t_mlx*)p;
	w->key_down[key] = 1;
	printf("down:%d\n",key);
	//	printf("m:%d oct:%d bit:%d \n",w->key.mask, w->key.oct, w->key.bit);
//	ft_key(key, p);
	return (0);
}

int		release(int key, void *p)
{
	t_mlx *w;

	printf("		relase: %d\n",key);
	w = (t_mlx*)p;
	w->key_down[key] = 0;
//	ft_key(key, p);
	return (0);
}

void	ft_init_key(t_mlx *w)
{
	int i;

	i = 0;
	while (i < 300)
		w->key_down[i++] = 0;
}
