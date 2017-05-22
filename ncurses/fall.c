/*
** fall.c for tetris in /home/vatoth/PSU_2016_tetris
**
** Made by Vatoth
** Login   <quentin.sonnefraud@epitech.eu>
**
** Started on  Wed Mar 15 22:36:01 2017 Vatoth
** Last update Tue Mar 21 15:40:29 2017 loto
*/

#include "tetris.h"

extern t_keys	g_keys;

void    print_tetri(t_piece *e, char **map, int x, int y)
{
  int   i;
  int   j;
  int   tmp;

  i = 0;
  tmp = x;
  while (i < e->width)
    {
      x = tmp;
      j = 0;
      while (j < e->height)
	{
	  if (e->star[i][j] == '*')
	    {
	      map[y][x] = '*';
	    }
	  j++;
	  x++;
	}
      i++;
      y++;
    }
}

void    clean_tetri(t_piece *e, char **map, int x, int y)
{
  int   i;
  int   j;
  int   tmp;

  i = 0;
  tmp = x;
  while (i < e->width)
    {
      x = tmp;
      j = 0;
      while (j < e->height)
	{
	  if (e->star[i][j++] == '*')
	    map[y][x++] = ' ';
	}
      i++;
      y++;
    }
}

int     fall_tetri(t_piece *e, char **map, int *x, int y)
{
  clean_tetri(e, map, *x, y);
  y++;
  print_tetri(e, map, *x, y);
  return (0);
}
