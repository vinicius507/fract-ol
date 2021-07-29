NAME = fractol
CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

INCLUDESDIR=./includes ./libft/includes ./mlx
INCLUDES := $(addprefix -I,$(INCLUDESDIR))
SRCDIR =./src
OBJDIR =./build

SRCS = fractol.c argparse.c complex.c mandelbrot.c \
	   julia.c utils.c error.c init.c keys.c
OBJS := $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
SRCS := $(addprefix $(SRCDIR),$(SRCS))

MLXDIR = ./mlx
MLX = $(MLXDIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLXDIR) -lmlx_Linux -lXext -lX11 -lm

LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a
LIBFT_FLAGS = -L$(LIBFTDIR) -lft

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -c -o $@

$(MLX):
	make -C $(MLXDIR)

$(LIBFT):
	make -C $(LIBFTDIR)

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	make fclean -C $(LIBFTDIR)
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
