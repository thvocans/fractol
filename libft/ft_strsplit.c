/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:45:37 by thvocans          #+#    #+#             */
/*   Updated: 2017/05/10 20:01:01 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_malloc(char const *str, t_split *var, char c)
{
	int i;
	int len;

	i = 0;
	len = 0;
	var->i = 0;
	var->j = 0;
	var->k = 0;
	while (str[len])
	{
		if (str[len] != c && (len == 0 || str[len - 1] == c))
			var->k++;
		len++;
	}
	if (!(var->out = malloc(sizeof(var->out) * (var->k + 1))))
		return (0);
	while (i < var->k)
		if (!((var->out[i++]) = malloc(sizeof(char) * len)))
			return (0);
	var->k = 0;
	return (len);
}

char			**ft_strsplit(char const *str, char c)
{
	t_split	var;

	if (str && c)
	{
		var.len = ft_malloc(str, &var, c);
		if (var.len == 0 && !(var.out))
			return (NULL);
		while (str[var.i] == c)
			var.i++;
		while (str[var.i])
		{
			while (!(str[var.i] == c) && str[var.i])
				var.out[var.k][var.j++] = str[var.i++];
			while (str[var.i] == c)
				var.i++;
			var.out[var.k++][var.j] = '\0';
			var.j = 0;
		}
		var.out[var.k] = NULL;
		return (var.out);
	}
	return (NULL);
}
