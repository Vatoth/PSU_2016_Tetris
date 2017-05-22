/*
** comande.c for commande.c in /home/loto/Documents/semestre2/PSU/PSU_2016_tetris/src
**
** Made by loto
** Login   <loto@epitech.net>
**
** Started on  Tue Feb 28 14:53:33 2017 loto
** Last update Sun Mar 19 16:09:36 2017 loto
*/

# include <stdio.h>
# include <ncurses.h>
# include "commande.h"

t_keys	g_keys;

void	initialise_commande()
{
  g_keys.keyy_left = tigetstr("kcub1");
  g_keys.keyy_right = tigetstr("kcuf1");
  g_keys.key_turn = tigetstr("kcuu1");
  g_keys.key_drop = tigetstr("kcud1");
  g_keys.key_quit = my_strdup("q");
  g_keys.key_pause = my_strdup(" ");
  g_keys.size_x = 20;
  g_keys.size_y = 10;
  g_keys.level = 1;
}

int	recup_command(char *flags, char *commande)
{
  int	i;
  int	(*foncs[8]) ();
  char	*tabs[8];

  i = 0;
  foncs[0] = &assignkl;
  foncs[1] = &assignkr;
  foncs[2] = &assignkt;
  foncs[3] = &assignkd;
  foncs[4] = &assignkq;
  foncs[5] = &assignkp;
  foncs[6] = &assignsize;
  foncs[7] = &assignl;
  if (!(tabs[0] = my_strdup("-kl")) || !(tabs[1] = my_strdup("-kr"))
      || !(tabs[2] = my_strdup("-kt")) || !(tabs[3] = my_strdup("-kd"))
      || !(tabs[4] = my_strdup("-kq")) || !(tabs[5] = my_strdup("-kp"))
      || !(tabs[6] = my_strdup("--map-size=")) || !(tabs[7] = my_strdup("-l")))
    return (-1);
  while (i != 8)
    {
      if (my_strc(flags, tabs[i]) == 0)
	foncs[i](commande);
      i++;
    }
  return (0);
}
