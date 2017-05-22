/*
** check_directory.c for tetris in /home/vatoth/PSU_2016_tetris
** 
** Made by Vatoth
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Wed Mar  1 08:33:13 2017 Vatoth
** Last update Sun Mar 19 16:47:39 2017 Quentin Sonnefraud
*/

#include <dirent.h>
#include "tetris.h"

static int     check(const char *s1, const char *s2)
{
  int	i;
  int	c;

  c = 0;
  i = 0;
  while (s1[c])
    c++;
  c--;
  while (s2[i])
    i++;
  i--;
  while (s1[c] == s2[i] && s1[c] && i > 0)
    {
      i--;
      c--;
    }
  if (s1[c] == s2[i])
    return (0);
  else if (s1[c] > s2[i])
    return (1);
  else if (s1[c] < s2[i])
    return (-1);
  return (0);
}

static int             check_dir(void)
{
  DIR			*rep;
  struct dirent		*readfile;
  int			i;

  if ((rep = opendir("./tetriminos/")) == NULL)
    return (-1);
  i = 0;
  while ((readfile = readdir(rep)) != NULL)
    {
      if (check(readfile->d_name, ".tetrimino") == 0)
	i++;
    }
  closedir(rep);
  return (i);
}

char            **rep_tetri(void)
{
  DIR           *rep;
  struct dirent *r;
  int           i;
  int           y;
  char          **name;

  if ((i = check_dir()) == -1)
    return (NULL);
  if ((name = malloc(sizeof(char *) * (i + 1))) == NULL)
    return (NULL);
  rep = opendir("./tetriminos/");
  y = 0;
  while ((r = readdir(rep)) != NULL)
    {
      if (check(r->d_name, ".tetrimino") == 0)
	{
	  if ((name[y] = malloc(sizeof(char) * (my_strlen(r->d_name)))) == NULL)
	    return (NULL);
	  name[y] = r->d_name;
	  y++;
	}
    }
  name[y] = NULL;
  return (name);
}
