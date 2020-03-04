/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edramire <edramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 01:50:53 by edramire          #+#    #+#             */
/*   Updated: 2020/03/04 18:42:54 by edramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define HEIGHT 1200
# define WIDTH 1200
# define GRID 4

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <time.h>

# include "minilibx/mlx.h"
# include "game_key.h"

typedef struct	s_image
{
	int		width;
	int		height;
	int		line;
	int		bpp;
	int		endian;
	void	*ptr;
	int		*buffer;
}				t_image;


typedef struct	s_game
{
	void	*mlx;
	void	*window;
	int		width;
	int		height;
	int		size;
	int		rows;
	int		cols;
	int		*grid;
	t_image	image;
}				t_game;

void	game_init(t_game *game);
void	game_draw(t_game *game, int index);
int		game_loop(void *param);

#endif
