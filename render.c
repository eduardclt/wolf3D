/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecloete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 11:50:31 by ecloete           #+#    #+#             */
/*   Updated: 2017/07/17 11:50:32 by ecloete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	render(t_values *v)
{
	int k;
	int i;
	int g;

	k = v->drawStart;
	while (k <= v->drawEnd)
	{	
		mlx_pixel_put(v->m.mlx, v->m.win, v->x, k, v->colour);
		k++;
	}
	i = k;
	while ( i < v->h)
	{
		mlx_pixel_put(v->m.mlx, v->m.win, v->x, i, 0x00403C3C);
		i++;
	}
	g = v->drawStart;
	while (g >= 0)
	{
		mlx_pixel_put(v->m.mlx, v->m.win, v->x, g, 0x00C5BDBD);
		g--;
	}
}
