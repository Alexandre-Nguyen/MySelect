/*
** base.c for base in /home/nguye_0/rendu/PSU_2015_my_select/sources
** 
** Made by alexandre2 nguyen
** Login   <nguye_0@epitech.net>
** 
** Started on  Sun Dec 13 17:55:48 2015 alexandre2 nguyen
** Last update Sun Dec 13 20:39:26 2015 alexandre2 nguyen
*/

#include "../include/fonction.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

int	my_putchar(char c)
{
  write (1, &c, 1);
}

int	my_putstr(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
