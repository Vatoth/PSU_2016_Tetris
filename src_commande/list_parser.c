/*
** list_parser.c for tetris in /home/vatoth/PSU_2016_tetris
** 
** Made by Vatoth
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Thu Mar  9 13:40:53 2017 Vatoth
** Last update Thu Mar  9 13:45:46 2017 Vatoth
*/

#include "tetris.h"

extern t_keys	g_keys;

char    **create_table(void)
{
  char  **tab;

  if ((tab = malloc(sizeof(char *) * 16)) == NULL)
    return (NULL);
  if ((tab[0] = my_strdup("-l")) == NULL ||
      (tab[1] = my_strdup("--level=")) == NULL ||
      (tab[2] = my_strdup("-kl")) == NULL ||
      (tab[3] = my_strdup("--key-left=")) == NULL ||
      (tab[4] = my_strdup("-kr")) == NULL ||
      (tab[5] = my_strdup("--key-right=")) == NULL ||
      (tab[6] = my_strdup("-kt")) == NULL ||
      (tab[7] = my_strdup("--key-turn=")) == NULL ||
      (tab[8] = my_strdup("-kd")) == NULL ||
      (tab[9] = my_strdup("--key-drop=")) == NULL ||
      (tab[10] = my_strdup("-kq")) == NULL ||
      (tab[11] = my_strdup("--key-quit=")) == NULL ||
      (tab[12] = my_strdup("-kp")) == NULL ||
      (tab[13] = my_strdup("--key-pause=")) == NULL ||
      (tab[14] = my_strdup("--map-size=")) == NULL)
    return (NULL);
  tab[15] = NULL;
  return (tab);
}

int             fill_list(t_list2 *list, char *av, int i)
{
  t_parser      *new_element;

  list->debug = 0;
  g_keys.debug = 0;
  g_keys.without_next = 0;
  list->without_next = 0;
  if ((new_element = malloc(sizeof(*new_element))) == NULL)
    return (-1);
  new_element->cmd = av;
  new_element->arg = NULL;
  new_element->num = i;
  new_element->call = 0;
  new_element->prev = list->last;
  new_element->next = NULL;
  if (list->last)
    list->last->next = new_element;
  else
    list->first = new_element;
  list->last = new_element;
  return (0);
}

int     my_compare(const char *s1, const char *s2, int i)
{
  while (i > 0 && *s1)
    {
      if (*s1 != *s2)
	return (*s1 - *s2);
      s1++;
      s2++;
      i--;
    }
  return (0);
}

char    *take_argument(char *cmd)
{
  int   i;
  int   j;
  int   y;
  char  *temp;

  i = 0;
  while (cmd[i] && cmd[i] != '=')
    i++;
  y = 0;
  while (cmd[i + y])
    y++;
  if ((temp = malloc(sizeof(char) * y + 1)) == NULL)
    return (NULL);
  j = 0;
  i++;
  while (cmd[i])
    temp[j++] = cmd[i++];
  temp[j] = '\0';
  if ((temp =  my_strdup(temp)) == NULL)
    return (NULL);
  return (temp);
}
