/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:08:35 by antmoren          #+#    #+#             */
/*   Updated: 2023/03/15 18:48:14 by antmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		mlx_set_setting(MLX_STRETCH_IMAGE, true);
		ft_bzero(&game, sizeof(t_game));
		check_map(&game.map, argv[1]);
		game.img_size = 64;
		game.score = 0;
		game.steps = 0;
		game.mlx = mlx_init(game.img_size * game.map.width, game.img_size
				* game.map.height, "SO_LONG", true);
		if (!game.mlx)
			exit(EXIT_FAILURE);
		create_map(&game);
		mlx_key_hook(game.mlx, &move_player, &game);
		mlx_loop(game.mlx);
		mlx_terminate(game.mlx);
	}
	else
		print_error("Missing arguments");
}
