/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:08:35 by antmoren          #+#    #+#             */
/*   Updated: 2023/03/09 12:23:41 by antmoren         ###   ########.fr       */
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
		game.score = 0; // remove from here
		game.steps = 0; // remove from here
		game.mlx = mlx_init(game.img_size * game.map.width, game.img_size
				* game.map.height, "SO_LONG", true);
		if (!game.mlx)
			exit(EXIT_FAILURE);
		create_map(&game);
		mlx_key_hook(game.mlx, &movement, &game);
		//mlx_loop_hook(game.mlx, ft_hook, game.mlx);
		mlx_loop(game.mlx);
		mlx_terminate(game.mlx);
	}
	else
		print_error("Missing arguments");
}

/* #include "MLX42/MLX42.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define WIDTH 512
#define HEIGHT 512

static void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t	main(void)
{
	// Start mlx
	mlx_t *mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!mlx)
		error();

	// Try to load the file
	mlx_texture_t *texture = mlx_load_png("./assets/img/floor.png");
	if (!texture)
		error();

	// Convert texture to a displayable image
	mlx_image_t *img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();

	// Display the image
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		error();

	mlx_loop(mlx);

	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
} */