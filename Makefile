NAME = so_long
 
MLX_PATH = inc/mlx 
LIBFT_PATH = inc/libft
PRINTF_PATH = inc/printf
GNL_PATH = inc/gnl

LIBFT_FILE	=	libft.a
MLX_FILE	=	libmlx_Linux.a
PRINTF_FILE	=	printf.a
GNL_FILE	=	gnl.a


LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))
MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))
PRINTF_LIB	=	$(addprefix $(PRINTF_PATH), $(PRINTF_FILE))
GNL_LIB	=	$(addprefix $(GNL_PATH), $(GNL_FILE))


SRCS = c_files/delete_game.c \
	c_files/error.c \
	c_files/main.c \
	c_files/movement.c \
	c_files/paste_comp.c \
	c_files/read_map.c

OBJS = $(SRCS:.c=.o)

INC = inc/mlx/libmlx_Linux.a \
	inc/libft/libft.a \
	inc/printf/libftprintf.a \
	inc/gnl/gnl.a

CC = gcc

%.o:%.CC
	$(CC)	-c $< -o $@


all	:	$(NAME)

lib:
	@echo "\033[0;33m\nCOMPILING $(LIBFT_PATH)\n"
	@make -C $(LIBFT_PATH)
	@echo "\033[1;32mLIBFT_lib created\n"

mlx:
	@echo "\033[0;33m\nCOMPILING $(MLX_PATH)...\n"
	@make -sC $(MLX_PATH)
	@echo "\033[1;32mMLX_lib created\n"


prnt:
	@echo "\033[0;33m\nCOMPILING $(PRINTF_PATH)\n"
	@make -C $(PRINTF_PATH)
	@echo "\033[1;32mPRINTF_lib created\n"

gnl:
	@echo "\033[0;33m\nCOMPILING $(GNL_PATH)...\n"
	@make -sC $(GNL_PATH)
	@echo "\033[1;32mGNL_lib created\n"

$(NAME): lib prnt mlx gnl $(OBJS)
	@$(CC) $(OBJS) $(INC) -lX11 -lXext -lm -o $(NAME)

clean:
	@echo "\033[0;31mDeleting Obj file in $(MLX_PATH)...\n"
	@make clean -sC $(MLX_PATH)
	@echo "\033[0;31mDeleting Obj file in $(LIBFT_PATH)...\n"
	@make clean -sC $(LIBFT_PATH)
	@echo "\033[0;31mDeleting Obj file in $(PRINTF_PATH)...\n"
	@make clean -sC $(PRINTF_PATH)
	@echo "\033[0;31mDeleting Obj file in $(GNL_PATH)...\n"
	@make clean -sC $(GNL_PATH)
	@echo "\033[1;32mDone\n"
	@echo "\033[0;31mDeleting So_long object...\n"
	@rm -f $(OBJS)
	@echo "\033[1;32mDone\n"

fclean: clean
	@echo "\033[0;31mDeleting so_long executable..."
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "\033[1;32mDone\n"
	
re: fclean all

.PHONY: clean fclean all re
