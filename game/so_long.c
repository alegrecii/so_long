/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegreci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:31:25 by alegreci          #+#    #+#             */
/*   Updated: 2022/11/29 16:31:28 by alegreci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		flag;

	flag = check_init(argc, argv, &game);
	if (!flag)
		return (0);
	mlx_key_hook(game.win, input_manager, &game);
	mlx_loop_hook(game.mlx, updater, &game);
	mlx_hook(game.win, 17, 0, superfree, &game);
	mlx_loop(game.mlx);
}
