NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
RM = rm -f

SRCDIR =./srcs
OBJDIR =./build

SRCS = fractol.c get_fractal_args.c argparse.c complex.c \
	   mandelbrot.c julia.c utils.c error.c init.c keys.c \
	   color.c display.c zoom.c translate.c defaults.c mandelbar.c
OBJS := $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
SRCS := $(addprefix $(SRCDIR),$(SRCS))

MLXDIR ?= ./mlx
MLX_FLAGS := -L$(MLXDIR)/lib -lmlx -lXext -lX11 -lm

LIBFTDIR ?= ./libft
LIBFT := $(LIBFTDIR)/lib/libft.a
LIBFT_FLAGS := -L$(LIBFTDIR)/lib -lft

INCLUDES := -I./include -I$(LIBFTDIR)/include -I$(MLXDIR)/include

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) $< -c -o $@

$(LIBFT):
	make -C $(LIBFTDIR)

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	make fclean -C $(LIBFTDIR)
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
