/*
** print_commande_debug_mode.c for print_commande in /home/loto/Documents/semestre2/PSU/PSU_2016_tetris/src commande
**
** Made by loto
** Login   <loto@epitech.net>
**
** Started on  Fri Mar  3 18:04:09 2017 loto
** Last update Sun Mar 12 15:40:46 2017 Vatoth
*/

# include "commande.h"

extern t_keys	g_keys;

int	check_arg(void)
{
  if (g_keys.keyy_left == NULL || g_keys.keyy_right == NULL ||
      g_keys.key_turn == NULL || g_keys.key_drop == NULL ||
      g_keys.key_quit == NULL || g_keys.key_pause == NULL ||
      g_keys.size_x == -1 || g_keys.size_y == -1 ||
      g_keys.level == -1)
    return (1);
  return (0);
}

void	put_debug(char *str)
{
  while (*str)
    {
      if (*str != ' ' && *str != 27)
	my_printf("%c", *str);
      else if (*str == ' ')
	my_printf("(space)");
      else if (*str == 27)
	write(1, "^E", 2);
      str++;
    }
  my_printf("\n");
}

void	print_commande_debugmode(void)
{
  my_printf("*** DEBUG MODE ***\n");
  my_printf("Key Left :\t");
  put_debug(g_keys.keyy_left);
  my_printf("Key Right :\t");
  put_debug(g_keys.keyy_right);
  my_printf("Key Turn :\t");
  put_debug(g_keys.key_turn);
  my_printf("Key drop :\t");
  put_debug(g_keys.key_drop);
  my_printf("Key Quit :\t");
  put_debug(g_keys.key_quit);
  my_printf("Key Pause :\t");
  put_debug(g_keys.key_pause);
  my_printf("Size :\t%d*%i\n", g_keys.size_x, g_keys.size_y);
  if (g_keys.without_next == 0)
    my_printf("Next : Yes\n");
  else
    my_printf("Next : No\n");
  my_printf("Level :\t%i\n", g_keys.level);
}
