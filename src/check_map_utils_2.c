/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:38:05 by antmoren          #+#    #+#             */
/*   Updated: 2023/03/05 14:38:23 by antmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_counters_map(t_map *map)
{
	if (map->collect_cnt < 1 || map->exit_cnt != 1 || map->player_cnt != 1)
	{
		print_error("There are missing or exceding elements");
	}
}
