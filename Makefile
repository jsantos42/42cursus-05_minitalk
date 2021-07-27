CC	=		gcc

CFLAGS =	-Wall -Werror -Wextra

RM =		rm -rf

NAME_CLIENT =	client

NAME_SERVER =	server

SRCS_CLIENT =	srcs/client.c \
				srcs/errors_and_confirmation.c

SRCS_SERVER =	srcs/server.c

LIBS =			libs/libft

OBJS_CLIENT =	$(SRCS_CLIENT:.c=.o)

OBJS_SERVER =	$(SRCS_SERVER:.c=.o)

all:		$(NAME_SERVER) $(NAME_CLIENT)

bonus:		all

libft:
				$(MAKE) -C $(LIBS)

$(NAME_SERVER):		libft $(OBJS_SERVER)
					$(CC) $(CFLAGS) -o $(NAME_SERVER) $(LIBS)/libft.a $(OBJS_SERVER)

$(NAME_CLIENT):		libft $(OBJS_CLIENT)
					$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(LIBS)/libft.a $(OBJS_CLIENT)

%.c.o:		%.c
				$(CC) $(CFLAGS) -I. -c $< -o $(<:.c=.o)

clean:
				make clean -C $(LIBS)
				$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)

fclean:		clean
				make fclean -C $(LIBS)
				$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re:			fclean	all

.PHONY:		all	clean	fclean	re
