/*
** linked_list.c for tetris in /home/vatoth/PSU_2016_tetris
**
** Made by Vatoth
** Login   <quentin.sonnefraud@epitech.eu>
**
** Started on  Wed Mar  1 08:07:50 2017 Vatoth
** Last update Sun Mar 19 16:56:30 2017 Quentin Sonnefraud
*/

#include "tetris.h"
#include "my_str_to_wordtab.h"

extern t_keys	g_keys;

int     test_number(char *s)
{
  int   i;

  i = 0;
  while (s[i])
    {
      if ((s[i] < '0' || s[i] > '9') && s[i] != ' ')
	return (-1);
      i++;
    }
  return (0);
}

int     check_number(char **spec, t_spec *number)
{
  number->height = my_atoi(spec[0]);
  number->widht = my_atoi(spec[1]);
  number->color_code = my_atoi(spec[2]);
  return (0);
}

int             add_to_list(t_list *list, char *name)
{
  t_piece       *new_element;
  char		**tab;
  char		**spec;
  t_spec	number;

  ++(list->nb);
  tab = NULL;
  if ((new_element = malloc(sizeof(*new_element))) == NULL)
    return (1);
  if (check_info(list, name, new_element, &tab) == 1)
    return (0);
  if (my_check_tab(tab, new_element, list) == 1)
    return (0);
  if ((spec = my_str_to_wordtab(tab[0], ' ')) == NULL)
    return (1);
  if (my_check_number(spec, &number, new_element, list) == 1)
    {
      freetable(tab);
      return (0);
    }
  if (my_check_stars(tab, new_element, list, number) == 1)
    return (0);
  return (0);
}

void	my_puttetri(char *str, char *s)
{
  int	i;
  int	j;
  int	l;

  i = my_strlen(str);
  j = my_strlen(s);
  l = 0;
  while (l < (i - j))
    {
      write(1, &str[l], 1);
      l++;
    }
}

void		print_list(t_list *list)
{
  t_piece       *element;
  int		i;

  element = list->first;
  my_printf("Tetriminos : %i\n", list->nb);
  while (element)
    {
      my_printf("Tetriminos : Name ");
      my_puttetri(element->name, ".tetrimino");
      if (element->valid == 0)
	{
	  my_printf(" : Size %i*%i : ", element->height, element->width);
	  my_printf("Color %i :\n", element->color_code);
	  i = 0;
	  while (element->star[i])
	    {
	      my_printf("%s\n", element->star[i]);
	      i++;
	    }
	}
      else
	my_printf(" : Error\n");
      element = element->next;
    }
}
