/*
** my_putstr.c for my_putstr in /home/Vatoth/CPool_Day04
** 
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
** 
** Started on  Thu Oct  6 16:03:08 2016 Quentin Sonnefraud
** Last update Fri Feb 24 16:38:26 2017 loto
*/

#include "my.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
}
