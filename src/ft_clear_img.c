/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:32:12 by thvocans          #+#    #+#             */
/*   Updated: 2018/01/16 17:34:26 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	clear_img(int **pic)
{
	int i;

	i = 0;
	while (i < (LARG * HAUT))
		pic[0][i++] = 0;
}
