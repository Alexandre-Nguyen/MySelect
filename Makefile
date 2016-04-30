##
## Makefile for makefile in /home/nguye_0/rendu/PSU_2015_my_select
##
## Made by alexandre2 nguyen
## Login   <nguye_0@epitech.net>
##
## Started on  Wed Dec  2 14:46:52 2015 alexandre2 nguyen
## Last update Sun Dec 13 18:51:22 2015 alexandre2 nguyen
##

CC	= gcc

RM	= rm -f

NAME	= my_select

SRCS	= sources/my_select2.c \
	  sources/base.c \
	  sources/list.c \
	  sources/my_select.c  \

OBJS	= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) -lncurses

all: $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(OBJS)

re: fclean all
