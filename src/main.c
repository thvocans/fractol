/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:59:32 by thvocans          #+#    #+#             */
/*   Updated: 2018/01/13 17:37:09 by thvocans         ###   ########.fr       */
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

void	ft_loop(t_mlx *w)
{
	mlx_hook(w->cur_win, 2, (1L << 0), &press_win, w);
	mlx_hook(w->cur_win, 3, (1L << 1), &release_win, w);
	if (w->cur_win == w->win1)
		mlx_hook(w->cur_win, 4, (1L << 2), &man_mouse, w);
	if (w->cur_win == w->win2)
	{
		mlx_hook(w->cur_win, 6, (1L << 7), &ft_move_mouse, w);
		mlx_hook(w->cur_win, 4, (1L << 2), &jul_mouse, w);
	}
	if (w->cur_win == w->win3)
		mlx_hook(w->cur_win, 4, (1L << 2), &newton_mouse, w);
	mlx_hook(w->cur_win, 17, (1L << 17), &ft_error, (void *)5);
}

void	man_loop(t_mlx *w)
{
	printf("mandelbrot loop\n");
	w->cur_win = w->win1;
	w->cur_pic = w->pic1;
//	ft_loop(w);
	mlx_hook(w->win1, 2, (1L << 0), &press_win1, w);
	mlx_hook(w->win1, 3, (1L << 1), &release_win1, w);
	mlx_hook(w->win1, 4, (1L << 2), &man_mouse, w);
	mlx_hook(w->win1, 17, (1L << 17), &ft_error, (void *)5);
}

void	jul_loop(t_mlx *w)
{
	printf("julia loop\n");
	w->cur_win = w->win2;
	w->cur_pic = w->pic2;
//	ft_loop(w);
	mlx_hook(w->win2, 2, (1L << 0), &press_win2, w);
	mlx_hook(w->win2, 3, (1L << 1), &release_win2, w);
	mlx_hook(w->win2, 4, (1L << 2), &jul_mouse, w);
	mlx_hook(w->win2, 6, (1L << 7), &ft_move_mouse, w);
	mlx_hook(w->win2, 17, (1L << 17), &ft_error, (void *)5);
}

void	newton_loop(t_mlx *w)
{
	printf("newton loop\n");
	w->cur_win = w->win3;
	w->cur_pic = w->pic3;
//	ft_loop(w);
	mlx_hook(w->win3, 2, (1L << 0), &press_win3, w);
	mlx_hook(w->win3, 3, (1L << 1), &release_win3, w);
	mlx_hook(w->win3, 4, (1L << 2), &newton_mouse, w);
	mlx_hook(w->win3, 17, (1L << 17), &ft_error, (void *)5);
}

int		mandel_main(t_mlx *w)
{
	printf("mandelbrot main\n");
	w->win1 = mlx_new_window(w->mlx, LARG, HAUT, "Mandelbread");
	w->img1.pt = mlx_new_image(w->mlx, LARG, HAUT);
	w->pic1 = (int*)mlx_get_data_addr(w->img1.pt, &(w->img1.bpp),\
			&(w->img1.ln), &(w->img1.end));
	ft_mandel_init(w);
	ft_mandelbrot(w);
	mlx_put_image_to_window(w->mlx, w->win1, w->img1.pt, 0, 0);
	man_loop(w);
	return (1);
}

int		julia_main(t_mlx *w)
{
	printf("julia main\n");
	w->win2 = mlx_new_window(w->mlx, LARG, HAUT, "Julia da best");
	w->img2.pt = mlx_new_image(w->mlx, LARG, HAUT);
	w->pic2 = (int*)mlx_get_data_addr(w->img2.pt, &(w->img2.bpp),\
			&(w->img2.ln), &(w->img2.end));
	ft_jul_init(w);
	ft_julia(w);
	mlx_put_image_to_window(w->mlx, w->win2, w->img2.pt, 0, 0);
	jul_loop(w);
	return (1);
}

int		newton_main(t_mlx *w)
{
	printf("newton main\n");
	w->win3 = mlx_new_window(w->mlx, LARG, HAUT, "cosh newton");
	w->img3.pt = mlx_new_image(w->mlx, LARG, HAUT);
	w->pic3 = (int*)mlx_get_data_addr(w->img3.pt, &(w->img3.bpp),\
			&(w->img3.ln), &(w->img3.end));
	ft_newton_init(w);
	ft_newton(w);
	mlx_put_image_to_window(w->mlx, w->win3, w->img3.pt, 0, 0);
	newton_loop(w);
	return (1);
}


int		main(int ac, char **av)
{
	t_mlx	w;
	int		*ag;
	
	ag = ft_args_check(ac, av);
	ft_init_key(&w.key);
	w.mlx = mlx_init();
	w.jul.mouseon = 1;
	av[0] = "";
	if (ag[0])
		mandel_main(&w);
	if (ag[1])
		julia_main(&w);
	if (ag[2])
		newton_main(&w);
	mlx_do_key_autorepeatoff(&w);
	mlx_loop(w.mlx);
}
