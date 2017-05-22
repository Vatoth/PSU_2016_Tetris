/*
** check_av.c for tetris in /home/Vatoth/Epitech/PSU_2016_tetris/src_commande
** 
** Made by Quentin Sonnefraud
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Sun Mar 19 17:42:04 2017 Quentin Sonnefraud
** Last update Sun Mar 19 17:42:10 2017 Quentin Sonnefraud
*/

#include <term.h>
#include "tetris.h"

int	check_av(int ac, char **av, t_list *list)
{
  setupterm(NULL, 1, (int *)0);
  if (check_help(av, ac) == 0)
    return (0);
  initialise_commande();
  if (init_list(list) == 1)
    return (1);
  if (check_d(av, ac) == 1)
    {
      if (parser_cmd(ac, av) == 1 || (check_arg() == 1))
	return (1);
      print_commande_debugmode();
      print_list(list);
      my_printf("Press any key to start Tetris\n");
      ncurses_init(list);
      return (0);
    }
  return (2);
}
