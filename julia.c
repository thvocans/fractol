/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:33:48 by thvocans          #+#    #+#             */
/*   Updated: 2017/11/15 21:32:33 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**		The Julia set
**	Each point is equal to the previous point coordinates squared
**	plus c:
**	n + 1 = n2 + c 
**	Given the use of imaginary numbers we will need the use of a matrix
**	given z = a + bi:
**	Matrix form bi:	(a	-b) carre :	(aa + -bb	a-b + -ba) 
**					(b	 a)			(ba + ab	b-b + aa)
**	Matrix form bi:	(a	b) carre :	(aa + bc	ab + bd) 
**					(c	d)			(ca + dc	cb + dd)
**
*/

void	ft_julia(t_jul )
