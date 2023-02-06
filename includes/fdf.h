/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:09:53 by antmoren          #+#    #+#             */
/*   Updated: 2023/02/06 20:56:52 by antmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 512
# define HEIGHT 512

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <memory.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct s_window {
	void	*mlx;
	void	*win;
	void	*img;
	int		*data;
	int		bpp;
	int		size_line;
	int		endian;
} t_window;

#endif