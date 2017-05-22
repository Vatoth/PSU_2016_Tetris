/*
** my_strcmp.c for strmcmp in /home/loto/Documents/semestre1/PSU/PSU_2016_minishell1
**
** Made by loto
** Login   <loto@epitech.net>
**
** Started on  Sat Jan 21 15:44:54 2017 loto
** Last update Sun Mar 19 16:09:59 2017 loto
*/

# include "commande.h"

int     my_strc(const char *s1, const char *s2)
{
  int   character;

  character = 0;
  while (s1[character] == s2[character] && s1[character] && s2[character])
    character = character + 1;
  if (s1[character] > s2[character])
    return (1);
  else if (s1[character] < s2[character])
    return (-1);
  else
    return (0);
}
