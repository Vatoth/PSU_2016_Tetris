/*
** tetris.h for tetris.h in /home/loto/Documents/semestre2/PSU/PSU_2016_tetris
**
** Made by loto
** Login   <loto@epitech.net>
**
** Started on  Fri Feb 24 17:10:48 2017 loto
** Last update Tue Mar 21 15:38:33 2017 loto
*/

#ifndef TETRIS_H_
# define TETRIS_H_

# include <ncurses.h>
# include "my.h"
# include "commande.h"

void	*my_memset(void *, int, size_t);
/*----------------------------------------------------------------------------**
**                                   structure                                **
**----------------------------------------------------------------------------*/
typedef struct          s_piece
{
  int                   width;
  int                   height;
  int                   color_code;
  char                  **star;
  char                  *name;
  int                   valid;
  int			x;
  int			y;
  struct s_piece        *next;
  struct s_piece	*last;
}                       t_piece;

typedef struct          s_list
{
  int			nb;
  struct s_piece        *first;
  struct s_piece	*last;
}                       t_list;

typedef struct          s_spec
{
  int                   height;
  int                   widht;
  int                   color_code;
}                       t_spec;

typedef struct		s_parser
{
  char			*cmd;
  char			*arg;
  int			num;
  int			call;
  struct s_parser	*next;
  struct s_parser	*prev;
}			t_parser;

typedef struct          s_list2
{
  int			check;
  int                   debug;
  int                   without_next;
  struct s_parser       *first;
  struct s_parser	*last;
}                       t_list2;

typedef struct          s_place
{
  int			i;
  int                   j;
}                       t_place;

/*------------------------------------------------------------------------------
**                            list_parser.c                                   **
------------------------------------------------------------------------------*/
char    **create_table(void);
int	fill_list(t_list2 *, char *, int);
int	my_compare(const char *, const char *, int);
char    *take_argument(char *);

/*------------------------------------------------------------------------------
**                            check_cmd.c                                     **
------------------------------------------------------------------------------*/
int	check_without_next(t_list2 *);
int	short_cmd(t_parser *, char **, int *, t_list2 *);
int	long_cmd(t_parser *, char **, int *, t_list2 *);
int	check_cmd2(t_list2 *, char **, int *, t_parser *);
int	check_cmd(t_list2 *, char **);

/*------------------------------------------------------------------------------
**                            parsing_commande.c                              **
------------------------------------------------------------------------------*/
int	check_debug(t_list2 *);
int	apply_cmd(t_list2 *);
void	free_list(t_list2 *);
int     parser_cmd(int , char **);

/*----------------------------------------------------------------------------**
**                                    check_all.c                             **
**----------------------------------------------------------------------------*/

int	check_info(t_list *, char *, t_piece *, char ***);
int	my_check_stars(char **, t_piece *, t_list *, t_spec);
int	check_size(t_spec *, t_piece *, t_list *);
int	my_check_number(char **, t_spec *, t_piece *, t_list *);
int	my_check_tab(char **, t_piece *, t_list *);
/*----------------------------------------------------------------------------**
**                               check_directory.c                            **
**----------------------------------------------------------------------------*/
char	**rep_tetri();

/*----------------------------------------------------------------------------**
**                               check_tetrimino.c                            **
**----------------------------------------------------------------------------*/

int     check_stars(char **, t_spec);
/*----------------------------------------------------------------------------**
**                              linked_list.c                                 **
**----------------------------------------------------------------------------*/

int	test_number(char *);
int	check_number(char **, t_spec *);
int	add_to_list(t_list *, char *);
void	print_list(t_list *);
/*----------------------------------------------------------------------------**
**                              read_tetrimino.c                              **
**----------------------------------------------------------------------------*/

char	*read_file(const char *);
/*----------------------------------------------------------------------------**
**                              tetris.c                                      **
**----------------------------------------------------------------------------*/

void    help(char *);
/*----------------------------------------------------------------------------**
**                              tools.c                                       **
**----------------------------------------------------------------------------*/
char	*my_strdup(char *);
int     count_tab(char **);
void    freetable(char **);
int     my_atoi(char *);

void    initialise_commande(void);
int     check_arg(void);
void    print_commande_debugmode(void);

/*----------------------------------------------------------------------------**
**                              init_ncurses.c                                **
**----------------------------------------------------------------------------*/
void	init_pair_color(void);
int	print_title();
void	animation_title(char *);
void	init_ncurses_fonc();
void	ncurses_init(t_list *);

/*----------------------------------------------------------------------------**
**                                  ncurses.c                                 **
**----------------------------------------------------------------------------*/
int	game(WINDOW *, WINDOW *, WINDOW *, t_list *);
void	game_board(WINDOW *, WINDOW *, t_list *);
char	**creat_map_board();
int	move_tetrimino(WINDOW *, t_list *, char **);

void	init_tetrimino(t_piece *, char **, WINDOW *);
void	print_window_map(char **, WINDOW *);

WINDOW	*map_score();
WINDOW	*game_map();
WINDOW	*map_next();

int	fall_tetri(t_piece *, char **, int *, int );
int	check_print_tetri(t_piece *, char **, int , int );
void	clean_tetri(t_piece *, char **, int , int );
void	print_tetri(t_piece *, char **, int , int );

/*----------------------------------------------------------------------------**
**                                next_piece.c                                **
**----------------------------------------------------------------------------*/
void	print_next_piece(t_piece *, WINDOW *);
char	**creat_score_map();
void	print_window_score(char **, WINDOW *);
void	aff_next_piece(t_piece *, char **);

int	check_av(int , char **, t_list *);
int	check_help(char **, int );
int	check_d(char **, int );
void	sort(char **);
int	init_list(t_list *);
void	liste(t_list *, int , WINDOW *);

#endif /* !TETRIS_H_ */
