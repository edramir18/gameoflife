/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edramire <edramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:01:18 by edramire          #+#    #+#             */
/*   Updated: 2020/03/04 18:59:03 by edramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		game_count(t_game *game, int row, int col)
{
	int		x;
	int		dx;
	int		y;
	int		dy;
	int		n;

	n = 0;
	dx = 0;
	dy = -1;
	for (int i = 0; i < 4; i++)
	{
		y = row * game->size + dy * game->size;
		x = col * game->size + dx * game->size;
		x += x < 0 ? game->width : 0;
		x = x >= game->width ? x % game->width : x;
		y += y < 0 ? game->height : 0;
		y = y >= game->height ? y % game->height : y;
		if (x >=0 && x < game->width && y >= 0 && y < game->height)
			if (game->image.buffer[y * game->width + x] > 0)
				++n;
		x = dx;
		y = dy;
		dx = -y;
		dy = x;
	}
	dx = 1;
	dy = 1;
	for (int i = 0; i < 4; i++)
	{
		y = row * game->size + dy * game->size;
		x = col * game->size + dx * game->size;
		x += x < 0 ? game->width : 0;
		x = x >= game->width ? x % game->width : x;
		y += y < 0 ? game->height : 0;
		y = y >= game->height ? y % game->height : y;
		if (x >=0 && x < game->width && y >= 0 && y < game->height)
			if (game->image.buffer[y * game->width + x] > 0)
				++n;
		x = dx;
		y = dy;
		dx = -y;
		dy = x;
	}
	return (n);
}
int		game_check(t_game *game, int row, int col, int n)
{
	int		y;
	int		x;
	int		live;

	x = col * game->size;
	y = row * game->size;	
	live =	game->image.buffer[y * game->width + x] > 0 ? 1 : 0;
	if (live == 1 && (n < 2 || n > 3))
		return (row * game->cols + col);
	else if (live == 0 && n == 3)
		return (row * game->cols + col);
	return (-1);
}

int		game_loop(void *param)
{
	t_game	*game;
	int		row;
	int		col;
	int		total;
	int		n;
	clock_t t;
	static clock_t fps = 0;

	t = clock();
	if ((t - fps) < (CLOCKS_PER_SEC / 60))
		return (0);
	fps = t;
	game = (t_game *)param;
	mlx_put_image_to_window(game->mlx, game->window, game->image.ptr, 0, 0);
	total = 0;
	row = 0;
	while (row < game->rows)
	{
		col = 0;
		while (col < game->cols)
		{
			n = game_count(game, row, col);
			n = game_check(game, row, col, n);
			if (n >= 0)
				game->grid[total++] = n;
			++col;
		}
		++row;
	}
	while (total > 0)
		game_draw(game, game->grid[--total]);
	return (0);
}