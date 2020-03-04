/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edramire <edramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 01:58:05 by edramire          #+#    #+#             */
/*   Updated: 2020/03/04 18:11:14 by edramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	game_exit(void *param)
{
	t_game *game;

	game = (t_game *)param;
	mlx_destroy_window(game->mlx, game->window);
	exit(0);
	return (0);
}

static int	game_key_press(int keycode, void *param)
{
	t_game *game;

	game = (t_game *)param;
	if (keycode == KEY_ESC)
		game_exit(game);
	return (0);
}
/*
static int	game_key_release(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	return (0);
}
*/

static void	game_init_map(t_game *game)
{
	int		row;
	int		col;

	row = 0;
	while (row < game->rows)
	{
		col = 0;
		while (col < game->cols)
		{
			if (rand() % 100 < 30)
				game_draw(game, row * game->cols + col);
			++col;
		}
		++row;
	}
}

void		game_init(t_game *game)
{
	t_image		*image;
	
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return ;
	game->height = HEIGHT;
	game->width = WIDTH;
	game->window = mlx_new_window(game->mlx, WIDTH, HEIGHT, "GAME");
	mlx_hook(game->window, 2, 1L, game_key_press, game);
	//mlx_hook(game->window, 3, 2L, game_key_release, game);
	mlx_hook(game->window, 17, 0, game_exit, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	image = &game->image;
	image->ptr = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	image->buffer = (int *)mlx_get_data_addr(image->ptr, &image->bpp, &image->line, &image->endian);
	game->size = GRID;
	game->rows = HEIGHT / GRID;
	game->cols = WIDTH / GRID;
	game->grid = malloc(sizeof(int) * (game->rows * game->cols));
	if (game->grid == NULL)
		game_exit(game);
	bzero(game->grid, sizeof(int) * (game->rows * game->cols));
	game_init_map(game);
}