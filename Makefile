CFLAGS = -Wall -Wextra -Werror
NAME = pipex

MAIN = main.c

SRC_DIR = src
LIB_DIR = lib
GNL_DIR = get_next_line
INC_DIR = inc
OBJ_DIR = obj

HEADERS = $(INC_DIR)/pipex.h

SRC = $(SRC_DIR)/check_args.c $(SRC_DIR)/here_doc.c $(SRC_DIR)/paths.c \
	$(SRC_DIR)/pipes.c $(SRC_DIR)/pipex.c $(LIB_DIR)/ft_putstr_fd.c $(LIB_DIR)/ft_strncmp.c \
	$(LIB_DIR)/ft_split.c $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c 

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS) $(MAIN)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(MAIN) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_DIR)/%.o: $(LIB_DIR)/%.c
	mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c
	mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj
fclean: clean
	rm $(NAME)
re: fclean all