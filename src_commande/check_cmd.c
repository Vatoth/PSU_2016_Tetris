/*
** check_cmd.c for tetris in /home/vatoth/PSU_2016_tetris/src_commande
**
** Made by Vatoth
** Login   <quentin.sonnefraud@epitech.eu>
**
** Started on  Thu Mar  9 13:37:11 2017 Vatoth
** Last update Sun Mar 19 16:09:15 2017 loto
*/

#include "tetris.h"

extern t_keys	g_keys;

int     check_without_next(t_list2 *list)
{
  if (list->without_next == 1)
    return (-1);
  list->without_next = 1;
  g_keys.without_next = 1;
  list->check = 1;
  return (0);
}

int     short_cmd(t_parser *element, char **av, int *i, t_list2 *list)
{
  if (element->call != 0)
    return (-1);
  *i = *i + 1;
  if (av[*i] != NULL)
    {
      if ((element->arg = my_strdup(av[*i])) == NULL)
	return (-1);
      (element->call)++;
      list->check = 1;
    }
  else
    return (-1);
  return (0);
}

int     long_cmd(t_parser *element, char **av, int *i, t_list2 *list)
{
  if (my_compare(element->cmd, "--map-size=", my_strlen(element->cmd)) != 0)
    element = element->prev;
  if (my_strlen(av[*i]) <= my_strlen(element->cmd))
    return (-1);
  if (element == NULL || element->call != 0)
    return (-1);
  if ((element->arg = take_argument(av[*i])) == NULL)
    return (-1);
  (element->call)++;
  list->check = 1;
  if (my_compare(element->cmd, "--map-size=", my_strlen(element->cmd)) != 0)
    element = element->next;
  return (0);
}

int     check_cmd2(t_list2 *list, char **av, int *i, t_parser *element)
{
  if (my_strc(av[*i], "-d") == 0 || my_strc(av[*i], "--debug") == 0)
    {
      if ((check_debug(list)) == -1)
	return (-1);
      return (1);
    }
  else if (my_strc(av[*i], "-w") == 0 || my_strc(av[*i], "--without-next") == 0)
    {
      if (check_without_next(list) == -1)
	return (-1);
      return (1);
    }
  else if ((my_strc(av[*i], element->cmd)) == 0)
    {
      if (short_cmd(element, av, i, list) == -1)
	return (-1);
      return (1);
    }
  else if (my_compare(av[*i], element->cmd, my_strlen(element->cmd)) == 0)
    {
      if (long_cmd(element, av, i, list) == -1)
	return (-1);
      return (1);
    }
  return (0);
}

int             check_cmd(t_list2 *list, char **av)
{
  t_parser      *element;
  int           i;
  int           output;

  i = 1;
  while (av[i] != NULL)
    {
      element = list->first;
      list->check = 0;
      output = 0;
      while (element)
	{
	  output = check_cmd2(list, av, &i, element);
	  if (output == -1)
	    return (-1);
	  if (output == 1)
	    break;
	  element = element->next;
	}
      if (list->check == 0)
	return (-1);
      i++;
    }
  return (0);
}
