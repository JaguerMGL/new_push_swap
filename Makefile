# -----------------------------------Makefile------------------------------------
NAME 	= push_swap
DEBUG 	= debug.out
# -----------------------------------Sources-------------------------------------
SRCS	= main.c \
			check_arg.c \
			check_arg_utils.c \
			general_utils.c \
			general_utils2.c \
			print.c \
			ft_split.c \
			ft_split_utils.c \
			free.c \
			init_stack.c \
			push_swap.c \
			push_swap_utils.c \
			push_swap_utils2.c \
			swap.c \
			rotate.c \
			rev_rotate.c \
			full_rot.c \
			top_rot.c \
			push.c \
			tiny_sort.c \
			little_sort.c \

CHECKER_SRCS = checker.c \
			checker_operations.c \
			check_arg.c \
			check_arg_utils.c \
			general_utils.c \
			general_utils2.c \
			print.c \
			ft_split.c \
			ft_split_utils.c \
			free.c \
			init_stack.c \
			rotate.c \
			rev_rotate.c

CHECKER_SRC = ${addprefix src/, ${CHECKER_SRCS}}
CHECKER_OBJS = ${addprefix $(OBJ_DIR)/, ${CHECKER_SRC:.c=.o}}

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

bonus: $(OBJ_DIR) checker

checker: $(CHECKER_OBJS)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) -o checker

debug: $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(FSANITIZE) $(OBJS) -o $(DEBUG)

clean:
	$(RM) -r $(OBJ_DIR)
	@echo "It's clean."

fclean: clean
	$(RM) $(NAME) $(DEBUG) checker
	@echo "It's super clean."

re: fclean all
# -----------------------------------.phony-------------------------------------
.PHONY: all clean fclean re debug bonus