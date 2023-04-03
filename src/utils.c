/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:17:17 by antmoren          #+#    #+#             */
/*   Updated: 2023/04/03 11:41:05 by antmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_error(char *message)
{
	ft_printf("\033[0;31mError\n%s\n", message);
	exit(1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	finish_game(t_game *game)
{
	if (game->score == game->map.collect_cnt)
	{
		if (game->map.coords[game->player_pos_y][game->player_pos_x] == 'E')
		{
			printf("\e[32;1mYOU WIN!\e[0m\n");
			delete_img(game);
			mlx_terminate(game->mlx);
			exit(EXIT_SUCCESS);
		}
	}
}
