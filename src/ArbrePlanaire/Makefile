CC = gcc
EXEC = testArbrePlanaire
CFLAGS = -std=c99 -O2
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
CPPFLAGS = -I ../../include

all : ${EXEC}

${EXEC} : depend $(OBJ)
	${CC} -o $@ ${OBJ}

.PHONY : clean
clean :
	rm edit $(OBJ)
depend : 
	$(CC) -MM $(SRC) > depends.txt

