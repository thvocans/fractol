/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:59:32 by thvocans          #+#    #+#             */
/*   Updated: 2017/11/22 20:35:01 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*int	ft_latent(t_mlx *w)
{
	ft_key(w);
	return (0);
}*/

void    clear_img(int **pic)
{
	int i;

	i = 0;
	while (i < (LARG * HAUT))
		pic[0][i++] = 0;
}

void	ft_hook(t_mlx *w, void *win, int *pic)
{
		mandel_main(&w);
		julia_main(&w);
	mlx_hook(win, 2, (1L << 0), &press, w);
	mlx_hook(win, 3, (1L << 1), &release, w);
	mlx_hook(win, 4, (1L << 2), &pressmouse, w);
	mlx_hook(win, 6, (1L << 7), &movemouse, w);
//	mlx_hook(win, 5, (1L << 3), &releasemouse, &w);
//	mlx_loop_hook(w->mlx, &ft_latent, &w);
	ft_key(w, win, pic);
}

void	mandel_main(t_mlx *w)
{
	w->win1 = mlx_new_window(w->mlx, LARG, HAUT, "Mandelcute");
	w->img1.pt = mlx_new_image(w->mlx, LARG, HAUT);
	w->pic1 = (int*)mlx_get_data_addr(w->img1.pt, &(w->img1.bpp),\
			&(w->img1.ln), &(w->img1.end));
	ft_mandel_init(&w->man);
	ft_mandelbrot(w);
	mlx_put_image_to_window(w->mlx, w->win1, w->img1.pt, 0, 0);
}

void	julia_main(t_mlx *w)
{
	w->win2 = mlx_new_window(w->mlx, LARG, HAUT, "Julia da best");
	w->img2.pt = mlx_new_image(w->mlx, LARG, HAUT);
	w->pic2 = (int*)mlx_get_data_addr(w->img2.pt, &(w->img2.bpp),\
			&(w->img2.ln), &(w->img2.end));
	ft_jul_init(&w->jul);
	ft_julia(w);
	mlx_put_image_to_window(w->mlx, w->win2, w->img2.pt, 0, 0);
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
	av[0] = "";
//	if (1)
//	{
	printf("test\n");
//	}
	mlx_do_key_autorepeatoff(&w);
//	ft_hook(&w, w.win1, w.pic1);
	ft_hook(&w, w.win2, w.pic2);
	mlx_loop(w->mlx);
}
