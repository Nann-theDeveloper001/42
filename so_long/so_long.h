/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:20:41 by marvin            #+#    #+#             */
/*   Updated: 2024/10/21 21:18:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
// # include <mlx.h>
# include <sys/types.h>
# include "libft/libft.h"

# define KEY_UP		13
# define KEY_DOWN	1
# define KEY_LEFT	0
# define KEY_RIGHT	2
# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2

typedef struct s_map
{
    char** map_array;
    int width;
    int height;
    int collect_count;
    int exit_count;
    int player_count;
    int outsider;
} t_map;

typedef struct f_point
{
    int x;
    int y;
    int b_x;
    int b_y;
    int count;
}   t_point;

// typedef s_game
// {
//     int player_x;
//     int player_y;
//     int moves;
//     int collectibles;
//     void* mlx_ptr;
//     void* win_ptr;
// }t_game

void    fill_map(int fd, t_map *game_map);
void    border_check(t_map *game_map);
void    ch_validate(int r, int c, t_map *g_map);
void    is_rectangular(t_map* game_map);
void    print_map(t_map *game_map, int row);
void    error_msg(t_map *g_map);
void    m_validate(char **av, t_map *game_map);
int     check_file(char **av);
void	flood_fill(char **tab, t_point size, t_point begin);
void    fill (char **tab, t_point size, t_point cur);
int file_validate(char **av);
void    **row_col(int bytes_read, char *buffer, t_map *g_map);
char **map_array_alloc(t_map *game_map);
void g_struct(char **av, t_map *game_map, int bytesRead, char *buffer);
void    begin_point(char **map, t_map *g_map, t_point *begin);

#endif