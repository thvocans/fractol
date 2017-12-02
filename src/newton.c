/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:35:25 by thvocans          #+#    #+#             */
/*   Updated: 2017/12/02 03:56:05 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*
** Douady's rabbit
** z^2 + (-0.12 + 0.75i))
** -1.45 -> 1.45
** new = old - ( (old^3 - 1) / (3 * old^2));
** OR
** new = (2 * old * old * old + 1) / ( 3 * old * old);
**
*/


void	rabbit(t_mlx *w)
{
	double	winmin = -1.45;
	double	winmax = 1.45;
	double	size = abs(winmin) + abs(winmax);
	double	old[2]; //[0-2] == real | [1-3] == imaginary
	double	new[2]; //[0-2] == real | [1-3] == imaginary
	int		maxit = 100;
	int		i, x, y;
	
	y = -1;
	old = {0, 0};
	while (++y < HAUT)
	{
		x = -1;
		while (++x < LARG)
		{
			old[0] = winmin + (size * (x / LARG));
			old[2] = winmin + (size * (y / HAUT));
			for (int k = 0; k < maxit; k++)
			{
				new[0] = old[0] * old[0] - old[1] * old[1] -0.12;
				new[1] = 2 * old[0] + old[1] + 0.75;

			}
		}
	}
}
