/*
** parsing_command.c for tetris in /home/vatoth/PSU_2016_tetris
**
** Made by Vatoth
** Login   <quentin.sonnefraud@epitech.eu>
**
** Started on  Wed Mar  1 14:14:14 2017 Vatoth
** Last update Thu Mar  9 17:01:55 2017 Vatoth
*/

#include "tetris.h"

extern t_keys	g_keys;

int	check_debug(t_list2 *list)
{
  if (list->debug == 1)
    return (-1);
  g_keys.debug = 1;
  list->debug = 1;
  list->check = 1;
  return (0);
}

int	apply_cmd(t_list2 *list)
{
  t_parser	*element;

  element = list->first;
  while (element)
    {
      if (element->call != 0)
	{
	  if (recup_command(element->cmd, element->arg) == 1)
	    return (-1);
	}
      element = element->next;
    }
  return (0);
}

void	free_list(t_list2 *list)
{
  t_parser	*element;
  t_parser	*temp;

  element = list->first;
  while (element)
    {
      free(element->arg);
      free(element->cmd);
      temp = element;
      element = element->next;
      free(temp);
    }
  list->first = NULL;
  list->last = NULL;
}

int		parser_cmd(int ac, char **av)
{
  t_list2	list;
  char		**tab;
  int		num;
  int		i;

  initialise_commande();
  if (ac == 1)
    return (0);
  if ((tab = create_table()) == NULL)
    return (1);
  list.first = NULL;
  list.last = NULL;
  num = 0;
  i = 0;
  while (tab[i])
    if (fill_list(&list, tab[i++], num++) == -1)
      return (1);
  if (check_cmd(&list, av) == -1)
    return (1);
  if (apply_cmd(&list) == -1)
    return (84);
  free_list(&list);
  return (0);
}
