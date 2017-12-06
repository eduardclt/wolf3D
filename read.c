/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecloete <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 13:08:18 by ecloete           #+#    #+#             */
/*   Updated: 2017/07/20 13:08:19 by ecloete          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "./libft/libft.h"

static void		ft_read_count(char *file, t_read *k)
{
	int space;

	space = 0;
	k->row_count = 0;
	k->col_count = 0;
	k->fd = open(file, O_RDONLY);
	if (get_next_line(k->fd, &k->row))
		k->row_count++;
	while (k->row[k->col_count])
	{
		if (k->row[k->col_count] == 32)
			space++;
		k->col_count++;
	}
	//free(k->row);
	k->col_count -= space;
	while (get_next_line(k->fd, &k->row))
	{
		k->row_count++;
	//	free(k->row);
	}
	close(k->fd);
}

void			read_file(char *file, t_values *v)
{
	t_read	k;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_read_count(file, &k);
	k.fd = open(file, O_RDONLY);
	v->worldMap = (int **)malloc(sizeof(int *) * (k.row_count + 1));
	while (get_next_line(k.fd, &k.row))
	{
		k.split = ft_strsplit((const char*)k.row, ' ');
	//	free(k.row);
		while (k.split[k.col_count] != NULL)
			k.col_count++;
		j = 0;
		v->worldMap[i] = (int *)malloc(sizeof(int) * (k.col_count + 1));
		while (k.split[j] != NULL)
		{
			v->worldMap[i][j] = ft_atoi((const char*)k.split[j]);
	//		free(k.split[j]);
			j++;
		}
	//	free(k.split);
		i++;
	}
	close(k.fd);
}
