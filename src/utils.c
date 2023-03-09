/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:17:17 by antmoren          #+#    #+#             */
/*   Updated: 2023/03/09 12:04:19 by antmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_error(char *message)
{
	ft_printf("\033[0;31mError\n%s\n", message);
	exit(1);
}

char	*read_line(int fd)
{
	char	*line;
	char	c;
	int		i;

	i = 0;
	line = (char *)malloc(MAX_LINE_LENGTH * sizeof(char));
	while (read(fd, &c, 1) > 0 && c != '\n')
	{
		line[i++] = c;
		if (i == MAX_LINE_LENGTH - 1)
		{
			break ;
		}
	}
	line[i] = '\0';
	if (i > 0)
	{
		return (line);
	}
	else
	{
		free(line);
		return (NULL);
	}
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