/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edramire <edramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 01:58:05 by edramire          #+#    #+#             */
/*   Updated: 2020/03/04 02:19:59 by edramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	game_exit(void *param)
{
	t_game *game;

	game = (t_game *)param;
	mlx_destroy_window(game->mlx, game->window);
	exit(0);
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
void		game_init(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return ;
	game->height = HEIGHT;
	game->width = WIDTH;
	game->window = mlx_new_window(game->mlx, WIDTH, HEIGHT, "GAME");
	mlx_hook(game->window, 2, 1L, game_key_press, game);
	//mlx_hook(game->window, 3, 2L, game_key_release, game);
	mlx_hook(game->window, 17, 0, game_exit, game);
}