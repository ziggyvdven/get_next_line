# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 13:45:36 by zvandeven         #+#    #+#              #
#    Updated: 2023/03/02 17:07:36 by zvan-de-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libftget_next_line.a
OBJS 	= $(addprefix $(BINDIR), $(SRCS:.c=.o))
CC	 	= gcc
CFLAGS 	= -Wall -Wextra -Werror -g
RM		= rm -f
BINDIR	= bin/
SRCS	= get_next_line.c get_next_line_utils.c \


all: $(NAME)

$(BINDIR)%.o: %.c
	$(CC) $(CFLAGS) -D BUFFER_SIZE=5 -c -o $@ $<

$(NAME): $(BINDIR) $(OBJS)
	ar rc $(NAME) $(OBJS)

$(BINDIR) :
	mkdir $(BINDIR)

main: $(NAME) main.c
	$(CC) $(CFLAGS) -L. -o main main.c -lftget_next_line

clean:
	$(RM) $(OBJS)
	$(RM) -r $(BINDIR)

fclean: clean
	$(RM) $(NAME) main

re: fclean all main

.PHONY:		all bonus clean fclean re