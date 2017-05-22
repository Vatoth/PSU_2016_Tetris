/*
** check_tetrimino.c for tetris in /home/vatoth/PSU_2016_tetris
** 
** Made by Vatoth
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Wed Mar  1 10:07:37 2017 Vatoth
** Last update Sun Mar 19 16:58:10 2017 Quentin Sonnefraud
*/

#include "tetris.h"

static int	check_after_star(char *str, int i)
{
  i++;
  while (str[i])
    {
      if (str[i] == '*')
	return (0);
      i++;
    }
  return (1);
}

static int	check_line(char *line, int test, int stars, int i)
{
  while (line[i])
    {
      if ((line[i] == '*' || line[i] == ' ') && test == 1)
	{
	  stars++;
	  if (check_after_star(line, i) == 1)
	    {
	      if (line[i] == ' ')
		stars--;
	      return (stars);
	    }
	}
      else if (test == 0 && line[i] == '*')
	{
	  test = 1;
	  stars++;
	}
      if (line[i] != ' ' && line[i] != '*')
	return (-1);
      i++;
    }
  return (stars);
}

int	check_stars(char **tab, t_spec number)
{
  int	i;
  int	stars;
  int	max;
  int	test;

  if (count_tab(tab) != number.widht)
    return (1);
  i = 0;
  max = 0;
  while (tab[i])
    {
      stars = 0;
      test = 0;
      if ((stars = check_line(tab[i], test, stars, test)) == -1)
	return (1);
      if (stars > max)
	max = stars;
      i++;
    }
  if (max != number.height)
    return (1);
  return (0);
}
