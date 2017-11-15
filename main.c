/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:59:32 by thvocans          #+#    #+#             */
/*   Updated: 2017/11/06 17:40:17 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_latent(/*int key,*/ t_mlx *w)
{
	ft_key(w);
	return (0);
}

void    clear_img(int **pic)
{
	int i;

	i = 0;
	while (i < (LARG * HAUT))
		pic[0][i++] = 0;
}


int		main(int ac, char **av)
{
	t_mlx	w;
	void	*p;

	p = &w;
	if (ac < 1)
		ft_error(NO_ARGS);
	ft_init_key(&w.key);
	w.mlx = mlx_init();
	w.win = mlx_new_window(w.mlx, LARG, HAUT, "You Shall Not Segfault");
	w.img.pt = mlx_new_image(w.mlx, LARG, HAUT);
	w.pic = (int*)mlx_get_data_addr(w.img.pt, &(w.img.bpp), &(w.img.ln),\
			&(w.img.end));
	av[0] = "";
	ft_init(&w.man);
	ft_mandelbrot(&w);
	mlx_do_key_autorepeatoff(&w);
	mlx_hook(w.win, 2, (1L << 0), &press, &w);
	mlx_hook(w.win, 3, (1L << 1), &release, &w);
	mlx_hook(w.win, 4, (1L << 2), &pressmouse, &w);
	//	mlx_hook(w.win, 5, (1L << 3), &releasemouse, &w);
	mlx_loop_hook(w.mlx, &ft_latent, &w);
	mlx_loop(w.mlx);
}
