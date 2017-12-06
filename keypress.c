/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecloete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 10:50:40 by ecloete           #+#    #+#             */
/*   Updated: 2017/07/17 10:50:42 by ecloete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	forward(t_values *v)
{
	if(v->worldMap[(int)(v->posX + v->dirX * v->moveSpeed)][(int)(v->posY)] == 0)
        v->posX += v->dirX * v->moveSpeed;
	if(v->worldMap[(int)(v->posX)][(int)(v->posY + v->dirY * v->moveSpeed)] == 0)
        v->posY += v->dirY * v->moveSpeed;
}

void	backwards(t_values *v)
{
	if(v->worldMap[(int)(v->posX - v->dirX * v->moveSpeed)][(int)(v->posY)] == 0)
        v->posX -= v->dirX * v->moveSpeed;
	if(v->worldMap[(int)(v->posX)][(int)(v->posY - v->dirY * v->moveSpeed)] == 0)
        v->posY -= v->dirY * v->moveSpeed;
}

void	right(t_values *v)
{
	v->oldDirX = v->dirX;
	v->dirX = v->dirX * cos(-v->rotSpeed) - v->dirY * sin(-v->rotSpeed);
	v->dirY = v->oldDirX * sin(-v->rotSpeed) + v->dirY * cos(-v->rotSpeed);
	v->oldPlaneX = v->planeX;
	v->planeX = v->planeX * cos(-v->rotSpeed) - v->planeY * sin(-v->rotSpeed);
	v->planeY = v->oldPlaneX * sin(-v->rotSpeed) + v->planeY * cos(-v->rotSpeed);
}

void	left(t_values *v)
{
	v->oldDirX = v->dirX;
	v->dirX = v->dirX * cos(v->rotSpeed) - v->dirY * sin(v->rotSpeed);
	v->dirY = v->oldDirX * sin(v->rotSpeed) + v->dirY * cos(v->rotSpeed);
	v->oldPlaneX = v->planeX;
	v->planeX = v->planeX * cos(v->rotSpeed) - v->planeY * sin(v->rotSpeed);
	v->planeY = v->oldPlaneX * sin(v->rotSpeed) + v->planeY * cos(v->rotSpeed);
}

int	readkeys(int keycode, t_values *v)
{
	mlx_clear_window(v->m.mlx, v->m.win);
	if (keycode == 126)
	{
		forward(v);
		raycasting(v);
	}
	else if (keycode == 125) //down
	{
		backwards(v);
		raycasting(v);
	}
	else if (keycode == 124) //right
	{
		right(v);
		raycasting(v);
	}
	else if (keycode == 123) //left
	{
		left(v);
		raycasting(v);
	}
	return (0);
}
