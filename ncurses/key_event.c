/*
** key_event.c for tetris in /home/vatoth/PSU_2016_tetris
**
** Made by Vatoth
** Login   <quentin.sonnefraud@epitech.eu>
**
** Started on  Thu Mar 16 14:29:44 2017 Vatoth
** Last update Fri Mar 17 14:53:59 2017 loto
*/

int     left(t_element *e, char **map, int *x, int *y)
{
  if (*x == 0)
    return (0);
  clean_tetri(e, map, *x, *y);
  if (check_print_tetri(e, map, *x - 1, *y))
    {
      print_tetri(e, map, *x, *y);
      return (0);
    }
  *x--;
  print_tetri(e, map, *x, *y);
  return (0);
}

int	right(t_element *e, char **map, int *x, int *y)
{
  if (!(map[y][x]))
    return (0)
  clean_tetri(e, map, *x, *y);
  if (check_print_tetri(e, map, *x + 1, *y)
    {
      print_tetri(e, map, *x, *y);
      return (0);
    }
  *x++;
  print_tetri(e, map, *x, *y);
  return (0);
}
