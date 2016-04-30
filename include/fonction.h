/*
** fonction.h for fonction in /home/nguye_0/rendu/PSU_2015_my_select/include
** 
** Made by alexandre2 nguyen
** Login   <nguye_0@epitech.net>
** 
** Started on  Thu Dec  3 09:39:48 2015 alexandre2 nguyen
** Last update Sun Dec 13 20:33:12 2015 alexandre2 nguyen
*/

#ifndef FONCTION_H_
# define FONCTION_H_

typedef struct		s_list
{
  char	*str;
  int	attr;
  int	x;
  int	enter;
  struct s_list	*next;
  struct s_list *prev;
}			t_list;

int	my_putchar(char c);
int	my_putstr(char *str);
int	display_first_condition(t_list *list);
void	delete(t_list *list);
void	enter(t_list *list);
void	compare(t_list *list, int var_key);
int	ncurse(t_list *list);
int	display(t_list *list);
void	keydown(t_list *list);
void	keyup(t_list *list);
void	print(t_list *list);

#endif
