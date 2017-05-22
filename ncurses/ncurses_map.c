/*
** ncurses_map.c for tetris in /home/Vatoth/Epitech/PSU_2016_tetris/ncurses
** 
** Made by Quentin Sonnefraud
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Sun Mar 19 17:46:47 2017 Quentin Sonnefraud
** Last update Sun Mar 19 17:53:09 2017 Quentin Sonnefraud
*/

#include <ncurses.h>
#include "tetris.h"

extern t_keys	g_keys;

WINDOW		*game_map(void)
{
  int		x;
  int		y;
  WINDOW	*box_game;

  x = (LINES - g_keys.size_x) / 2;
  y = (COLS - g_keys.size_x) / 2;
  box_game = newwin(g_keys.size_x * 2, g_keys.size_y * 4, x, y);
  wborder(box_game, '|', '|', '-', '-', '+', '+', '+', '+');
  return (box_game);
}

WINDOW		*map_score(void)
{
  int		x;
  int		y;
  WINDOW	*score;

  x = (LINES - g_keys.size_x) / 2;
  y = (COLS - g_keys.size_x) / 2;
  score = newwin(10, 20, x, y - 30);
  wborder(score, '|', '|', '-', '-', 'o', 'o', 'o', 'o');
  return (score);
}

WINDOW		*map_next(void)
{
  int		x;
  int		y;
  WINDOW	*next;

  x = (LINES - g_keys.size_x) / 2;
  y = (COLS - g_keys.size_x) / 2;
  next = newwin(10, 20, x + 30, y + 50);
  wborder(next, '|', '|', '-', '-', 'o', 'o', 'o', 'o');
  return (next);
}
