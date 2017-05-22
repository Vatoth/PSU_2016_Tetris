/*
** commande.h for tetris in /home/Vatoth/Epitech/PSU_2016_tetris
** 
** Made by Quentin Sonnefraud
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Sun Mar 19 16:46:08 2017 Quentin Sonnefraud
** Last update Sun Mar 19 16:54:20 2017 Quentin Sonnefraud
*/

#ifndef COMMANDE_H_
# define COMMANDE_H_

# include "tetris.h"

# define WAX_SIZE_KEYS 10

/*------------------------------------------------------------------------------
**                          interpret_commande.c                              **
------------------------------------------------------------------------------*/
typedef struct	s_keys
{
  char		*keyy_left;
  char		*keyy_right;
  char		*key_turn;
  char		*key_drop;
  char		*key_quit;
  char		*key_pause;
  char		*next;
  int		level;
  int		size_x;
  int		size_y;
  int		debug;
  int		without_next;
}		t_keys;

int	recup_command(char *, char *);
int	assignkd(char *);
int	assignkq(char *);
int	assignkp(char *);
int	assignkl(char *);
int	assignkt(char *);
int	assignsize(char *);
int	assignl(char * );

/*------------------------------------------------------------------------------
**                          commande.c                                        **
------------------------------------------------------------------------------*/
int	assignkr(char *);
char	*str_in_tab(int, char *, int, char **);
int	setup_term(char **);
char	*recup_term(char **);

/*------------------------------------------------------------------------------
**                          dirty.c                                           **
------------------------------------------------------------------------------*/
int	my_strc(const char *, const char *);
char	*my_strdup(char *);

/*------------------------------------------------------------------------------
**                          print_commande_debug_mode.c                       **
------------------------------------------------------------------------------*/
void	print_commande_debug_mode();

#endif /* !COMMANDE_H_ */
