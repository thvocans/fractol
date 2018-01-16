/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 15:47:16 by thvocans          #+#    #+#             */
/*   Updated: 2018/01/16 17:25:24 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_color(int iter)
{
	int				out;
	unsigned char	*pt;

	out = 0;
	pt = (unsigned char *)&out;
	pt[0] = (sin(0.1 * iter + 4) * 127 + 127);
	pt[1] = (sin(0.013 * iter + 3) * 200 + 50);
	pt[2] = (sin(0.01 * iter + 4) * 127 + 127);
	pt[3] = 0;
	return (out);
}
