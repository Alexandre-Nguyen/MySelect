/*
** my_select2.c for my_select2 in /home/nguye_0/rendu/PSU_2015_my_select/sources
** 
** Made by alexandre2 nguyen
** Login   <nguye_0@epitech.net>
** 
** Started on  Sun Dec 13 18:03:06 2015 alexandre2 nguyen
** Last update Sun Dec 13 20:41:19 2015 alexandre2 nguyen
*/

#include "../include/fonction.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

int	display_first_condition(t_list *list)
{
  if (list->enter == 1)
    {
      attron(A_REVERSE);
      attron(A_UNDERLINE);
      printw(list->str);
      attroff(A_REVERSE);
      attroff(A_UNDERLINE);
    }
  else
    {
      attron(A_UNDERLINE);
      printw(list->str);
      attroff(A_UNDERLINE);
    }
}

int	display(t_list *list)
{
  t_list        *tmp;

  tmp = list;
  list = list->next;
  while (list != tmp)
    {
      if (list->attr == 1)
	display_first_condition(list);
      else if (list->enter == 1)
        {
          attron(A_REVERSE);
          printw(list->str);
          attroff(A_REVERSE);
        }
      else
	printw(list->str);
      printw("\n");
      list = list->next;
    }
}

void	delete(t_list *list)
{
  t_list        *tmp;

  tmp = list;
  tmp = tmp->next;
  while (tmp->attr != 1)
    {
      tmp = tmp->next;
    }
  tmp->prev->next = tmp->next;
  tmp->next->prev = tmp->prev;
  tmp->next->attr = 1;
  free(tmp);
}

void	keydown(t_list *list)
{
  t_list        *tmp;
  t_list        *tmp2;

  tmp = list;
  tmp2 = tmp;
  tmp = tmp->next;
  while (tmp->attr != 1)
    tmp = tmp->next;
  if (tmp->next == tmp2)
    {
      tmp->attr = 0;
      tmp->next->next->attr = 1;
    }
  else
    {
      tmp->next->attr = 1;
      tmp->attr = 0;
    }
}

void	keyup(t_list *list)
{
  t_list        *tmp;
  t_list        *tmp2;

  tmp = list;
  tmp = tmp->next;
  tmp2 = tmp->prev;
  while (tmp->attr != 1)
    tmp = tmp->prev;
  if (tmp->prev == tmp2)
    {
      tmp->attr = 0;
      tmp->prev->prev->attr = 1;
    }
  else
    {
      tmp->prev->attr = 1;
      tmp->attr = 0;
    }
}
