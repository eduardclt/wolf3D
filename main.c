/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecloete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 10:50:16 by ecloete           #+#    #+#             */
/*   Updated: 2017/07/20 12:56:41 by ecloete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	initvar(t_values *v)
{
 	v->posX = 3;
	v->posY = 4;
	v->dirX = -1;
	v->dirY = 0;
	v->planeX = 0;
	v->planeY = 0.66;
	v->time = 0;
    v->x = 0;
    v->w = 512;
	v->h = 384;
	v->moveSpeed = 0.3;
	v->rotSpeed =  0.1;
}

int	main()
{
	t_values	v;

	printf("hello");
	initvar(&v);
	read_file("worldmap.txt", &v);
	v.m.mlx = mlx_init();
	v.m.win = mlx_new_window(v.m.mlx, v.w, v.h, "WOLF3D");
	printf("\nhi\n");
	raycasting(&v);
	//mlx_hook(v.m.win, 2, (1L << 0), readkeys, &v);
	mlx_key_hook(v.m.win, readkeys, &v);
	mlx_loop(v.m.mlx);
}
