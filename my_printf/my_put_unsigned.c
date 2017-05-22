/*
** my_put_unsigned.c for my_put_unsigned.c in /home/Vatoth/PSU_2016_my_printf
**
** Made by Quentin Sonnefraud
** Login   <Vatoth@epitech.net>
**
** Started on  Thu Nov 17 12:06:37 2016 Quentin Sonnefraud
** Last update Fri Feb 24 16:38:34 2017 loto
*/

#include "my.h"

int     my_put_unsigned(unsigned int nb)
{
  int   modulo;

  if (nb > 0)
    {
      if (nb > 9)
	{
	  modulo = nb % 10;
	  nb = (nb - modulo) / 10;
	  my_put_nbr(nb);
	  my_putchar(48 + modulo);
	}
      else
	{
	  my_putchar(nb + 48);
	}
    }
  return (0);
}
