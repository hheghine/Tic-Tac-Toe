NAME			= tictactoe

SRC_DIR			= src

SRCS			= $(wildcard $(SRC_DIR)/*.c)

HEADER			= $(wildcard includes/*.h )

OBJS			= ${SRCS:.c=.o}

INCS			= -I

CFLAGS			= #-Wall -Wextra -Werror

RAYLIB			= raylib/src

FMS				= -L $(RAYLIB) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# cc main.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) $(INCS)$(RAYLIB) -c $< -o $@

all:	mlx ${NAME}

mlx:
	make -C $(RAYLIB)

${NAME}: ${OBJS}
	$(CC) $(CFLAGS) $(OBJS) $(FMS) -o ${NAME}

clean:
	rm -f $(OBJS)
	make clean -C $(RAYLIB)

fclean: clean
	rm -f ${NAME}

re: 	fclean all

.PHONY: all clean fclean mlx