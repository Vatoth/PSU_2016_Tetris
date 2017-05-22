/*
** read_tetrimino.c for tetris in /home/vatoth/PSU_2016_tetris
** 
** Made by Vatoth
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Wed Mar  1 08:42:54 2017 Vatoth
** Last update Sun Mar 19 17:13:47 2017 Quentin Sonnefraud
*/

#include <fcntl.h>
#include <sys/stat.h>
#include "tetris.h"

static char     *the_path(const char *d, const char *s)
{
  char          *path;
  int           i;
  int           a;

  i = 0;
  a = 0;
  if ((path = malloc(sizeof(char) * my_strlen(d) + my_strlen(s) + 1)) == NULL)
    return (NULL);
  while (d[i])
    path[a++] = d[i++];
  i = 0;
  while (s[i])
    path[a++] = s[i++];
  path[a] = '\0';
  return (path);
}

char            *read_file(const char *name)
{
  struct stat   status;
  char          *path;
  char          *buffer;
  int           fd;

  path = the_path("tetriminos/", name);
  if ((fd = open(path, O_RDONLY)) == -1)
    return (NULL);
  stat(path, &status);
  if (status.st_size > 9999999999)
    return (NULL);
  free(path);
  if ((buffer = malloc(sizeof(char) * (status.st_size + 1))) == NULL)
    return (NULL);
  buffer[status.st_size] = '\0';
  read(fd, buffer, status.st_size);
  return (buffer);
}
