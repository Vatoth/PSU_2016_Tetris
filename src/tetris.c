/*
** tetris.c for tetris in /home/vatoth/PSU_2016_tetris
** 
** Made by Vatoth
** Login   <quentin.sonnefraud@epitech.eu>
** 
** Started on  Fri Feb 24 15:45:16 2017 Vatoth
** Last update Wed Mar  8 16:26:34 2017 Vatoth
*/

#include "../include/tetris.h"

void	help(char *s)
{
  my_printf("Usage: %s [options]\n", s);
  my_printf("Options:\n");
  my_printf("  --help                Display this help\n");
  my_printf("  -l --level={num}      Start Tetris at level num (def: 1)\n");
  my_printf("  -kl --key-left={K}    ");
  my_printf("Move the tetrimino LEFT using the K key (def: left arrow)\n");
  my_printf("  -kr --key-right={K}   ");
  my_printf("'Move the tetrimino RIGHT using the K key (def: right arrow)\n");
  my_printf("  -kt --key-turn={K}    ");
  my_printf("TURN the tetrimino clockwise ");
  my_printf("90d using the K key (def: top arrow)\n");
  my_printf("  -kd --key-drop={K}    ");
  my_printf("DROP the tetrimino using the K key (def: down arrow)\n");
  my_printf("  -kq --key-quit={K}    ");
  my_printf("QUIT the game using the K key (def: ’Q’ key)\n");
  my_printf("  -kp --key-pause={K}   ");
  my_printf("PAUSE/RESTART the game using the K key (def: space bar)\n");
  my_printf("  --map-size={row,col}  ");
  my_printf("Set the numbers of rows and columns of the map (def: 20,10)\n");
  my_printf("  -w --without-next     Hide next tetrimino (def: false)\n");
  my_printf("  -d --debug            Debug mode (def: false)\n");
}
