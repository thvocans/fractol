/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thvocans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 18:29:19 by thvocans          #+#    #+#             */
/*   Updated: 2017/10/07 20:38:10 by thvocans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define LARG 640
# define HAUT 480

# include "sierra/mlx.h"
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct s_img	t_img;
typedef struct s_key	t_key;
typedef struct s_man	t_man;
typedef struct s_mlx	t_mlx;

struct	s_img
{
	void	*pt;

	int		ln;
	int		bpp;
	int		end;
};

struct	s_key
{
	unsigned char	down[40];
	short			oct;
	short			bit;
	short			mask;
	unsigned int	*pt;
};

struct	s_man
{
};

struct	s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		*pic;
	
	t_man	mandel;
	t_key	key;
	int		key_down[300];
};

int		press(int key, void *p);
int		release(int key, void *p);
void	ft_init_key(t_key *key);
int		ft_key(t_mlx *w);

#endif
