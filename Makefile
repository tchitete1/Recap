CC = gcc
CFLAGS = -Wall -pedantic -ansi -Werror
OBJ = main.o recap.o
EXEC = recap

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c recap.h
	$(CC) -c main.c $(CFLAGS)

recap.o : recap.c recap.h bool.h
	$(CC) -c recap.c $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJ) *.jpg