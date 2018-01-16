/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 21:37:57 by thvocans          #+#    #+#             */
/*   Updated: 2018/01/16 14:17:29 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int *ft_args_check(int ac, char **av)
{
	int *out;
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (ac < 2)
	{
		ft_putstr("usage :\tfractol param1 param2 ...\n");
		ft_putstr("  params: julia mandelbrot newton\n");
		exit(1);
	}
	if (!(out = ft_memalloc(sizeof(int) * 8)))
		ft_error(NO_MEM);
	while (++i < ac)
	{
		if (ft_strequ(av[i], "mandelbrot"))
			out[0] = 1;
		if (ft_strequ(av[i], "julia"))
			out[1] = 1;
		if (ft_strequ(av[i], "newton"))
			out[2] = 1;
	}
	i = 0;
	while (i < 8)
		if (out[i++] != 0)
			flag = 1;
	if (flag == 0)
		ft_error(NO_ARGS);
	return (out);
}
