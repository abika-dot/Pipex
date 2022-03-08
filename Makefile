src= src/her_doc.c src/paths.c \
	src/pipes.c		src/pipex.c \
	lib/ft_putstr_fd.c lib/ft_split.c \
	lib/ft_strncmp.c get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c 

CC = gcc
FLAGS = -Wall -Werror -Wextra
HEADER = inc/pipex.h
NAME = pipex

${NAME} : ${OBJ} ${HEADER}
	@${CC} ${FLAGS} -g ${src} -o ${NAME}
clean:
	@rm -f ${OBJ}
fclean : clean
	@rm -f ${NAME}
re : fclean all

all : ${NAME}