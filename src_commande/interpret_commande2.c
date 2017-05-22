/*
** interpret_commande2.c for tetris in /home/vatoth/PSU_2016_tetris/src_commande
** 
** Made by Vatoth
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Sat Mar 18 18:27:38 2017 Vatoth
** Last update Sun Mar 19 17:36:59 2017 Quentin Sonnefraud
*/

#include <ncurses.h>
#include "commande.h"

int     test_num(char *s)
{
  int    i;

  i = 0;
  while (s[i])
    {
      if (s[i] < '0' || s[i] > '9')
	return (-1);
      i++;
    }
  return (0);
}

extern t_keys	g_keys;

int	assignl(char *commande)
{
  if (test_num(commande) == -1)
    {
      g_keys.level = -1;
      return (1);
    }
  g_keys.level = my_atoi(commande);
  return (0);
}

int	assignkr(char *commande)
{
  if (tigetstr(commande) == 0 || tigetstr(commande) == (char *) - 1)
    g_keys.keyy_right = my_strdup(commande);
  else
    g_keys.keyy_right = tigetstr(commande);
  return (0);
}
