/*
** tools.c for tools.c in /home/vatoth/PSU_2016_tetris/src
** 
** Made by Vatoth
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Mon Feb 27 21:51:35 2017 Vatoth
** Last update Thu Mar  9 13:35:52 2017 Vatoth
*/

#include <stdlib.h>
#include "tetris.h"

char    *my_strdup(char *src)
{
  char  *dest;
  int   i;
  int   n;

  i = 0;
  n = my_strlen(src);
  if ((dest = malloc(sizeof(char) * (n + 1))) == NULL)
    return (NULL);
  while (i < n)
    {
      dest[i] = src[i];
      ++i;
    }
  dest[i] = '\0';
  return (dest);
}

int     count_tab(char **tab)
{
  int   i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}

void    freetable(char **tab)
{
  int   i;

  i = 0;
  while (tab[i])
    free(tab[i++]);
  free(tab);
}

int     my_atoi(char *str)
{
  int   res;
  int   i;

  i = 0;
  res = 0;
  while (str[i] != '\n' && str[i])
    res = res * 10 + str[i++] - '0';
  return (res);
}
