/*
** turn_pieces.c for tetris in /home/vatoth/PSU_2016_tetris
**
** Made by Vatoth
** Login   <quentin.sonnefraud@epitech.eu>
**
** Started on  Tue Mar 14 11:50:47 2017 Vatoth
** Last update Sun Mar 19 16:29:21 2017 loto
*/

#include <stdio.h>
#include "tetris.h"

char		**rotate(char **s, int *x, int *y)
{
  t_place	ij;
  int		save;
  char	**temp;

  ij.i = 0;
  if (!(temp = malloc(sizeof(char *) * (*x + 1))))
    return (NULL);
  while (ij.i < *x)
    {
      if (!(temp[ij.i] = malloc(sizeof(char) * (*y + 1))))
	return (NULL);
      ij.j = 0;
      while (ij.j < *y)
	{
	  temp[ij.i][ij.j] = s[*y - ij.j - 1][ij.i];
	  ij.j = ij.j + 1;
	}
      temp[ij.i][ij.j] = '\0';
      ij.i = ij.i + 1;
    }
  save = *y;
  *y = *x;
  *x = save;
  temp[ij.i] = NULL;
  return (temp);
}
