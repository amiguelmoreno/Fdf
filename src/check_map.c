/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 20:29:03 by antmoren          #+#    #+#             */
/*   Updated: 2023/04/03 12:52:01 by antmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	read_map(t_game *game)
{
	char	*str_map;
	int		fd;
	char	c;
	int		count;

	count = 0;
	fd = open(game->map.path, O_RDONLY);
	if (fd < 0)
		print_error("Something went wrong opening the file");
	while (read(fd, &c, 1) == 1)
		count++;
	if (count == 0)
		print_error("Something went wrong opening the file");
	str_map = (char *)malloc(sizeof(char) * (count + 1));
	if (!str_map)
		print_error("Could not allocate memory");
	close(fd);
	fd = open(game->map.path, O_RDONLY);
	read(fd, str_map, count);
	str_map[count] = '\0';
	close(fd);
	game->map.coords = ft_split(str_map, '\n');
	free(str_map);
}

void	check_map(t_game *game, char *argv)
{
	game->map.path = check_path(argv);
	read_map(game);
	check_rectangle_map(game);
	check_elem_num(game, &game->map);
	check_content_map(game);
	check_border_map(game);
	check_route(game);
}
