################################################################################
# - Useful variables

NAME = so_long

CC = gcc
FLAGS = -Wall -Wextra -Werror 

################################################################################
# - Taking all *.c and *.h that are needed to compile actual source (not libs)

SUBDIRS = 
DIR_OBJ = ./obj

INCS = so_long.h

SRCS = free_memory.c game.c game_draw.c key_bindings.c \
map_draw.c map_errors.c map_field.c map_utils.c player.c \
player_draw.c so_long.c utils_000.c box.c

OS := $(shell uname)

ifeq ($(OS), Linux)
	MY_OS = 1
	FMLX = -Lmlx_Linux -lmlx_Linux -L ./minilibx -Imlx_Linux -lXext -lX11 -lm -lbsd
else
	MY_OS = 0
	FMLX = -lmlx -framework OpenGL -framework AppKit
endif

OBJS = $(addprefix $(DIR_OBJ)/, $(SRCS:c=o))
INC_DIRS = -I./ $(addprefix -I, $(SUBDIRS))

################################################################################
# - Including libs

LIBFT = libft/libft.a

LIBFT_DEPS  = libft/libft.h libft/ft_atoi.c libft/ft_lstiter.c \
libft/ft_strcmp.c libft/ft_bzero.c libft/ft_lstlast.c \
libft/ft_strdup.c libft/ft_calloc.c	libft/ft_lstmap.c libft/ft_striteri.c \
libft/ft_duplicated_x_element.c libft/ft_lstnew.c libft/ft_strjoin.c \
libft/ft_fill_i_array.c libft/ft_lstsize.c	libft/ft_strlcat.c \
libft/ft_free_cmatrix.c libft/ft_memchr.c libft/ft_strlcpy.c \
libft/ft_isalnum.c libft/ft_memcmp.c libft/ft_strlen.c\
libft/ft_isalpha.c libft/ft_memcpy.c libft/ft_strmapi.c libft/ft_isascii.c \
libft/ft_memmove.c libft/ft_strncmp.c libft/ft_isdigit.c libft/ft_memset.c \
libft/ft_strnstr.c libft/ft_isprint.c libft/ft_putchar_fd.c \
libft/ft_strrchr.c libft/ft_issign.c libft/ft_putendl_fd.c \
libft/ft_strrncmp.c libft/ft_itoa.c libft/ft_putnbr_fd.c libft/ft_strtrim.c \
libft/ft_lstadd_back.c libft/ft_putstr_fd.c libft/ft_substr.c \
libft/ft_lstadd_front.c libft/ft_split.c libft/ft_tolower.c \
libft/ft_lstclear.c libft/ft_str_is_int.c libft/ft_toupper.c \
libft/ft_lstdelone.c libft/ft_strchr.c libft/ft_printf/base.c \
libft/ft_printf/flag_utils.c libft/ft_printf/ft_printf.c \
libft/ft_printf/put_things_aside.c libft/ft_printf/printers/common_prints.c \
libft/ft_printf/printers/flag_prints.c libft/ft_printf/printers/print_c.c \
libft/ft_printf/printers/print_di.c libft/ft_printf/printers/print_p.c \
libft/ft_printf/printers/print_s.c libft/ft_printf/printers/print_t.c \
libft/ft_printf/printers/print_u.c libft/ft_printf/printers/print_x.c \
libft/ft_printf/printers/print_y.c libft/ft_printf/printers/printers.c \
libft/get_next_line/get_next_line.c \
libft/get_next_line/get_next_line_utils.c

MLX = minilibx/libmlx.a

################################################################################
################################################################################
################################################################################

################################################################################
# - Rules

all: $(LIBFT) $(MLX) $(NAME)

$(NAME): $(LIBS) $(OBJS) $(INCS)
	$(CC) $(FLAGS) $(OBJS) -D MY_OS=$(MY_OS) $(FMLX) $(LIBFT) $(MLX) -o $(NAME)

$(DIR_OBJ)/%.o: %.c 
	mkdir -p $(@D)
	$(CC) -D MY_OS=$(MY_OS) -o $@ $(FLAGS) -c $< $(INC_DIRS)

################################################################################
# - Compiling Libs

$(LIBFT): $(LIBFT_DEPS)
	@make -C libft

$(MLX):
	@make -C minilibx

################################################################################
# - Default rules

allwc: all clean

clean:
	@make clean -C libft
	@make clean -C minilibx
	@rm -rf obj
	@echo Clean $(NAME) objects

fclean:
	@make fclean -C libft
	@make clean -C minilibx
	@rm -rf obj
	@rm -rf $(NAME)
	@echo Clean $(NAME) objects and ./$(NAME)

bonus: all

re: fclean all

.PHONY: all clean fclean re
