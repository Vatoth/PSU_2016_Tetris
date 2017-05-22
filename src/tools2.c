/*
** getnextline.c for getnextline.c in /home/Vatoth/CPE_2016_getnextline
**
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
**
** Started on  Wed Jan 11 08:40:02 2017 Quentin Sonnefraud
** Last update Sat Mar 18 18:19:30 2017 Vatoth
*/

#include "tetris.h"

extern t_keys	g_keys;

int     is_num(char *s)
{
  int   i;
  int   comma;

  i = 0;
  comma = 0;
  while (s[i])
    {
      if (s[i] == ',')
	comma++;
      i++;
    }
  if (comma != 1)
    return (-1);
  i = 0;
  while (s[i])
    {
      if (s[i] < '0' && s[i] > '9')
	return (-1);
      i++;
    }
  return (0);
}

int     convert(char *str)
{
  int   res;
  int   i;

  i = 0;
  res = 0;
  while (str[i] != ',' && str[i])
    res = res * 10 + str[i++] - '0';
  return (res);
}

int     assignsize(char *commande)
{
  if (is_num(commande) == -1)
    {
      g_keys.size_x = -1;
      g_keys.size_y = -1;
    }
  else
    {
      g_keys.size_x = convert(commande);
      while (*commande != ',')
	commande++;
      commande++;
      g_keys.size_y = convert(commande);
    }
  return (0);
}

void    *my_memset(void *str, int c, size_t n)
{
  char  *d;

  d = str;
  while (n > 0)
    {
      *d++ = c;
      n = n - 1;
    }
  return (str);
}
