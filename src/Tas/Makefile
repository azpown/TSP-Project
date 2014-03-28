CC = gcc
EXEC = testTas
CFLAGS = -std=c99 -O2
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
CPPFLAGS = -I ../../include

all : ${EXEC}

${EXEC} : depend $(OBJ)
	${CC} -o $@ ${OBJ} 

.PHONY : clean
clean :
	rm $(OBJ)
depend : 
	$(CC) -MM $(SRC) > depends.txt

