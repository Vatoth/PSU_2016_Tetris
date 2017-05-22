/*
** init_ncurses.c for tetris in /home/Vatoth/Epitech/PSU_2016_tetris/ncurses
** 
** Made by Quentin Sonnefraud
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Sun Mar 19 17:42:57 2017 Quentin Sonnefraud
** Last update Sun Mar 19 17:49:41 2017 Quentin Sonnefraud
*/

#include <fcntl.h>
#include <ncurses.h>
#include <curses.h>
#include "tetris.h"

extern t_keys	g_keys;

void	init_pair_color(void)
{
  init_pair(0, COLOR_BLACK, COLOR_BLACK);
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
  init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

int		print_title()
{
  char		*buffer;
  int		fd;

  if ((fd = open("title", O_RDONLY)) == -1)
    return (1);
  if ((buffer = malloc(sizeof(char) * 10000)) == NULL)
    return (1);
  buffer = my_memset(buffer, '\0', 10000);
  if ((read(fd, buffer, 10000)) == -1)
    return (1);
  attron(COLOR_PAIR(4));
  mvprintw(0, 0, buffer);
  attroff(COLOR_PAIR(4));
  refresh();
  sleep(1);
  clear();
  attron(COLOR_PAIR(3));
  mvprintw(0, 0, buffer);
  attroff(COLOR_PAIR(3));
  refresh();
  sleep(1);
  clear();
  animation_title(buffer);
  return (0);
}

void	animation_title(char *buffer)
{
  attron(COLOR_PAIR(5));
  mvprintw(0, 0, buffer);
  attroff(COLOR_PAIR(5));
  refresh();
  sleep(1);
  clear();
  attron(COLOR_PAIR(1));
  mvprintw(0, 0, buffer);
  attroff(COLOR_PAIR(1));
  refresh();
  sleep(1);
  clear();
  attron(COLOR_PAIR(4));
  mvprintw(0, 0, buffer);
  attroff(COLOR_PAIR(4));
  refresh();
}

void	init_ncurses_fonc()
{
  char	buffer[10];

  initscr();
  if (g_keys.debug == 1)
    read(0, buffer, 10);

  start_color();
  init_pair_color();
  curs_set(0);
  keypad(stdscr, TRUE);
}

void		ncurses_init(t_list *list)
{
  WINDOW	*box_game;
  WINDOW	*score_map;
  WINDOW	*next_map;

  init_ncurses_fonc();
  box_game = game_map();
  score_map = map_score();
  next_map = map_next();
  game (box_game, score_map, next_map, list);
}
