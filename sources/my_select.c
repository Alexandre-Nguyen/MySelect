/*
** my_select.c for my_select in /home/nguye_0/rendu/PSU_2015_my_select/sources
** 
** Made by alexandre2 nguyen
** Login   <nguye_0@epitech.net>
** 
** Started on  Fri Dec 11 17:25:25 2015 alexandre2 nguyen
** Last update Mon Dec 14 22:27:27 2015 alexandre2 nguyen
*/

#include "../include/fonction.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

void	enter(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp->attr != 1)
    tmp = tmp->next;
  if (tmp->enter == 1)
    tmp->enter = 0;
  else
    tmp->enter = 1;
  tmp->attr = 0;
  tmp->next->attr = 1;
}

void	compare(t_list *list, int var_key)
{
  int	nbr[7];
  void	(*fonction[7])(t_list *);
  int	i;

  i = 0;
  keypad(stdscr, TRUE);
  nbr[0] = KEY_DOWN;
  nbr[1] = KEY_UP;
  nbr[2] = 32;
  nbr[3] = 263;
  nbr[4] = 10;
  nbr[5] = 330;
  fonction[0] = keydown;
  fonction[1] = keyup;
  fonction[2] = enter;
  fonction[3] = delete;
  fonction[4] = print;
  fonction[5] = delete;
  while (i < 6)
    {
      if (var_key == nbr[i])
        fonction[i](list);
      i = i + 1;
    }
  i = 0;
}

void	print(t_list *list)
{
  t_list        *tmp;

  tmp = list;
  list = list->next;
  while (list != tmp)
    {
      if (list->enter == 1)
        {
          my_putstr(list->str);
	  my_putchar(' ');
        }
      list = list->next;
    }
  my_putchar('\n');
}

int	ncurse(t_list *list)
{
  int	var_key;

  newterm(NULL, stderr, stdin);
  keypad(stdscr, TRUE);
  curs_set(FALSE);
  noecho();
  keydown(list);
  while (1)
    {
      clear();
      refresh();
      display(list);
      var_key = getch();
      compare(list, var_key);
      if (var_key == 27 || var_key == 13 || var_key == 10)
	{
	  endwin();
	  if (var_key == 10 || var_key == 13)
	    print(list);
	  return (0);
	}
    }
}

int	main(int argc, char **argv)
{
  char          *str;
  t_list        *racine;
  int           i;

  i = 1;
  racine = malloc(sizeof(t_list));
  if (racine != NULL)
    {
      racine->next = racine;
      racine->prev = racine;
      racine->str = argv[1];
      racine->attr = 1;
      racine->enter = 0;
    }
  if (argc == 1)
    return (0);
  while (i < argc)
    {
      my_put_in_list(racine, argv[i], i);
      i = i + 1;
    }
  ncurse(racine);
  return (0);
}
