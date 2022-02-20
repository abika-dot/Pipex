SRC = additional.c	ft_split.c	paths.c		pipes.c		pipex.c

CC = gcc
FLAGS = -Wall -Werror -Wextra 
HEADER = pipex.h
NAME = pipex

${NAME} : ${HEADER}
	@${CC}   ${SRC} -g -o ${NAME} 
clean:
	@rm -f ${NAME} 
re : clean all
all : ${NAME}




