/*
** cont_path.c for cont_path.c in /home/loto/Documents/semestre1/PSU/PSU_2016_minishell1
**
** Made by loto
** Login   <loto@epitech.net>
**
** Started on  Fri Jan 20 21:52:17 2017 loto
** Last update Sun Mar 19 17:40:22 2017 Quentin Sonnefraud
*/

# include "commande.h"

char	*str_in_tab(int n, char *str, int a, char **env)
{
  int	i;
  int	c;

  c = 0;
  i = 0;
  while (i < a)
    {
      if (env[n][i] == 'T' || env[n][i] == 'E' || env[n][i] == 'R'
	  || env[n][i] == 'M' || env[n][i] == '=')
	i++;
      else
	{
	  str[c] = env[n][i];
	  i++;
	  c++;
	}
    }
  return (str);
}

char	*recup_term(char **env)
{
  int	n;
  int	a;
  char	*str;
  int	m;

  m = 0;
  n = 0;
  while (env[m] != NULL)
    {
      if (env[m][0] == 'T' && env[m][1] == 'E' && env[m][2] == 'R')
	n = m;
      m = m + 1;
    }
  a = my_strlen(env[n]);
  if ((str = malloc(sizeof (char) * a)) == NULL)
    return (NULL);
  str = str_in_tab(n, str, a, env);
  return (str);
}
