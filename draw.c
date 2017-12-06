/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecloete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 10:50:05 by ecloete           #+#    #+#             */
/*   Updated: 2017/07/17 10:50:08 by ecloete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	calculatestep(t_values *v)
{
	if (v->rayDirX < 0)
	{
		v->stepX = -1;
		v->sideDistX = (v->rayPosX - v->mapX) * v->deltaDistX;
	}
	else
	{
		v->stepX = 1;
		v->sideDistX = (v->mapX + 1.0 - v->rayPosX) * v->deltaDistX;
	}
	if (v->rayDirY < 0)
	{
		v->stepY = -1;
		v->sideDistY = (v->rayPosY - v->mapY) * v->deltaDistY;
	}
	else
	{
		v->stepY = 1;
		v->sideDistY = (v->mapY + 1.0 - v->rayPosY) * v->deltaDistY;
	}	
}

void	dda(t_values *v)
{
	while (v->hit == 0)
	{
		if (v->sideDistX < v->sideDistY)
		{
			v->sideDistX += v->deltaDistX;
			v->mapX += v->stepX;
			v->side = 0;
		}
		else
		{
			v->sideDistY += v->deltaDistY;
			v->mapY += v->stepY;
			v->side = 1;
		}
		if (v->worldMap[v->mapX][v->mapY] > 0)
			v->hit = 1;
	}
}

void	prepwall(t_values *v)
{
	if (v->side == 0)
		v->perpWallDist = (v->mapX - v->rayPosX + (1 - v->stepX) / 2) / v->rayDirX;
	else
		v->perpWallDist = (v->mapY - v->rayPosY + (1 - v->stepY) / 2) / v->rayDirY;    
	v->lineHeight = (int)(v->h / v->perpWallDist);
	v->drawStart = -v->lineHeight / 2 + v->h / 2;
	if (v->drawStart < 0)
		v->drawStart = 0;
	v->drawEnd = v->lineHeight / 2 + v->h / 2;
	if(v->drawEnd >= v->h)
		v->drawEnd = v->h - 1;
}

void	choosecolour(t_values *v)
{
	if (v->worldMap[v->mapX][v->mapY] == 1)
        v->colour = 0x00FF0000; //red
    else if (v->worldMap[v->mapX][v->mapY] == 2)
        v->colour = 0x0000FF00; //green
    else if (v->worldMap[v->mapX][v->mapY] == 3)
        v->colour = 0x000000FF; //blue
    else if (v->worldMap[v->mapX][v->mapY] == 4)
        v->colour = 0x00F0FF0F; //white
    else
        v->colour = 0x00FFFF00; //yellow
	if (v->side == 1) 
		v->colour = v->colour / 1.1;
}

void	raycasting(t_values *v)
{
    v->x = 0;
	while (v->x < v->w)
	{    
		v->cameraX = 2 * v->x / (double)(v->w) - 1;
		v->rayPosX = v->posX;
		v->rayPosY = v->posY;
		v->rayDirX = v->dirX + v->planeX * v->cameraX;
		v->rayDirY = v->dirY + v->planeY * v->cameraX;
		v->mapX = (int)(v->rayPosX);
		v->mapY = (int)(v->rayPosY);
		v->deltaDistX = sqrt(1 + (v->rayDirY * v->rayDirY) / (v->rayDirX * v->rayDirX));
		v->deltaDistY = sqrt(1 + (v->rayDirX * v->rayDirX) / (v->rayDirY * v->rayDirY));
		v->hit = 0;
		calculatestep(v);
		dda(v);
        prepwall(v);
        choosecolour(v);
		render(v);
		v->x++;
	}
}
