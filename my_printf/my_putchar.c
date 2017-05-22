/*
** my_putchar.c for my_putchar in /home/Vatoth/CPool_Day07
** 
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
** 
** Started on  Wed Oct 12 08:01:01 2016 Quentin Sonnefraud
** Last update Fri Feb 24 16:37:33 2017 loto
*/

#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
