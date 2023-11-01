# Normbre del ejecutable
NAME = libftprintf.a
EXECUTABLE = test.out

# Colores
NC = \033[0m
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m

# Directorios
SRC_DIR = srcs/mandatory/
SRC_DIR_BONUS = srcs/bonus/
OBJ_DIR = objs/
OBJF = objs
INC = incs

# Ficheros
SRC_FILES = ft_printf ft_printf_utils ft_print_unsigned ft_print_ptr
SRC_FILES_BONUS = ft_printf_bonus ft_printf_utils_bonus ft_flags_bonus

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

SRC_BONUS = $(addprefix $(SRC_DIR_BONUS), $(addsuffix .c, $(SRC_FILES_BONUS)))
OBJ_BONUS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES_BONUS)))

# Comandos
CC = gcc
CFLAGS = -Wall -Werror -Wextra $(if $(DEBUG),-fsanitize=address,)
RM = rm -f
AR = ar rcs

# REGLAS #

.SILENT:

all: $(NAME)

$(NAME): $(OBJ) libft clean_bonus
	$(AR) $(NAME) $(OBJ)
	echo "$(GREEN)libftprintf compiled!$(NC)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	printf "$(BLUE)Compiling: $< $(NC)"
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@
	echo "$(GREEN) Done! $(NC)"

bonus: $(OBJ_BONUS) libft clean_mandatory
	$(AR) $(NAME) $(OBJ_BONUS)
	echo "$(GREEN)libftprintf bonus compiled!$(NC)"

$(OBJ_DIR)%.o: $(SRC_DIR_BONUS)%.c | $(OBJF)
	printf "$(BLUE)Compiling: $< $(NC)"
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@
	echo "$(GREEN) Done! $(NC)"

$(OBJF):
	mkdir -p $(OBJ_DIR)

libft:
	echo "$(PURPLE)Compiling libft...$(NC)"
	make -C ./libft
	cp libft/libft.a $(NAME)
	echo "$(GREEN)Libft compiled!$(NC)"

test:
	echo "$(PURPLE)Compiling and executing test...$(NC)"
	$(CC) $(CFLAGS) -I $(INC) main.c $(NAME) -o $(EXECUTABLE)
	./$(EXECUTABLE)

clean_mandatory:
	if [ -e "$(OBJ_DIR)ft_printf.o" ]; then \
		$(RM) $(OBJ); \
		echo "$(YELLOW)Objects from mandatory part cleaned! $(NC)"; \
	fi

clean_bonus:
	if [ -e "$(OBJ_DIR)ft_printf_bonus.o" ]; then \
		$(RM) $(OBJ_BONUS); \
		echo "$(YELLOW)Objects from bonus part cleaned! $(NC)"; \
	fi

clean: clean_mandatory clean_bonus
	make clean -C ./libft
	$(RM) -r $(OBJ_DIR)
	echo "$(YELLOW)Objects from libft cleaned! $(NC)"
	echo "$(RED)All objects cleaned! $(NC)"

fclean: clean
	make fclean -C ./libft
	$(RM) $(NAME) $(EXECUTABLE)
	echo "$(RED)Executable cleaned! $(NC)"

re: fclean all

norm:
	norminette $(SRC) $(SRC_BONUS) $(INC)

.PHONY: all bonus libft test clean_mandatory clean_bonus clean fclean re
