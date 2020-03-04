/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edramire <edramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 01:55:31 by edramire          #+#    #+#             */
/*   Updated: 2020/03/04 16:55:17 by edramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		main(void)
{
	t_game	game;

	srand(time(0));
	bzero(&game, sizeof(t_game));
	game_init(&game);
	if (game.mlx != NULL)
		mlx_loop(game.mlx);
	return (0);
}