/*
** list.c for list in /home/nguye_0/rendu/PSU_2015_my_select/sources
** 
** Made by alexandre2 nguyen
** Login   <nguye_0@epitech.net>
** 
** Started on  Thu Dec  3 09:45:44 2015 alexandre2 nguyen
** Last update Sun Dec 13 20:39:38 2015 alexandre2 nguyen
*/

#include "../include/fonction.h"
#include <stdlib.h>
#include <ncurses.h>

char	my_put_in_list(t_list *list, char *elem, int pos)
{
  t_list	*newlist;

  newlist = malloc(sizeof(t_list));
  if (newlist == NULL)
    return (0);
  if (newlist != NULL)
    {
      newlist->str = elem;
      newlist->attr = 0;
      newlist->enter = 0;
      newlist->next = list;
      newlist->prev = list->prev;
      list->prev = newlist;
      newlist->prev->next = newlist;
    }
}

char	my_show_list(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  list = list->next;
  while (list != tmp)
    {
      attron(A_UNDERLINE);
      printw(list->str);
      printw("\n");
      list = list->next;
    }
}
