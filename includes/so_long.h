/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:09:53 by antmoren          #+#    #+#             */
/*   Updated: 2023/02/09 21:34:32 by antmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#define WIDTH 512
#define HEIGHT 512

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/42-library/includes/libft.h"
#include "../lib/42-library/includes/get_next_line_bonus.h"
#include "../lib/42-library/includes/ft_printf.h"
#include <fcntl.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_map
{
    int width;
    int height;
    char **coords;
} t_map;

#endif