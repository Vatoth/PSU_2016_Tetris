/*
** interpret_commande.c for  in /home/loto/Documents/semestre2/PSU/PSU_2016_tetris
**
** Made by loto
** Login   <loto@epitech.net>
**
** Started on  Wed Mar  1 13:25:38 2017 loto
** Last update Sun Mar 19 17:41:18 2017 Quentin Sonnefraud
*/

#include <ncurses.h>
#include "commande.h"

extern t_keys	g_keys;

int	assignkt(char *commande)
{
  if (tigetstr(commande) == 0 || tigetstr(commande) == (char *) - 1)
    g_keys.key_turn = my_strdup(commande);
  else
    g_keys.key_turn = tigetstr(commande);
  return (0);
}

int     assignkd(char *commande)
{
  if (tigetstr(commande) == 0 || tigetstr(commande) == (char *) - 1)
    g_keys.key_drop = my_strdup(commande);
  else
    g_keys.key_drop = tigetstr(commande);
  return (0);
}

int     assignkq(char *commande)
{
  free(g_keys.key_quit);
  if (tigetstr(commande) == 0 || tigetstr(commande) == (char *) - 1)
    g_keys.key_quit = my_strdup(commande);
  else
    g_keys.key_quit = tigetstr(commande);
  return (0);
}

int     assignkp(char *commande)
{
  free(g_keys.key_pause);
  if (tigetstr(commande) == 0 || tigetstr(commande) == (char *) - 1)
    g_keys.key_pause = my_strdup(commande);
  else
    g_keys.key_pause = tigetstr(commande);
  return (0);
}

int	assignkl(char *commande)
{
  if (tigetstr(commande) == 0 || tigetstr(commande) == (char *) - 1)
    g_keys.keyy_left = my_strdup(commande);
  else
    g_keys.keyy_left = tigetstr(commande);
  return (0);
}
