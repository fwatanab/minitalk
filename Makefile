NAME1 = server

NAME2 = client

SRCSDIR	= src/

SRCS1	= server.c

SRCS2	= client.c

OBJS1	= $(addprefix $(SRCSDIR), $(SRCS1:.c=.o))

OBJS2	= $(addprefix $(SRCSDIR), $(SRCS2:.c=.o))

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

LIBFTDIR = libft/
LIBFTNAME = libft.a

all:$(NAME1) $(NAME2)

$(NAME1):$(OBJS1)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(CFLAGS) -o $(NAME1) $(OBJS1) -L$(LIBFTDIR) -lft

$(NAME2):$(OBJS2)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(CFLAGS) -o $(NAME2) $(OBJS2) -L$(LIBFTDIR) -lft

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

libft/$(LIBFTNAME):
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(RM) $(OBJS1) $(OBJS2)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME1) $(NAME2)
	$(MAKE) -C $(LIBFTDIR) fclean


re: fclean all
