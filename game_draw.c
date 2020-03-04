/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edramire <edramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:48:36 by edramire          #+#    #+#             */
/*   Updated: 2020/03/04 18:58:49 by edramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	game_draw(t_game *game, int index)
{
	int		row;
	int		col;
	int		idx;
	int		color;

	//color = 0xFF<< (8 * (rand() % 3));
	color = 0xFFFFFF;
	row = (index / game->cols) * game->size;
	col = (index % game->cols) * game->size;
	for (int y = 0; y < game->size; y++)
		for (int x = 0; x < game->size; x++)
		{
			idx = (row + y) * game->width + col + x;
			if (game->image.buffer[idx] > 0)
				game->image.buffer[idx] = 0x0;
			else
				game->image.buffer[idx] = color;
		}
}
