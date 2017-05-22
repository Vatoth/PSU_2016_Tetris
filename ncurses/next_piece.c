/*
** next_piece.c for tetris in /home/Vatoth/Epitech/PSU_2016_tetris/ncurses
**
** Made by Quentin Sonnefraud
** Login   <quentin.sonnefraud@epitech.eu>
**
** Started on  Sun Mar 19 17:48:09 2017 Quentin Sonnefraud
** Last update Wed Mar 22 10:59:34 2017 loto
*/

#include "tetris.h"

void	print_next_piece(t_piece *element, WINDOW *score)
{
  char	**map_score;

    map_score = creat_score_map();
  aff_next_piece(element, map_score);
  print_window_score(map_score, score);
}

char	**creat_score_map()
{
  char	**map;
  int	i;

  i = 0;
  if ((map = malloc(sizeof(char *) * 10)) == NULL)
    return (NULL);
  while (i < 10)
    {
      if ((map[i] = malloc(sizeof(char) * 20)) == NULL)
	return (NULL);
      map[i] = my_memset(map[i], ' ', 18);
      map[i][18] = '\0';
      i++;
  }
  map[i - 1] = NULL;
  return (map);
}

void	print_window_score(char **map_score, WINDOW *score)
{
  int	size;

  size = 1;
  while (map_score[size])
    {
      mvwprintw(score, size, 1, map_score[size]);
      size++;
    }
  wrefresh(score);
}

void	aff_next_piece(t_piece *e, char **map)
{
  int	x;
  int	y;
  int   i;
  int   j;
  int   tmp;

  x = (20 / 2) - (e->width / 2) - 1;
  y =  (10 / 2) - (e->height / 2) - 1;;
  i = 0;
  tmp = x;
  while (i < e->width)
    {
      x = tmp;
      j = 0;
      while (j < e->height)
	{
	  if (e->star[i][j] == '*')
	    map[y][x] = '*';
	  ++x;
	  ++j;
	}
      ++i;
      ++y;
    }
}

void		liste(t_list *list, int n, WINDOW *score)
{
  (void) list;
  (void) n;
  (void) score;
  /*t_piece	*element;
  int		i;

   return ;
  i = 0;
  element = list->first;
  while (i < n && i < list->nb)
    {
      if (!(element))
	element = list->first;
      element = element->next;
      i++;
    }
  element = element->next;
  print_next_piece(element, score);*/
}
