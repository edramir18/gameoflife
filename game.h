/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edramire <edramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 01:50:53 by edramire          #+#    #+#             */
/*   Updated: 2020/03/04 02:11:56 by edramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#define HEIGHT 400
#define WIDTH 400

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# include "minilibx/mlx.h"
# include "game_key.h"

typedef struct	s_image
{
	int		width;
	int		height;
	int		line;
	int		ppm;
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
	t_image	image;
}				t_game;

void	game_init(t_game *game);

#endif
