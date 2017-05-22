/*
** my_strdup.c for vatoth in /home/vatoth/PSU_2016_tetris/src_commande
** 
** Made by Vatoth
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Mon Mar  6 18:19:12 2017 Vatoth
** Last update Sun Mar 19 17:38:10 2017 Quentin Sonnefraud
*/

# include "commande.h"

char	*my_strdup(char *src)
{
  char	*d;
  int	p;

  p = 0;
  if ((d = malloc(my_strlen(src) + 1)) == NULL)
    return (NULL);
  my_memset(d, '\0', my_strlen(src) + 1);
  if ((d = malloc(my_strlen(src) + 1)) == NULL)
      return (NULL);
  while (src[p] != 0)
    {
      d[p] = src[p];
      p++;
    }
  return (d);
}
