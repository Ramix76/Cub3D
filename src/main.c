/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:19:32 by framos-p          #+#    #+#             */
/*   Updated: 2023/12/14 13:23:36 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "init.h"

void	free_all(t_cub *cub);

/*
** CUB3D is a project for 42 that involves building a 3D game engine
** using the raycasting technique popularized by games like Wolfenstein 3D
** and Doom. The goal is to parse a map file that specifies the layout of
** walls, the player's starting position and orientation, and textures for
** the walls, and then use the MLX library to render the game on the screen.
** The project is structured as follows:
**
** 1. Parsing: read in the map file and store the relevant information
** in a data structure.
**
** 2. Raycasting: use the information from the map to cast rays from the
** player's position to the walls, calculating the distance and angle
** to each wall and using that information to render a 3D projection
** of the scene.
**
** 3. Display: use the MLX library to render the projection on the screen,
** handling user input to move the player and interact with the environment.
**
*/
/**
 * main - the entry point of the program
 *
 * This function initializes the game state, sets up the window, and starts
 * the game execution loop. It takes command-line arguments, but they are
 * not currently used in this implementation.
 *
 * @argv: the number of command-line arguments
 * @argc: the array of command-line argument strings
 *
 * Return: 0 if the program exits successfully
 */

int	main(int argv, char **argc)
{
	t_cub	cub;

	ft_bzero(&cub, sizeof(t_cub));
	if (window_init(&cub.screen))
		exit(EXIT_FAILURE);
	if (parse_map(argv, argc, &cub) == EXIT_FAILURE)
	{
		ft_putstr_fd("Map Error\n", 2);
		free_all(&cub);
		exit(EXIT_FAILURE);
	}
	if (executor(&cub))
		exit(EXIT_FAILURE);
	exit (EXIT_SUCCESS);
}