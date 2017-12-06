/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecloete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 11:03:27 by ecloete           #+#    #+#             */
/*   Updated: 2017/07/13 10:21:40 by ecloete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
#define mapWidth 10
#define mapHeight 10

typedef struct  s_mlx
{
    void *mlx;
    void *win;
}               t_mlx;

typedef struct  s_values
{  
    int     **worldMap;
    int     fd;
    int     colour;
    int     w;
    int     h;
    int     mapX;
    int     mapY;
    int     hit;
    int     side;
    int     stepX;
    int     stepY;
    int     lineHeight;
    int     drawStart;
    int     drawEnd;
    int     x;
    double  posX;
    double  posY;
    double  dirX;
    double  dirY;
    double  planeX;
    double  planeY;
    double  time;
    double  oldTime;
    double  cameraX;
    double  rayPosX;
    double  rayPosY;
    double  rayDirX;
    double  rayDirY;
    double  sideDistX;
    double  sideDistY;
    double  deltaDistX;
    double  deltaDistY;
    double  perpWallDist;
    double  frameTime;
    double  moveSpeed;
    double  rotSpeed;
    double  oldPlaneX;
    double  oldDirX;
    struct  s_mlx   m;
}               t_values;

typedef	struct	s_read
{
	int			col_count;
	int			row_count;
	char		*row;
	char		**split;
	int			fd;
}				t_read;

void    initmap(t_values v);
void    forward(t_values *v);
void    backwards(t_values *v);
void    right(t_values *v);
void    left(t_values *v);
int     readkeys(int keycode, t_values *v);
static void    initvar(t_values *v);
void    raycasting(t_values *v);
void    choosecolour(t_values *v);
void    prepwall(t_values *v);
void    dda(t_values *v);
void    calculatestep(t_values *v);
void    render(t_values *v);
void 	read_file(char *file, t_values *v);
static void		ft_read_count(char *file, t_read *k);

#endif
