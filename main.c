/*
** main.c for tetris in /home/vatoth/PSU_2016_tetris
**
** Made by Vatoth
** Login   <quentin.sonnefraud@epitech.eu>
**
** Started on  Fri Feb 24 17:43:20 2017 Vatoth
** Last update Sun Mar 19 17:32:54 2017 Quentin Sonnefraud
*/

#include <ncurses.h>
#include <stdio.h>
#include <term.h>
#include "tetris.h"

extern t_keys g_keys;

void	sort(char **name)
{
  int   i;
  int   y;
  char  *temp;

  i = 0;
  while (name[i])
    {
      y = i + 1;
      if (name[y])
	{
	  while (name[y])
	    {
	      if (my_strc(name[i], name[y]) == -1)
		{
		  temp = name[y];
		  name[y] = name[i];
		  name[i] = temp;
		}
	      y++;
	    }
	}
      i++;
    }
}

int	init_list(t_list *list)
{
  char	**name;

  list->first = NULL;
  list->nb = 0;
  if ((name = rep_tetri()) == NULL)
    return (1);
  sort(name);
  while (*name)
    {
      if (add_to_list(list, *name++) == -1)
	return (1);
    }
  return (0);
}

int	check_help(char **av, int ac)
{
  int	i;

  i = 0;
  if (ac > 1)
    while (av[i])
      {
	if (my_strc(av[i], "--help") == 0)
	  {
	    help(av[0]);
	    return (0);
	  }
	i++;
      }
  return (1);
}

int	check_d(char **av, int ac)
{
  int   i;

  i = 0;
  if (ac > 1)
    while (av[i])
      {
	if (my_strc(av[i], "-d") == 0 ||
	    my_strc(av[i], "--debug") == 0)
	  return (1);
	i++;
      }
  return (0);
}

int		main(int ac, char **av)
{
  t_list	list;
  int		output;

  output = 0;
  output = check_av(ac, av, &list);
  if (output != 2)
    return (output);
  if (parser_cmd(ac, av) == 1)
    {
      help(av[0]);
      return (1);
    }
  if (check_arg() == 1)
    return (1);
  ncurses_init(&list);
}
