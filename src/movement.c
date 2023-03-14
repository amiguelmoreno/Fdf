/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:00:53 by antmoren          #+#    #+#             */
/*   Updated: 2023/03/14 18:20:30 by antmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_score(t_game *game, int x, int y)
{
	int	count;

	count = 0;
	while (game->map.coords[y])
	{
		x = 0;
		while (game->map.coords[y][x] != '\0')
		{
			if (game->map.coords[y][x] == 'C' && x == game->player_pos_x
				&& y == game->player_pos_y
				&& game->img.collectable->instances[count].enabled == true)
			{
				game->score++;
				game->img.collectable->instances[count].enabled = false;
				printf("Steps: %d | Score: %d\n", (game->steps), game->score);
			}
			if (game->map.coords[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	finish_game(game);
}

void	rotate_player(int n, t_game *game)
{
	game->img.player_right->instances[0].enabled = false;
	game->img.player_left->instances[0].enabled = false;
	game->img.player_front->instances[0].enabled = false;
	game->img.player_back->instances[0].enabled = false;
	if (n == 0)
		game->img.player_right->instances[0].enabled = true;
	if (n == 1)
		game->img.player_left->instances[0].enabled = true;
	if (n == 2)
		game->img.player_front->instances[0].enabled = true;
	if (n == 3)
		game->img.player_back->instances[0].enabled = true;
}

void	move_player_img(int n, int sign, t_game *game)
{
	if (n == 1)
	{
		game->img.player_right->instances[0].y += sign;
		game->img.player_left->instances[0].y += sign;
		game->img.player_front->instances[0].y += sign;
		game->img.player_back->instances[0].y += sign;
		if (sign < 0)
			rotate_player(3, game);
		else
			rotate_player(2, game);
	}
	if (n == 2)
	{
		game->img.player_right->instances[0].x += sign;
		game->img.player_left->instances[0].x += sign;
		game->img.player_front->instances[0].x += sign;
		game->img.player_back->instances[0].x += sign;
		if (sign < 0)
			rotate_player(1, game);
		else
			rotate_player(0, game);
	}
}

void	make_move(int n, int sign, t_game *game)
{
	game->steps++;
	move_player_img(n, sign, game);
	if ((game->map.coords[game->player_pos_y + (n == 1) * sign
			/ 64][game->player_pos_x + (n == 2) * sign / 64] != 'C'))
		printf("Steps: %d | Score: %d\n", (game->steps), game->score);
}

void	move_player(mlx_key_data_t keydata, void *param)
{
	t_game *game;

	(void)keydata;
	game = param;
	game->player_pos_y = game->img.player_right->instances[0].y / 64;
	game->player_pos_x = game->img.player_right->instances[0].x / 64;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(game->mlx);
		exit(EXIT_FAILURE);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_W)
		&& game->map.coords[game->player_pos_y - 1][game->player_pos_x] != '1')
		make_move(1, -64, game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S)
		&& game->map.coords[game->player_pos_y + 1][game->player_pos_x] != '1')
		make_move(1, 64, game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A)
		&& game->map.coords[game->player_pos_y][game->player_pos_x - 1] != '1')
		make_move(2, -64, game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D)
		&& game->map.coords[game->player_pos_y][game->player_pos_x + 1] != '1')
		make_move(2, 64, game);
	check_score(game, 0, 0);
}