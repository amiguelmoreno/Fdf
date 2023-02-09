/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:08:35 by antmoren          #+#    #+#             */
/*   Updated: 2023/02/08 23:55:42 by antmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* static mlx_image_t *g_img;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
}

void	generate_lines(mlx_image_t *g_img)
{
	int	i;

	i = 0;
	while(i < 250)
	{
		mlx_put_pixel(g_img, i, i, 0xFFFFFFFF);
		i++;
	}
	i--;
	while(i > 0)
	{
		mlx_put_pixel(g_img, i + 20, i, 0xFFFFFFFF);
		i--;
	}
}

int	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, WIDTH, HEIGHT);    // Creates a new image.
	mlx_image_to_window(mlx, g_img, 0, 0);
	// Adds an image to the render queue.
	generate_lines(g_img);
	mlx_loop(mlx);
	mlx_delete_image(mlx, g_img); // Once the application request an exit,
		cleanup.
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
 */

/* char	*get_next_line(int fd)
{
	char	*ret;
	char	c;
	int		i;
	int		cpt;

	ret = malloc(9999);
	i = 0;
	cpt = 0;
	if (fd < 0)
		return (NULL);
	while ((cpt = read(fd, &c, 1)) > 0)
	{
		ret[i] = c;
		i++;
		if (c == '\n')
			break ;
	}
	if (i == 0 || cpt < 0)
	{
		free(ret);
		return (NULL);
	}
	ret[i] = '\0';
	return (ret);
} */

int main(int argc, char **argv)
{
	int fd;
	char *line;

	(void)argc;
	fd = open((argv[1]), O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("LINE -> %s", line);
		line = get_next_line(fd);
	}
}
