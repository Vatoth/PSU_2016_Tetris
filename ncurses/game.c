/*
** game.c for game.c in /home/loto/Documents/semestre2/PSU/PSU_2016_tetris
**
** Made by loto
** Login   <loto@epitech.net>
**
** Started on  Sun Mar 12 13:43:35 2017 loto
** Last update Wed Mar 22 10:58:24 2017 loto
*/

#include <ncurses.h>
#include <curses.h>
#include "tetris.h"

extern t_keys	g_keys;

void	print_window_map(char **map_board, WINDOW *map)
{
  int	size;

  size = 1;
  while (map_board[size])
    {
      mvwprintw(map, size, 1, map_board[size]);
      size++;
    }
  wrefresh(map);
}

void	init_tetrimino(t_piece *element, char **map_board, WINDOW *map)
{
  int	x;
  int	y;

  x = (((g_keys.size_x / 2) - (element->width / 2)) - 2) * 2;
  y = 0;
  my_printf("%i\n", ((g_keys.size_y * 4) - 4));
  while (y < ((g_keys.size_y * 4) - 5))
    {
      my_printf("%i\n", y);
      fall_tetri(element, map_board, &x, y);
      print_window_map(map_board, map);
      usleep(200000);
      y++;
    }
}

void		game_board(WINDOW *map, WINDOW *score,
			   t_list *list)
{
  t_piece	*element;
  char		**map_board;
  int		nb;

  nb = 1;
  element = list->first;
  map_board = creat_map_board();
  while (1)
    {
      if (element == NULL)
	{
	  nb = 1;
	  element = list->first;
	}
      if (element->valid == 0)
	{
	  liste(list, nb, score);
	  init_tetrimino(element, map_board, map);
	  element = element->next;
	}
      if (element == NULL)
	{
	  element = list->first;
	  nb = 1;
	}
      else
	element = element->next;
      nb++;
    }
}

int	game(WINDOW *map, WINDOW *score, WINDOW *next, t_list *list)
{
  print_title();
  wrefresh(score);
  wrefresh(next);
  game_board(map, score, list);
  return (0);
}

char	**creat_map_board()
{
  char	**map;
  int	size;

  size = 0;
  if ((map = malloc(sizeof(char *) * ((g_keys.size_y * 4)))) == NULL)
    return (NULL);
  while (size < (g_keys.size_y * 4))
    {
      if ((map[size] = malloc(sizeof(char) * ((g_keys.size_x * 2)))) == NULL)
	return (NULL);
      map[size] = my_memset(map[size], ' ', (g_keys.size_x * 2) - 1);
      map[size][((g_keys.size_x * 2) - 2)] = '\0';
      size++;
    }
  map[size - 1] = NULL;
  return (map);
}
