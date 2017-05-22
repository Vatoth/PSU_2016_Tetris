/*
** check_all.c for tetris in /home/vatoth/PSU_2016_tetris/src
** 
** Made by Vatoth
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Thu Mar  9 13:24:37 2017 Vatoth
** Last update Sun Mar 19 16:56:13 2017 Quentin Sonnefraud
*/

#include "tetris.h"
#include "my_str_to_wordtab.h"

extern t_keys	g_keys;

int     check_info(t_list *list, char *name, t_piece *n, char ***tab)
{
  char  *info;

  n->name = name;
  if ((info = read_file(name)) == NULL)
    {
      n->next = list->first;
      n->valid = 1;
      list->first = n;
      return (1);
    }
  if ((*tab = my_str_to_wordtab(info, '\n')) == NULL)
    return (1);
  return (0);
}

int     my_check_stars(char **tab, t_piece *n, t_list *list, t_spec number)
{
  if (check_stars(&tab[1], number) == 1)
    {
      freetable(tab);
      n->next = list->first;
      n->valid = 1;
      list->first = n;
      return (1);
    }
  n->star = &tab[1];
  n->next = list->first;
  n->valid = 0;
  list->first = n;
  return (0);
}

int     check_size(t_spec *number, t_piece *n, t_list *list)
{
  if (g_keys.size_y < number->widht || g_keys.size_x < number->height)
    {
      n->next = list->first;
      n->valid = 1;
      list->first = n;
      return (1);
    }
  n->width = number->widht;
  n->height = number->height;
  n->color_code = number->color_code;
  return (0);
}

int     my_check_number(char **spec, t_spec *number, t_piece *n, t_list *list)
{
  if (count_tab(spec) != 3)
    {
      freetable(spec);
      n->next = list->first;
      n->valid = 1;
      list->first = n;
      return (1);
    }
  if (check_number(spec, number) == 1)
    {
      freetable(spec);
      n->next = list->first;
      n->valid = 1;
      list->first = n;
      return (1);
    }
  freetable(spec);
  if (check_size(number, n, list) == 1)
    return (1);
  return (0);
}

int     my_check_tab(char **tab, t_piece *new_element, t_list *list)
{
  if (count_tab(tab) < 2)
    {
      freetable(tab);
      new_element->next = list->first;
      new_element->valid = 1;
      list->first = new_element;
      return (1);
    }
  if (test_number(tab[0]) == -1)
    {
      freetable(tab);
      new_element->next = list->first;
      new_element->valid = 1;
      list->first = new_element;
      return (1);
    }
  return (0);
}
