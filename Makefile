# -----------------------------------Makefile------------------------------------
NAME 	= push_swap
DEBUG 	= debug.out
# -----------------------------------Sources-------------------------------------
SRCS	= free.c \
			ft_split_utils.c \
			ft_split.c \
			full_rot.c \
			init_stack_utils.c \
			init_stack.c \
			main.c \
			push_swap_utils.c \
			push_swap_utils2.c \
			push_swap.c \
			push.c \
			rev_rotate.c \
			rotate.c \
			swap.c \
			tiny_sort.c \
			top_rot.c \
			check_arg.c \
			check_arg_utils.c \
			ft_strjoin.c \
			print_error.c 
            
SRC		= ${addprefix src/, ${SRCS}}
OBJ_DIR = obj
OBJS	= ${addprefix $(OBJ_DIR)/, ${SRC:.c=.o}}
# -----------------------------------Compilation---------------------------------
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Iincludes
RM			= rm -f
FSANITIZE	= -fsanitize=address -g
# -----------------------------------Rules---------------------------------------
all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)/src

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

debug: $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(FSANITIZE) $(OBJS) -o $(DEBUG)

clean:
	$(RM) -r $(OBJ_DIR)
	@echo "It's clean."

fclean: clean
	$(RM) $(NAME) $(DEBUG)
	@echo "It's super clean."

re: fclean all
# -----------------------------------.phony-------------------------------------
.PHONY: all clean fclean re debug