NAME 		= 	execution

SRCS 		= 	main.c \
						find_path.c

OBJS 		= 	$(SRCS:.c=.o)

CFLAGS 	= 	-W -Wall -Wextra -Iinclude

CC 			= 	gcc

RM 			= 	rm

all: 				$(NAME)

$(NAME): 		$(OBJS)
						$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
						$(RM) -f $(NAME)

fclean:			clean
						$(RM) -f $(OBJS)

re: 				fclean all
